#include<bits/stdc++.h>
using namespace std;
string s; int top,t[110000];
int main(){
	cin>>s; int n=s.length();
	for (int i=0;i<n;i++)
		if (s[i]=='1') t[++top]=i;
		else if (top) top--;
	while (top) s[t[top--]]='0';
	cout<<s<<endl;
	return 0;
}