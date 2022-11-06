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
struct edge
{
	ll u,v,c;
	
};
ll dfs(int i, int j,vector<int> tree[],ll sub[])
{
	ll s=1;
	FOR(k,0,tree[i].size())
	{
		if(tree[i][k]!=j)
		{
			s+=dfs(tree[i][k],i,tree,sub);
		}
	}
	sub[i]=s;
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	cin>>t;
	while(t--)
	{
		int k;
		cin>>k;
		ll sub[2*k],u,v,c;
		edge r[2*k-1];
		vector<int> tree[2*k];
		FOR(i,0,2*k-1)
		{
			cin>>u>>v>>c;
			tree[u-1].pb(v-1);
			tree[v-1].pb(u-1);
			r[i].u=u-1;
			r[i].v=v-1;
			r[i].c=c;
		}
		dfs(0,-1,tree,sub);
		ll mi=0,ma=0;
		FOR(i,0,2*k-1)
		{
			ma+=(min(min(sub[r[i].u],sub[r[i].v]),(2*k-min(sub[r[i].u],sub[r[i].v])))*r[i].c);
			mi+=((min(sub[r[i].u],sub[r[i].v])%2)*r[i].c);
//			cout<<mi<<' '<<ma<<'\n';
		}
		cout<<mi<<' '<<ma<<'\n';
	}
	return 0;
}