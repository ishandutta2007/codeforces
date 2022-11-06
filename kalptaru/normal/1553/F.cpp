#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp() pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
const ll mod=1e9+7;
ll INF=1e18;
const ll N=300005;
ll po(ll a,ll b)
{
	ll re=1;  
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
ll t[2000000],co[2000000],sub[2000000];
ll sum(int v,int tl,int tr,int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	if(tl==l && tr==r)
	{
		return t[v];
	}
	int tm=(tl+tr)/2;
	return sum(2*v,tl,tm,l,min(tm,r))+sum(2*v+1,tm+1,tr,max(l,tm+1),r);
}
ll subt(int v,int tl,int tr,int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	if(tl==l && tr==r)
	{
		return sub[v];
	}
	int tm=(tl+tr)/2;
	return subt(2*v,tl,tm,l,min(tm,r))+subt(2*v+1,tm+1,tr,max(l,tm+1),r);
}
ll cnt(int v,int tl,int tr,int l,int r)
{
	if(l>r)
	{
		return 0;
	}
	if(tl==l && tr==r)
	{
		return co[v];
	}
	int tm=(tl+tr)/2;
	return cnt(2*v,tl,tm,l,min(tm,r))+cnt(2*v+1,tm+1,tr,max(l,tm+1),r);
}
void usub(int v,int tl,int tr,ll p,ll a)
{
	if(tl==tr)
	{
		sub[v]+=a;
		return;
	}
	int tm=(tl+tr)/2;
	if(p>tm)
	{
		usub(2*v+1,tm+1,tr,p,a);
	}
	else
	{
		usub(2*v,tl,tm,p,a);
	}
	sub[v]=sub[2*v]+sub[2*v+1];
}
void up(int v,int tl,int tr,ll p)
{
	if(tl==tr)
	{
		t[v]+=p;
		co[v]++;
		return;
	}
	int tm=(tl+tr)/2;
	if(p>tm)
	{
		up(2*v+1,tm+1,tr,p);
	}
	else
	{
		up(2*v,tl,tm,p);
	}
	t[v]=t[2*v]+t[2*v+1];
	co[v]=co[2*v]+co[2*v+1];
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
   
    
	ll test=1;
	// int gt=0;
	// cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a,b,c,d,e=0;
		ll ans=0;
		FOR(i,0,n)
		{
			cin>>a;
			b=0,c=a-1;
			d=0;
			ans+=a*e-subt(1,0,N,0,a);
			while(c<N)
			{
				ans+=sum(1,0,N,b,c)-d*a*cnt(1,0,N,b,c);
				usub(1,0,N,c+1,a);
				b+=a;
				c+=a;
				d++;
			}
			c=N;
			ans+=sum(1,0,N,b,c)-d*a*cnt(1,0,N,b,c);
			up(1,0,N,a);
			e++;
			cout<<ans<<' ';
		}
	}
	return 0;
}