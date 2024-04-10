#include<bits/stdc++.h>
using namespace std;
int ans[1000010],indx;
bool book[1000010];
 
int main()
{
	int n,s;
	cin>>n>>s;
	if(n==1)
	{
		if(s==1) {puts("NO"); return 0;}
		puts("YES");
		cout<<s<<'\n'<<(s-1)<<'\n';
		return 0;
	}
	if(n==2)
	{
		if(s<=3) {puts("NO"); return 0;}
		puts("YES");
		cout<<s/2<<' '<<s-s/2<<'\n'<<1;
		return 0;
	}
	if(n>s/2) {puts("NO"); return 0;}
	else
	{
		puts("YES");
		cout<<(s-n+1);
		for(int i=2;i<=n;++i) cout<<' '<<1;
		cout<<'\n'<<s/2<<'\n';
	}
	return 0;
}