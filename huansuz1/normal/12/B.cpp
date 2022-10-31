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
int n;
string s,l,x;
int main()
{
cin>>s>>l;
x=s;
sort(s.begin(),s.end());

if (s[0]=='0'){
	for (int j=0; j<s.length(); j++)
		if (s[j]!='0') {s[0]=s[j]; s[j]='0'; break;}	   
}                
if (s==l) cout<<"OK"; else cout<<"WRONG_ANSWER";

	return 0;
}