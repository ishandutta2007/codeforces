#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>

using namespace std;

string s,l,x,y;
int k;

int main(){
	cin>>s>>l;
	for (int i=0; i<s.length(); i++){
		if (s[i]=='|') k=1;
		if (k==0) x+=s[i];
		if (k==1&&s[i]!='|') y+=s[i];
	}
	for (int i=0; i<l.length(); i++)
		if (x.length()<y.length()) x+=l[i]; else y+=l[i];
	if (x.length()==y.length()) cout<<x<<'|'<<y; else cout<<"Impossible";

	return 0;
}