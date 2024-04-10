#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define pp pop_back()
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// const ll mod=998244353;
ll mod=1e9+7;
ll INF=1e18;
const int N=1000005;
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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("equal.in", "r", stdin);
    // freopen("equal.out", "w", stdout);
    // ll gtest=0;
    // spre
    
	ll test=1;
	// int gt=0;
	cin>>test;
	while(test--)
	{
		ll n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		ll t[n];
		ll o=mod;
		FOR(i,0,n)
		{
			if(s[i]=='1')
			{
				o=0;
			}
			else
			{
				o++;
			}
			t[i]=o;
		}
		o=mod;
		FORD(i,n,0)
		{
			if(s[i]=='1')
			{
				o=0;
			}
			else
			{
				o++;
			}
			if(t[i]>o)
			{
				t[i]=o;
			}
			else if(t[i]==o && o!=0)
			{
				t[i]=mod;
			}
		}
		FOR(i,0,n)
		{
			// cout<<t[i]<<' ';
			if(t[i]<=m)
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
		cout<<'\n';
	}
	return 0;
}