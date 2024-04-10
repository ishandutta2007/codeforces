#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <map>

using namespace std;

long long a[100009],n,m,z,p,k;
string s,l="abcdefghijklmnopqrstuvwxyz";
char b[1234567];

int main() {
	cin>>k>>s;
	for (int i=0; i< s.length(); i++) 
		a[s[i]-'a']++;
	s="";
	for (int i=0; i<26; i++)
		if (a[i]%k==0) {
			for (int j=1; j<=a[i]/k; j++)
				s+=l[i];
		} else{ p=1; break; }
		if (p==1) cout<<-1; else {
		for (int i=0; i<k; i++)
			cout<<s;
		}
	
	return 0;
}