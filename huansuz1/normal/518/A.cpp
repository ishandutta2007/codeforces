#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;

string s,l,t="abcdefghijklmnopqrstuvwxyz";
int k;

int main(){
cin>>s>>l;
if (s==l) {cout<<"No such string"; exit(0);}
for (int i=0; i<26; i++)
	if (t[i]==s[s.length()-1]) k=i;
for (int i=s.length()-1; i>=0; i--) {
	
	for (int j=0; j<26; j++) 
		if (t[j]==s[i]) k=j;
	if (k==25) s[i]='a'; else {s[i]=t[k+1]; break;}      
		
}

if (s==l) {cout<<"No such string"; exit(0);}
cout<<s;

}