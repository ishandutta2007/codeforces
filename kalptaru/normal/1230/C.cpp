#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
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
	while ( t-- ) 
	{
		int n,m;
		cin>>n>>m;
		vector<int> tr[n];
		int par[n];
		FOR(i,0,n)
		par[i]=i;
		int a,b;
		FOR(i,0,m)
		{
			cin>>a>>b;
			a--;
			b--;
			tr[b].push_back(a);
			tr[a].push_back(b);
		}
		if(n==7)
		{
			set<int> o;
			int mi=7;
			FOR(i,0,n)
			{
				FOR(j,0,n)
				{
					if(i!=j)
					{
						FOR(k,0,tr[i].size())
						o.insert(tr[i][k]);
						FOR(k,0,tr[j].size())
						o.insert(tr[j][k]);
						mi=min(mi,int(tr[i].size()+tr[j].size()-o.size()));
						o.clear();
					}
				}
			}
			cout<<m-mi;
			return 0;
		}
		cout<<m;
	}
	return 0;
}