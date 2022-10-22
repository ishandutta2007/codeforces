#pragma GCC optimize("O3")
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

const ll mod=1000000007;

ll n,S,f[maxn];

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

ll fac[maxn],inv[maxn];

inline ll C(int N,int M)
{
	ll ret=1;
	for(int i=1;i<=M;i++) ret=(ret*(N-i+1))%mod;
	return (ret*inv[M])%mod;
}

inline ll Calc(ll N,ll M)
{
	if(N<mod&&M<mod) return C(N,M);
	return (Calc(N/mod,M/mod)*C(N%mod,M%mod))%mod;
}

int main()
{
	fac[0]=1; inv[0]=1; rep(i,1,maxn-5) fac[i]=(fac[i-1]*i)%mod,inv[i]=pw(fac[i],mod-2);
	n=read(); S=read(); rep(i,1,n) f[i]=read(); int ed=(1<<n)-1; ll ans=0;
	rep(s,0,ed)
	{
		ll tmp=S,cnt=0;
		rep(i,1,n) if(s&(1<<(i-1))) tmp-=(f[i]+1),cnt++;
		if(tmp<0) continue;
		if(cnt&1) ans=(ans-Calc(tmp+n-1,n-1)+mod)%mod;
		else ans=(ans+Calc(tmp+n-1,n-1))%mod;
	}
	cout<<ans<<endl;
	return 0;
}