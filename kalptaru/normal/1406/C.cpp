#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
// ll mod=998244353;
ll INF=1e18;
bool f;
int n;
int dfs(int i,int j,vector<int> tree[])
{
	int s=1;
	int si=tree[i].size();
	FOR(k,0,si)
	{
		if(tree[i][k]!=j)
		{
			s+=dfs(tree[i][k],i,tree);
		}
	}
	if(s==(n/2) && f==0)
	{
		int o=0;
		if(tree[i][o]==j)
		{
			o=1;
		}
		cout<<tree[i][o]+1<<' '<<i+1<<'\n'<<tree[i][o]+1<<' '<<j+1<<'\n';
		f=1;
	}
	return s;
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
	int test=1;
	cin>>test;
	while(test--)
	{
		cin>>n;
		f=0;
		vector<int> tree[n];
		int u,v;
		FOR(i,1,n)
		{
			cin>>u>>v;
			tree[u-1].pb(v-1);
			tree[v-1].pb(u-1);
		}
		if((n%2)==1)
		{
			cout<<u<<' '<<v<<'\n'<<u<<' '<<v<<'\n';
			continue;
		}
		dfs(0,-1,tree);
		if(f==0)
		{
			cout<<u<<' '<<v<<'\n'<<u<<' '<<v<<'\n';
		}
	}
	return 0;
}