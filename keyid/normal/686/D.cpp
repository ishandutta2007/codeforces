#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=300005;

struct edge
{
	int to,nxt;
}e[MAXN];

int ec,first[MAXN],fa[MAXN],d[MAXN],deep[MAXN],size[MAXN];
LL ds[MAXN],ds2[MAXN];

inline void addedge(int u,int v)
{
	e[ec]={v,first[u]};
	first[u]=ec++;
}

void dfs1(int u)
{
	d[u]=u;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		deep[v]=deep[u]+1;
		dfs1(v);
		size[u]+=size[v];
		ds[u]+=ds[v];
	}
	ds[u]+=size[u];
	ds2[u]=ds[u];
	size[u]++;
}

void dfs2(int u)
{
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		dfs2(v);
		int p=d[v];
		LL sum=ds[v]+ds2[u]-ds2[v]-size[v]+(LL)(deep[p]-deep[u])*(size[u]-size[v]);
		while (size[p]*2<size[u])
		{
			sum+=size[p]*2-size[u];
			p=fa[p];
		}
		if (sum<=ds[u])
		{
			ds[u]=sum;
			d[u]=p;
		}
	}
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	fill(first+1,first+n+1,-1);
	for (int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		addedge(fa[i],i);
	}
	dfs1(1);
	dfs2(1);
	while (q--)
	{
		int v;
		scanf("%d",&v);
		printf("%d\n",d[v]);
	}
	return 0;
}