#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;

struct edge
{
	int to,nxt;
}e[MAXN*2];

struct query
{
	int k,id;
};

int n,ec,first[MAXN],c[MAXN],son[MAXN],ans[MAXN],cnt[MAXN],C[MAXN];
vector <query> q[MAXN];

void addedge(int u,int v)
{
	e[ec]=(edge){v,first[u]};
	first[u]=ec++;
}

void add(int x,int d)
{
	while (x)
	{
		C[x]+=d;
		x-=x&-x;
	}
}

int sum(int x)
{
	int ret=0;
	while (x<=n)
	{
		ret+=C[x];
		x+=x&-x;
	}
	return ret;
}

int dfs1(int u,int fa)
{
	int su=1,maxson=0;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa)
		{
			int sv=dfs1(v,u);
			if (sv>maxson)
			{
				maxson=sv;
				son[u]=v;
			}
			su+=sv;
		}
	}
	return su;
}

void add_subtree(int u,int fa)
{
	add(cnt[c[u]],-1);
	add(++cnt[c[u]],1);
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa)
			add_subtree(v,u);
	}
}

void clear(int u,int fa)
{
	add(cnt[c[u]],-1);
	add(--cnt[c[u]],1);
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa)
			clear(v,u);
	}
}

void dfs2(int u,int fa)
{
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa&&v!=son[u])
		{
			dfs2(v,u);
			clear(v,u);
		}
	}
	if (son[u])
	{
		dfs2(son[u],u);
		for (int i=first[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			if (v!=fa&&v!=son[u])
				add_subtree(v,u);
		}
	}
	add(cnt[c[u]],-1);
	add(++cnt[c[u]],1);
	for (int i=0;i<q[u].size();i++)
		ans[q[u][i].id]=sum(q[u][i].k);
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	fill(first+1,first+n+1,-1);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	for (int i=0;i<m;i++)
	{
		int v,k;
		scanf("%d%d",&v,&k);
		q[v].push_back((query){k,i});
	}
	dfs1(1,0);
	dfs2(1,0);
	for (int i=0;i<m;i++)
		printf("%d\n",ans[i]);
	return 0;
}