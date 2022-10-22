#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll u,v;

int main()
{
	cin>>u>>v;;
	if(u>v) {puts("-1"); return 0;}
	ll p=v-u;
	if(p%2==1) {puts("-1"); return 0;}
	if(u==v)
	{
		if(u==0) puts("0");
		else {puts("1"); cout<<u<<endl;}
		return 0;
	}
	ll p2=(v-u)/2;
	if((p2&u)==0)
	{
		puts("2");
		cout<<p2<<" "<<(p2|u)<<endl;
	}
	else
	{
		cout<<3<<endl;
		cout<<u<<" "<<p2<<" "<<p2<<endl;
	}
	
	return 0;
}