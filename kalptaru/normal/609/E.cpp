#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll ma[200001][20];
int parent_tree[200001][25];
int height[200001];
vector<pair<int,ll> > tree[200001];





void dfs(int i,int j,ll e,int h)
{
	parent_tree[i][0]=j;
	height[i]=h;
	ma[i][0]=e;
	int s=tree[i].size();
	FOR(k,0,s)
	{
		if(tree[i][k].first!=j)
		dfs(tree[i][k].first,i,tree[i][k].second,h+1);
	}
}
struct Edge
{
    int u, v, i; 
	ll w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};
bool ch[200001];
int parent[200001];
void make_set(int v) 
{
    parent[v] = v;
}
int find_set(int v) 
{
    if (v == parent[v])
        return v;
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int query(int a, int b)
{
	ll ans=0;
	if(height[a]>height[b])
	swap(a,b);
	int h=height[b]-height[a],i=0;
	while(h>0)
	{
		if(h&1)
		{
			ans=max(ans,ma[b][i]);
			b=parent_tree[b][i];
		}
		i++;
		h>>=1;
	}
//	cout<<a<<' '<<b<<' '<<ans<<' ';
	if(a==b)
	return ans;
	i=0;
	while(parent_tree[a][i]!=parent_tree[b][i])
	i++;
	while(i>=0)
	{
		if(parent_tree[a][i]!=parent_tree[b][i])
		{
			ans=max(ans,max(ma[a][i],ma[b][i]));
			a=parent_tree[a][i];
			b=parent_tree[b][i];
		}
		i--;
	}
	ans=max(ans,max(ma[a][0],ma[b][0]));
	return ans;
}
int main()
{
	
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n,m,u,v;
		ll w;
		cin>>n>>m;
		Edge e;
		vector<Edge> edges,ed;
		ll cost = 0;
		
		vector<Edge> result;
		FOR(i,0,m)
		{
			cin>>u>>v>>w;
			e.u=u-1;
			e.v=v-1;
			e.w=w;
			e.i=i;
			edges.push_back(e);
		}
		ed=edges;
		for (int i = 0; i < n; i++)
   			parent[i] = i;
		sort(edges.begin(), edges.end());
		FOR(i,0,m) 
		{
			e=edges[i];
		    if (find_set(e.u) != find_set(e.v) )
			{
		        cost += e.w;
		        result.push_back(e);
		        union_sets(e.u,e.v);
		    	ch[e.i]=1;
		    }
		}
		FOR(i,0,n-1)
		{
			e=result[i];
			tree[e.u].push_back( make_pair(e.v,e.w));
			tree[e.v].push_back(make_pair(e.u,e.w));
		}
		dfs(0,0,0,0);
		ll multi=1;
		int power=1;
//		FOR(i,0,n)
//		{
//			FOR(j,0,tree[i].size())
//			cout<<tree[i][j].first<<' ';
//			cout<<'\n';
//		}
//		FOR(i,0,n)
//		cout<<parent_tree[i][0]<<' ';
//		cout<<'\n';
		while(multi<=n)
		{
			FOR(i,0,n)
			{
				parent_tree[i][power]=parent_tree[parent_tree[i][power-1]][power-1];
//				cout<<parent_tree[i][power]<<' ';
				ma[i][power]=max(ma[i][power-1],ma[parent_tree[i][power-1]][power-1]);
			}
			cout<<'\n';
			power++;
			multi<<=1;
		}
		FOR(i,0,m)
		{
			e=ed[i];
			if(ch[e.i])
			{
				cout<<cost<<'\n';
			}
			else
			{
				cout<<cost-query(e.u,e.v)+e.w<<'\n';
			}
//			cout<<query(e.u,e.v)<<'\n';
		}
	}
	return 0;
}