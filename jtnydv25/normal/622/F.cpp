#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long

ll mod;

#define ld long double
#define ui unsigned int

#define vi vector<int>
#define pb push_back
#define mp make_pair
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC

ll powr(ll a, ll b)
{
	ll x = 1;
	a %= mod;
	while(b)
	{
		if(b&1)
			x = (x*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return x;
}
ll inv(ll a)
{
	return powr(a,mod-2);
}

ll lagrange(vll& v , int k, ll x)
{
	ll inn = 1;
	for(int i = 1;i<=k;i++)
	{	
		inn = (inn*(x - i))%mod;
		inn = (inn*inv(mod - i))%mod;
	}
	ll ret = 0;
	for(int i = 0;i<=k;i++)
	{
		ret = (ret + v[i]*inn)%mod;
		ll md1 = mod - ((x-i)*(k-i))%mod;
		ll md2 = ((i+1)*(x-i-1))%mod;
		if(i!=k)
			inn = (((inn*md1)%mod)*inv(md2))%mod;
	}
	return ret;
}

ll pwsm(ll n ,int  k, ll p)
{
	if(k == 0)
	{
		return n%p;
	}
	mod = p;
	if(p <= k )
	{
		ll sm1 = 0;
		ll sm2 = 0;
		int x = n%p;
		for(int i = 1;i<=p;i++){
			sm1=(sm1+powr(i,k))%mod;
			if(i == x)
				sm2 = sm1;
		}
		return (sm1*(n/p) + sm2)%mod;
	}
	n%=p;
	if(n==0)
		return 0;
	vll v;
	int deg = k+1;
	ll sm = 0;
	v.pb(sm);
	for(int i = 1;i<=deg;i++)
	{
		sm = (sm + powr(i,k))%mod;
		v.pb(sm);
		if(n == i)
			return sm;
	}
	return lagrange(v,deg,n);
}
ll brute(ll n,ll k, ll p)
{
	mod=p;
	ll ret = 0;
	for(int i = 1;i<=n;i++)
		ret=(ret+powr(i,k))%mod;
	return ret;
}
int main()
{
	ll n,p = 1e9+7;
	int k;
	
	cin>>n>>k;
	cout<<pwsm(n,k,p)<<"\n";
	return 0;
}