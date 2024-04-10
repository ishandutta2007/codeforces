#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n,k,z;
string s;

int main(){

	cin >> n >> k;
	for (int i=0; i<n; i++)  {
		cin>>s;
		string l="";
		sort(s.begin(),s.end());
		l+=s[0];
		for (int j=1; j<s.length(); j++)
			if (s[j]!=s[j-1]) l+=s[j];
		
		int p=0;
		for (int j=0; j<=k; j++)
			if ((l[j]-'0')!=j) { p=1; break; }
		if (p==0) z++;
	}
	cout<<z;
		
	return 0;
}