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
const ll mod=1000000007;

inline ll pw(ll a,ll b)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1) ans=(ans*base)%mod;
		base=(base*base)%mod; b>>=1;
	}
	return ans;
}

inline ll C(int N,int M)
{
	if(N<M||M<0) return 0;
	return (fac[N]*inv[M]%mod)*inv[N-M]%mod;
}

int main()
{
	fac[0]=1; inv[0]=1;
	rep(i,1,(maxn-5)) fac[i]=(fac[i-1]*i)%mod;
	rep(i,1,(maxn-5)) inv[i]=pw(fac[i],mod-2);
	
	int T=read();
	while(T--)
	{
		int n=read(),m=read(),k=read();
		rep(i,1,n) a[i]=read(); sort(a+1,a+n+1);
		int r=1; ll ans=0;
		rep(i,1,n)
		{
			while(a[r]-a[i]<=k&&r<=n) r++;
			ans=(ans+C(r-i-1,m-1))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}