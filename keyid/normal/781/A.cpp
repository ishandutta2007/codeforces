#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=200005;

vector <int> G[MAXN],G2[MAXN];
int col[MAXN],fa[MAXN];

void dfs(int u)
{
	int num=1;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if (v==fa[u]) continue;
		while (num==col[u]||num==col[fa[u]]) num++;
		col[v]=num++;
		fa[v]=u;
		dfs(v);
	}
}

int main()
{
	//freopen("read.txt","r",stdin);
	int n;
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	col[1]=1;
	dfs(1);
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,col[i]);
	printf("%d\n",ans);
	for (int i=1;i<=n;i++)
		printf("%d ",col[i]);
	return 0;
}