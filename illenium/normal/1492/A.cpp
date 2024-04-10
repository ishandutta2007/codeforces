#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e18
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
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
	int T=read();
	while(T--)
	{
		ll p=read(),a=read(),b=read(),c=read(),ans=inf;
		if(p%a==0) ans=0; else ans=a-p%a;
		if(p%b==0) ans=0; else ans=min(ans,b-p%b);
		if(p%c==0) ans=0; else ans=min(ans,c-p%c);
		printf("%lld\n",ans);
	}
	return 0;
}