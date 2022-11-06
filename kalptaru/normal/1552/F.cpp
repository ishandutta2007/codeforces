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
#define spre cout<<fixed<<setprecision(1);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
const ll mod=998244353;
// const ll mod=1e9+7;
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
struct por{
	ll x,y,s,p;
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("G.in", "r", stdin);
    // freopen("equal.out", "w", stdout);
    // ll gtest=0;
    // spre
    
	ll test=1;
	// int gt=0;
	// cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		por a[n];
		pair<ll,int> be[n];
		FOR(i,0,n)
		{
			cin>>a[i].x>>a[i].y>>a[i].s;
			be[i].ff=a[i].y;
			be[i].ss=i;
		}
		sort(be,be+n);
		int j=0;
		FOR(i,0,n)
		{
			while(j<n && be[j].ff<a[i].x)
			{
				a[be[j].ss].p=i;
				j++;
			}
		}
		ll pl[n];
		ll pre[n];
		pre[0]=pl[0]=a[0].x-a[0].y;
		FOR(i,1,n)
		{
			int l=a[i].p;
			if(l==0)
			{
				pl[i]=(pre[i-1]+a[i].x-a[i].y)%mod;
			}
			else
			{
				pl[i]=(pre[i-1]-pre[l-1]+a[i].x-a[i].y+mod)%mod;
			}
			pre[i]=(pre[i-1]+pl[i])%mod;
		}
		ll ans=a[n-1].x+1;
		FOR(i,0,n)
		{
			if(a[i].s==1)
			{
				ans+=pl[i];
				ans%=mod;
			}
		}
		cout<<ans%mod;
	}
	return 0;
}