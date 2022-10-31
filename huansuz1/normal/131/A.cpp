#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
   
int main(){
	int z=0;
	string s;
	cin>>s;
	if (s.length() == 1 && s[0] >= 'a' && s[0] <= 'z') {s[0] = s[0] - 'a' + 'A'; cout <<s; } 
	 else {
	for (int i=0; i<s.length(); i++)
		if (s[i] >= 'A' && s[i] <= 'Z')  z++;
	
	if ((s[0] >= 'a' && s[0] <= 'z' && z == s.length() - 1)) {
		if (s[0] >= 'a' && s[0] <= 'z') s[0] = s[0] - 'a' + 'A'; 
		for (int i=1; i<s.length(); i++)
			if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a'; 
		} else 
	if (z == s.length()) {
		
		for (int i=0; i<s.length(); i++)
			if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a'; 
		
			  } 
			  cout<<s; 
    }
			return 0;          
}