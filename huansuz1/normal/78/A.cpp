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

char a[12345],b[12345],c[12345];
string s="aeiou";
int x,y,z;

int main() {
	gets(a);
	gets(b);
	gets(c);
	for (int i=0; i<strlen(a); i++)
		for (int j=0; j<s.length(); j++)
			if (s[j]==a[i]) {x++; break;}

	for (int i=0; i<strlen(b); i++)
		for (int j=0; j<s.length(); j++)
			if (s[j]==b[i]) {y++; break;}

	for (int i=0; i<strlen(c); i++)
		for (int j=0; j<s.length(); j++)
			if (s[j]==c[i]) {z++; break;}
	if (x==5 && y==7 && z==5) cout<<"YES"; else cout<<"NO";

    return 0;
}