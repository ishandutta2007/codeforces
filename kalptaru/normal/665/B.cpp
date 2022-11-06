#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll n,m,k;
		cin>>n>>m>>k;
		ll arr[k+1];
		set<ll> p;
		ll u;
		FOR(i,0,k)
		{
			cin>>u;
			arr[u]=mod-k+i+1;
// 			cout<<u<<' '<<arr[u]<<'\n';
			p.insert(mod-k+i+1);
		}
		ll c=mod-k;
		ll ans=0;
		ll j;
// 		cout<<arr[5];
		FOR(i,0,n*m)
		{
			cin>>u;
			j=(distance(p.begin(),p.find(arr[u])));
			ans+=(j+1);
// 			cout<<u<<'\n';
// 			cout<<u<<' '<<arr[u]<<'\n';
			p.erase(arr[u]);
			arr[u]=c;
			p.insert(c);
			c--;
// 			cout<<j<<' ';
		}
		cout<<ans;
	}
	return 0;
}