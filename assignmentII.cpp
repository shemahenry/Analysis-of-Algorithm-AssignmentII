#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <set>
using namespace std;


const int ALPHA_LENGTH = 26;


void getWords(string &word1, string &word2);
void printWordLadder(string word1, string word2);


int main() {
    
  string word1, word2;
  getWords(word1, word2); 
  printWordLadder(word1, word2);
    
  return 0;
}



void getWords(string &word1, string &word2) {
  while (true) {
    cout << "Please enter a word: ";
    cin>>word1;
    
    cout << "Please enter another word of the same length: ";
    cin>>word2;
    
    if (word1.length() == word2.length()) {
      break;
    }
    cout << "Please enter two words with the same length." << endl;
  }
}




void printWordLadder(string word1, string word2){
    
   
    queue<stack<string> > myQueue;
    
   
    stack<string> wordladder;
    
   
    stack<string> myStack;
    myStack.push(word1);
    myQueue.push(myStack);
    
    string token;
    ifstream dictionary("dictionary.txt");
    set<string> myDictionary;
    set<string> testedWords;
    
    if(dictionary.is_open()) {
      
	      while (dictionary >> token) {
	    	myDictionary.insert(token);
	      }
	      
	      
	      while (!(myQueue.empty())) {
	        
	        
			stack<string> ladder = myQueue.front();
			myQueue.pop();
			string word = ladder.top();
		   
			if (word == word2) {
			
			  
			  cout << "The ladder from " << word1 << " to " << word2 << " is \n";
			 
			  
			  while(!ladder.empty()){
			  	wordladder.push(ladder.top());
			  	ladder.pop();
			  }
			  while(!wordladder.empty()){
			  	cout<<wordladder.top()<<" > ";
			  	wordladder.pop();
			  }
		} 
		else {
			  
			  string test;
			  for (int i = 0; i < word.size(); i++) {
			    for (char j = 'a'; j <= 'z'; j++) {
			    test = word.substr(0, i) + j + word.substr(i + 1);
		            
			    if (myDictionary.count(test)) {
			      
			      if (!testedWords.count(test)) {
				
						stack<string> copy = ladder;
				                
						copy.push(test);
				                
						myQueue.push(copy);
			      }
			    }
		            
			    testedWords.insert(test);
			}
		}
	      }
	    }
    } else {
      cout << "Couldn't open the dictionary" << endl;
    }
    
    
}
