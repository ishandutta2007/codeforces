#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=500005,SIGMA=22,INF=0x3f3f3f3f;

struct edge
{
	int to,c;
};

int deep[MAXN],root,sum,maxson[MAXN],len[1<<SIGMA],ans[MAXN];
bool vis[MAXN];
vector <edge> G[MAXN];

void addedge(int u,int v,int c)
{
	G[u].pb((edge){v,c});
}

void dfs(int u,int fa)
{
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa)
		{
			deep[v]=deep[u]+1;
			dfs(v,u);
		}
	}
}

int getroot(int u,int fa)
{
	int su=1;
	maxson[u]=0;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa&&!vis[v])
		{
			int sv=getroot(v,u);
			su+=sv;
			maxson[u]=max(maxson[u],sv);
		}
	}
	maxson[u]=max(maxson[u],sum-su);
	if (maxson[u]<maxson[root]) root=u;
	return su;
}

int calsize(int u,int fa)
{
	int s=1;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa&&!vis[v])
			s+=calsize(v,u);
	}
	return s;
}

void work(int u,int fa,int now)
{
	ans[root]=max(ans[root],deep[u]-deep[root]+len[now]);
	for (int i=0;i<SIGMA;i++)
		ans[root]=max(ans[root],deep[u]-deep[root]+len[(1<<i)^now]);
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa&&!vis[v])
			work(v,u,now^(1<<G[u][i].c));
	}
}

void update(int u,int fa,int now)
{
	len[now]=max(len[now],deep[u]-deep[root]);
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa&&!vis[v])
			update(v,u,now^(1<<G[u][i].c));
	}
}

void clear(int u,int fa,int now)
{
	len[now]=-INF;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa&&!vis[v])
			clear(v,u,now^(1<<G[u][i].c));
	}
}

void work2(int u,int fa,int dep,int now,int anc)
{
	ans[anc]=max(ans[anc],dep+len[now]);
	for (int i=0;i<SIGMA;i++)
		ans[anc]=max(ans[anc],dep+len[(1<<i)^now]);
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa&&!vis[v])
			work2(v,u,dep+1,now^(1<<G[u][i].c),deep[v]<deep[anc]?v:anc);
	}
}

void dfs2(int u)
{
	vis[u]=true;
	len[0]=0;
	int f=-1,fc;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (!vis[v])
		{
			if (deep[v]<deep[u])
			{
				f=v;
				fc=G[u][i].c;
				continue;
			}
			work(v,u,1<<G[u][i].c);
			update(v,u,1<<G[u][i].c);
		}
	}
	if (f!=-1)
		work2(f,u,1,1<<fc,f);
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (!vis[v]&&v!=f)
			clear(v,u,1<<G[u][i].c);
	}
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (!vis[v])
		{
			root=0;
			sum=calsize(v,u);
			getroot(v,u);
			dfs2(root);
		}
	}
}

void dfs3(int u,int fa)
{
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa)
		{
			dfs3(v,u);
			ans[u]=max(ans[u],ans[v]);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=2;i<=n;i++)
	{
		int p;
		char ch[3];
		scanf("%d%s",&p,ch);
		addedge(p,i,ch[0]-'a');
		addedge(i,p,ch[0]-'a');
	}
	fill(len+1,len+(1<<SIGMA),-INF);
	dfs(1,0);
	maxson[root=0]=INT_MAX;
	sum=n;
	getroot(1,0);
	dfs2(root);
	dfs3(1,0);
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}