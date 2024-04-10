#pragma GCC optimize(2)
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

ll fac[maxn],inv[maxn],n,k,a[maxn];

inline ll wk(ll x){return x*(x-1)/2;}

int main()
{
	int T=read();
	while(T--)
	{
		ll n=read(),m=3,k=2;
		rep(i,1,n) a[i]=read(); sort(a+1,a+n+1);
		ll r=1; ll ans=0;
		rep(i,1,n)
		{
			while(a[r]-a[i]<=k&&r<=n) r++;
			ans=(ans+wk(r-i-1));
		}
		printf("%lld\n",ans);
	}
	return 0;
}