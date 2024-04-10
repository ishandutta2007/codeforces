#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
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

ll n,p,a[maxn];
map <ll,ll> mp;

inline ll Mod(ll a,ll b){return a<b?a:a%b+b;}

inline ll qpow(ll a,ll b,ll mod)
{
	ll ans=1,base=a;
	while(b)
	{
		if(b&1) ans=Mod(ans*base,mod);
		base=Mod(base*base,mod); b>>=1;
	}
	return ans;
}

inline ll phi(ll x)
{
	if(mp[x]) return mp[x];
	ll ans=x;
	for(ll i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			ans=ans/i*(i-1);
			while(x%i==0) x/=i;
		}
	}
	if(x!=1) ans=ans/x*(x-1); mp[x]=ans;
	return ans;
}

inline ll sol(ll L,ll R,ll mod)
{
	//cout<<L<<" "<<R<<" "<<mod<<endl;
	if(L==R||mod==1) return Mod(a[L],mod);
	return qpow(a[L],sol(L+1,R,phi(mod)),mod);
}

int main()
{
	n=read(); p=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int q=read();
	while(q--)
	{
		ll l=read(),r=read();
		printf("%lld\n",sol(l,r,p)%p);
	}
	return 0;
}