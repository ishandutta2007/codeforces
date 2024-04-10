#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n,m,p;
string x,s,l[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon" , "sylveon"};

int main(){
	cin>>n>>s;
	for (int i=0; i<s.length(); i++)
		if (s[i]>='A' && s[i]<='Z') s[i]-='A'+'a';
	for (int i=0; i<8; i++)
		if (l[i].length()==n) { 
			x=l[i];
			p=0;
			for (int j=0; j<n; j++)
				if (x[j]!=s[j] && s[j]!='.')  { p=1; break; }
			if (p==0) {cout<<x; return 0;}
		}
		
	
	
	return 0;

}