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
const ll mod=1000000007;
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
	ll test=1;
	// cin>>test;
	while(test--)
	{
		int q;
		cin>>q;
		int t,o;
		set<pair<int,int> > mo,po;
		pair<int,int> k;
		int c=0;
		FOR(i,0,q)
		{
			cin>>t;
			if(t==1)
			{
				cin>>o;
				mo.insert(mp(c,-o));
				po.insert(mp(-o,c));
				c++;
			}
			else if(t==2)
			{
				k=*mo.begin();
				cout<<k.first+1<<' ';
				mo.erase(k);
				po.erase(mp(k.second,k.first));
			}
			else
			{
				k=*po.begin();
				cout<<k.second+1<<' ';
				po.erase(k);
				mo.erase(mp(k.second,k.first));
			}
		}
	}
	return 0;
}