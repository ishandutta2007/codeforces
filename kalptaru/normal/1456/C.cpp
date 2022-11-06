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
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
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
	int test=1;
	// cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		ll a[n];
		k++;
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		ll ans=0,s=0;
		FORD(i,n,0)
		{
			ans+=s;
			s+=a[i];
			// cout<<a[i]<<' ';
		}
		ll o=ans;
		// cout<<ans;
		FOR(i,0,n)
		{
			s-=a[i];
			if(((i+1)%k)!=0)
				ans-=s;
			// ans+=(a[i]*(i/k));
			o=max(o,ans);
		}
		cout<<o;
	}
	return 0;
}