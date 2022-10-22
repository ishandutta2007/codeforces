#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int main()
{
	ll T=read();
	while(T--)
	{
		ll n=read(),g=read(),b=read();
		ll tmp=(n+1)/2;
		ll p1=tmp/g,p2=tmp%g;
		ll ans=p1*(g+b)+p2;
		if(p2==0) ans-=b;
		printf("%lld\n",max(ans,n));
	}
	return 0;
}