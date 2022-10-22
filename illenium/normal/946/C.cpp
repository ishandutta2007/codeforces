#include<bits/stdc++.h>
using namespace std;

int main()
{
	char s[100001];
	cin>>s; char t='a';
	for(int i=0;s[i] && t<='z';i++)
	{
		if(s[i]<=t) s[i]=t++;
	}
	if(t<='z') cout<<"-1";
	else cout<<s;
	return 0;
}