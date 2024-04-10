#include<bits/stdc++.h>
using namespace std;

int main()
{

	int n;string s;
	cin>>n>>s;
	int c1=0;
	for(auto c:s)c1+=c=='1';
	if(c1)cout<<1;
	for(int i=1;i<=n-c1;++i)putchar('0');
}