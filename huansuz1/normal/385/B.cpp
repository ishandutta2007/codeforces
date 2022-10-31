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

string s;
long long n,z;

int main() {
	cin>>s;
	if (s.length()<4) cout<<0; else {
		for (int i=0; i<s.length()-3; i++)
			if (s[i]=='b'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='r' ) {n+=(i+1-z)* (s.length()-(i+3));  z=i+1;}
		cout<<n;            }
	
	
	return 0;
}