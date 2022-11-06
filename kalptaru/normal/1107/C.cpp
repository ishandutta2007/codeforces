#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,k;
		cin>>n>>k;
		ll a[n];
		ll ans=0;
		FOR(i,0,n)
		{
			cin>>a[i];
		}
		string s;
		cin>>s;
		vector<ll> g;
		char y=';';
		FOR(i,0,n+1)
		{
			if(i==n)
			{
				int d=g.size();
				sort(g.begin(),g.end());
				FOR(j,0,min(k,d))
				{
					ans+=g[d-j-1];
				}
			}
			else if(y==s[i])
			g.push_back(a[i]);
			else
			{
				int d=g.size();
				sort(g.begin(),g.end());
				FOR(j,0,min(k,d))
				{
					ans+=g[d-j-1];
				}
				y=s[i];
				g.clear();
				g.push_back(a[i]);
			}
		}
		cout<<ans;
	}
	return 0;
}