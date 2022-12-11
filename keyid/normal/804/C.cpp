#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=300005;

struct edge
{
	int to,nxt;
}e[MAXN*2];

int ec,first[MAXN],col[MAXN],vis[MAXN];
vector <int> s[MAXN];

void addedge(int u,int v)
{
	e[ec]=(edge){v,first[u]};
	first[u]=ec++;
}

void dfs(int u,int fa)
{
	for (int i=0;i<s[u].size();i++)
		if (col[s[u][i]])
			vis[col[s[u][i]]]=u;
	int now=1;
	for (int i=0;i<s[u].size();i++)
		if (!col[s[u][i]])
		{
			while (vis[now]==u) now++;
			col[s[u][i]]=now++;
		}
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa)
		{
			dfs(v,u);
		}
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	fill(first+1,first+n+1,-1);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		while (x--)
		{
			int v;
			scanf("%d",&v);
			s[i].pb(v);
		}
	}
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	for (int i=1;i<=m;i++)
		if (!col[i])
			col[i]=1;
	int _max=0;
	for (int i=1;i<=m;i++)
		_max=max(_max,col[i]);
	printf("%d\n",_max);
	for (int i=1;i<=m;i++)
		printf("%d ",col[i]);
	return 0;
}