#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
vector<pii> G[100100];
int depth[100100];
int fa[100100][20];
int del[100100];
void dfs(int u,int f)
{
	depth[u]=depth[f]+1;
	fa[u][0]=f;
	for(auto p:G[u]) if(p.first!=f)
		dfs(p.first,u);
}
int lca(int u,int v)
{
	if(depth[u]<depth[v])
		swap(u,v);
	int delta=depth[u]-depth[v];
	for(int i=0;i<20;i++)
		if(delta>>i&1)
			u=fa[u][i];
	if(u==v)
		return u;
	for(int i=19;i>=0;i--)
		if(fa[u][i]!=fa[v][i])
		{
			u=fa[u][i];
			v=fa[v][i];
		}
	return fa[u][0];
}
int ans[100100];
int dfs2(int u,int f)
{
	int sum=del[u];
	for(auto p:G[u]) if(p.first!=f)
	{
		sum+=(ans[p.second]=dfs2(p.first,u));
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].pb(mp(v,i));
		G[v].pb(mp(u,i));
	}
	dfs(1,0);
	for(int i=1;i<20;i++)
		for(int j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	int k;
	cin>>k;
	while(k--)
	{
		int u,v;
		cin>>u>>v;
		int w=lca(u,v);
		del[w]-=2;
		del[u]++;
		del[v]++;
	}
	dfs2(1,0);
	for(int i=1;i<n;i++)
		cout<<ans[i]<<" ";
	return 0;
}