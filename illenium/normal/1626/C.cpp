#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
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

ll n,h[maxn],t[maxn],ans,st[maxn];

inline ll cal(ll x){return x*(x+1)/2;}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); ans=0; rep(i,1,n) t[i]=read(); rep(i,1,n) h[i]=read(),st[i]=t[i]-h[i];
		ll lst=n,nw=st[n];
		per(i,n-1,0)
		{
			if(t[i]<=nw)
			{
				ans+=cal(t[lst]-nw);
				lst=i; nw=st[i];
			}
			else nw=min(nw,st[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}