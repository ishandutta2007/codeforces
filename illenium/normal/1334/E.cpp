#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 40000005
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

const ll mod=998244353;
bool bk[maxn];
int pri[maxn],cnt;
ll fac[10005],inv[10005];
map <ll,ll> mp;

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

inline void pre()
{
	bk[0]=1; bk[1]=1;
	for(ll i=2;i<=maxn-5;i++)
	{
		if(bk[i]==0) pri[++cnt]=i;
		for(ll j=1;j<=cnt&&i*pri[j]<=maxn-5;j++)
		{
			bk[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
	fac[0]=1; inv[0]=1;
	rep(i,1,1005) fac[i]=(fac[i-1]*i)%mod;
	rep(i,1,1005) inv[i]=pw(fac[i],mod-2);
}

inline ll sol(ll u)
{
	if(mp[u]) return mp[u];
	vector <int> v; v.clear(); ll ans=0,V=u;
	for(int i=1;pri[i]*pri[i]<=u&&i<=cnt;i++)
	{
		if(u%pri[i]==0)
		{
			int cnt=0;
			while(u%pri[i]==0) u/=pri[i],cnt++,ans++;
			v.pb(cnt);
		}
	}
	if(u!=1) ans++; ans=fac[ans];
	for(int i=0;i<v.size();i++) ans=(ans*inv[v[i]])%mod; return mp[V]=ans;
}

int main()
{
	ll D=read(),T=read(); pre();
	while(T--)
	{
		ll u=read(),v=read(); ll p=__gcd(u,v);
		printf("%lld\n",(sol(u/p)*sol(v/p))%mod);
	}
	return 0;
}