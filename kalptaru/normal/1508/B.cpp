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
#define spre cout<<fixed<<setprecision(1);
typedef long long int ll;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=1e9+7;
ll INF=1e18;
ll po(ll a,ll b){
	ll re=1;  
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			// re%=mod;
		}
		a=(a*a);
		// a%=mod;
		b>>=1;
	}
	return re;
}
ll p[60];
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
	ll test=1;
	cin>>test;
	FOR(i,0,60)
	{
		p[i]=po(2,i);
	}
	while(test--)
	{
		int n;
		cin>>n;
		ll k;
		cin>>k;
		int ans[n];
		if(n<=60 && k>po(2,n-1))
		{
			cout<<"-1\n";
			continue;
		}
		k--;
		FOR(i,0,n)
		{
			ans[i]=i+1;
		} 
		int o=0;
		int u=n-1;
		while(k)
		{
			if(k%2)
			{
				o++;
			}
			else
			{
				FOR(j,0,o+1)
				{
					ans[j+u]=u+o-j+1;
				}
				o=0;
			}
			k>>=1;
			u--;

		}
		FOR(j,0,o+1)
		{
			ans[j+u]=u+o-j+1;
		}
		FOR(i,0,n)
		{
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}