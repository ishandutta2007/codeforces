#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		string a[n],b[m];
		FOR(i,0,n)cin>>a[i];
		FOR(i,0,m)cin>>b[i];
		int q;
		cin>>q;
		FOR(i,0,q)
		{
			ll h;
			cin>>h;
			h--;
			cout<<a[h%n]<<b[h%m]<<'\n';
		}
	}
	return 0;
}