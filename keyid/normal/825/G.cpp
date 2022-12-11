#include <bits/stdc++.h>
using namespace std;

const int MAXN=1000005;

struct edge
{
	int to,nxt;
}e[MAXN*2];

int ec,first[MAXN],fa[MAXN],mn,val[MAXN];
bool vis[MAXN];

void addedge(int u,int v)
{
	e[ec]={v,first[u]};
	first[u]=ec++;
}

void dfs(int u)
{
	val[u]=min(val[u],u);
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa[u])
		{
			fa[v]=u;
			val[v]=val[u];
			dfs(v);
		}
	}
}

void mark(int u)
{
	if (vis[u]) return;
	vis[u]=true;
	mn=min(mn,u);
	mark(fa[u]);
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		first[i]=-1;
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	int op,x,ans=0;
	scanf("%d%d",&op,&x);
	x=x%n+1;
	val[x]=x;
	dfs(x);
	mn=x;
	vis[x]=true;
	for (int i=1;i<q;i++)
	{
		scanf("%d%d",&op,&x);
		x=(x+ans)%n+1;
		if (op==1)
			mark(x);
		else
			printf("%d\n",ans=min(val[x],mn));
	}
	return 0;
}