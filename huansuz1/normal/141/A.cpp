#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <string>

using namespace std;

int p=0;
string s,l,t;

int main() {
     cin>>s>>l>>t;
     for (int i=0; i<s.length(); i++)
	     for (int j=0; j<t.length(); j++)
	     	if (s[i]== t[j]) { s[i]='0'; t[j]='0'; break; }
	for (int i=0; i<l.length(); i++)
		for (int j=0; j<t.length(); j++)
		    	if (l[i]== t[j]) { l[i]='0'; t[j]='0'; break; }

	s+=l;
	for (int i=0; i<s.length(); i++)
		if (s[i]!='0') {p=1; break; } 
	for (int j=0; j<t.length(); j++)
		if (t[j]!='0') { p=1; break; } 
	
	
	if (p==0)cout<<"YES"; else cout<<"NO";

     
     return 0;
}