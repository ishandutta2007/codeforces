#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
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

ll n,k1,k2,w,b;

int main()
{
	int T=read();
	while(T--)
	{
		n=read(),k1=read(),k2=read(),w=read(),b=read();
		ll p1=min(k1,k2)+abs(k1-k2)/2;
		ll p2=min(n-k1,n-k2)+abs(k1-k2)/2;
		if(w<=p1&&b<=p2) puts("YES"); else puts("NO");
	}
	return 0;
}