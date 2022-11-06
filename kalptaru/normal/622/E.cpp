#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) ;for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int dep[500001];
vector<int > ld;
void dfs(int i,int j,int d,vector<int> tree[])
{
	if(tree[i].size()==1 && i!=0)
	ld.pb(d);
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		dfs(tree[i][k],i,d+1,tree);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		vector<int> tree[n];
		FOR(i,1,n)
		{
			int u,v;
			cin>>u>>v;
			tree[v-1].pb(u-1);
			tree[u-1].pb(v-1);
		}
		int m=0;
		FOR(i,0,tree[0].size())
		{
			dfs(tree[0][i],0,1,tree);
			sort(ld.begin(),ld.end());
			int o=0;
			FOR(i,0,ld.size())
			{
				o=max(o+1,ld[i]);
//				cout<<ld[i]<<' ';
			}
			ld.clear();
			m=max(m,o);
		}
		cout<<m;
	}
	return 0;
}