#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=100005;

struct edge
{
	int to,nxt;
}e[MAXN];

int ec,first[MAXN],a[MAXN],deep[MAXN];
bool vis[MAXN],vis2[MAXN],done[MAXN];
vector <int> G[MAXN],ans;

inline void addedge(int u,int v)
{
	vis[v]=true;
	e[ec]=(edge){v,first[u]};
	first[u]=ec++;
}

void dfs1(int u)
{
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		deep[v]=deep[u]+1;
		dfs1(v);
	}
}

void dfs2(int u)
{
	vis2[u]=true;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (!vis2[v])
			dfs2(v);
	}
}

bool cmp(int a,int b)
{
	return deep[a]>deep[b];
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	fill(first+1,first+n+1,-1);
	for (int u,v;m--;)
	{
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for (int i=1;i<=n;i++)
		if (!vis[i])
			dfs1(i);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		G[a[i]].pb(i);
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		int u=a[i];
		if (done[u]) continue;
		done[u]=true;
		for (int j=0;j<G[u].size();j++)
			if (vis2[G[u][j]])
			{
				printf("-1");
				return 0;
			}
		dfs2(u);
		ans.pb(u);
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
	return 0;
}