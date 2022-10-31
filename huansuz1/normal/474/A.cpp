#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
string s,l="/qwertyuiopasdfghjkl;zxcvbnm,./q";
char x;
int main(){
     
	cin>>x;
	cin>>s;

	if (x=='R') {
		for (int i=0; i<s.length(); i++)
			for (int j=1; j<l.length(); j++)
				if (s[i]==l[j]) {cout<<l[j-1]; break;}
	
	} else {
		for (int i=0; i<s.length(); i++)
			for (int j=0; j<l.length(); j++)
				if (s[i]==l[j]) {cout<<l[j+1]; break;}
	}

	
	
	
	return 0;
}