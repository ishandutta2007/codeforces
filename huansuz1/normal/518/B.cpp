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

string s,l;
int x,y,a[123],b[123],c[123],d[123];

int main(){
cin>>s>>l;
for (int i=0; i<l.length(); i++)
	if (l[i]>='a' && l[i]<='z') a[l[i]-'a']++; else b[l[i]-'A']++;
for (int i=0; i<s.length(); i++)
	if (s[i]>='a' && s[i]<='z' && a[s[i]-'a']>0) {x++; a[s[i]-'a']--;s[i]=' ';} else  
		if (s[i]>='A' && s[i]<='Z' && b[s[i]-'A']>0) {x++; b[s[i]-'A']--;s[i]=' ';} 

for (int i=0; i<s.length(); i++)
    if (s[i]>='a' && s[i]<='z' && b[s[i]-'a']>0 && s[i]!=' ') {y++; b[s[i]-'a']--;} else
		if (s[i]>='A' && s[i]<='Z' && a[s[i]-'A']>0 && s[i]!=' ') {y++; a[s[i]-'A']--;} 

cout<<x<<" "<<y;

}