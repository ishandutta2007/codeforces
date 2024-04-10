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
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
    // freopen("java2016.in", "r", stdin);
    // freopen("java2016.out", "w", stdout);
    // ll gtest=0;
    // spre
	ll test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int u[n];
		FOR(i,0,n)
		{
			cin>>u[i];
		}
		vector<ll> s[n];
		ll o,p;
		FOR(i,0,n)
		{
			cin>>o;
			s[u[i]-1].pb(o);
		}
		ll ans[n]={0};
		FOR(i,0,n)
		{
			sort(s[i].begin(),s[i].end(),greater<ll>());

			o=s[i].size();
			FOR(j,1,o)
			{
				s[i][j]+=s[i][j-1];
			}
			FOR(j,1,o+1)
			{
				p=o-(o%j);
				ans[j-1]+=s[i][p-1];
			}
		}
		FOR(i,0,n)
		{
			cout<<ans[i]<<' ';
		}
		cout<<'\n';

	}
	return 0;
}