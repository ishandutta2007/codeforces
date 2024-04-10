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

int z=0;
string s,l;

int main() {
     cin>>s;
     if (s.length()<3) cout<<s; else {
     for (int i=0; i<s.length()-2; i++) {
     	l="";
		for (int j=i; j<i+3; j++)  
			l+=s[j];
		if (l=="WUB")	{s[i]='0'; s[i+1]='0'; s[i+2]='0'; }

	}
	l="";
     if (s[0]!='0')  l+=s[0];
     for (int i=1; i<s.length(); i++){
          if (s[i]!='0' && s[i-1]=='0') l+=' ';
     	if (s[i]!='0') l+=s[i];     
     	}
     if (l[0]!=' ') cout<<l[0];
     for (int i=1; i<l.length(); i++)
	     cout<<l[i];                 }

     return 0;
}