#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
typedef long double ld;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
ll mod=1e9+7;
ll INF=1e18;
ll po(ll a,ll b){
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
    // ll gtest=0;
    // spre
	ll test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		ll a[n],o=0,p=0;
		FOR(i,0,n)
		{
			cin>>a[i];
			o^=a[i];

		}
		if(o==0)
		{
			cout<<"YES\n";
			continue;
		}
		bool f=0,g=1;
		FOR(i,0,n)
		{
			p^=a[i];
			if(p==o)
			{
				f=1;
			}
			if(f && p==0)
			{
				g=0;
				cout<<"YES\n";
				break;
			}
		}
		if(g)
			cout<<"NO\n";
	}
	return 0;
}