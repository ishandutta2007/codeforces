#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

const ll mod=1000000007;
ll fac[maxn],inv[maxn],a[maxn],pre[maxn];

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

int main()
{
	ll n=read(),k=read(); rep(i,1,k+2) a[i]=pw(i,k),pre[i]=(pre[i-1]+a[i])%mod;
	fac[0]=1; inv[0]=1;
	rep(i,1,k+2) fac[i]=(fac[i-1]*i)%mod;
	rep(i,1,k+2) inv[i]=pw(fac[i],mod-2);
	
	ll ans=0,tot=1,nw=1;
	rep(i,1,k+2) tot=(tot*(n-i))%mod; if(k%2==0) nw=-1;
	
	rep(i,1,k+2)
	{
		ll s1=pre[i],s2=(fac[i-1]*fac[k-i+2])%mod;
		s1=(s1*tot)%mod; s2=(s2*(n-i))%mod;
		s1=(s1*pw(s2,mod-2))%mod;
		if(nw==1) ans=(ans+s1)%mod; else ans=(ans-s1+mod)%mod;
		nw*=-1;
	}
	
	if(n<=k+2) printf("%lld\n",pre[n]); else printf("%lld\n",ans);
	return 0;
}