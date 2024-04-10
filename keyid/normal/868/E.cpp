#include <bits/stdc++.h>
using namespace std;

const int MAXN=55,INF=0X3f3f3f3f;

struct edge
{
	int to,w,nxt;
}e[MAXN*2];

int n,ec,first[MAXN],d[MAXN],cri[MAXN],tot,id[MAXN*2],dp[MAXN*2][MAXN][MAXN];
bool vis[MAXN*2];

void addedge(int u,int v,int w)
{
	e[ec]={v,w,first[u]};
	first[u]=ec++;
}

int get_dep(int u,int fa)
{
	int ret=0;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa)
			ret=max(ret,get_dep(v,u)+e[i].w);
	}
	return ret;
}

int get_cri(int u,int fa)
{
	int ret=cri[u];
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa)
			ret+=get_cri(v,u);
	}
	return ret;
}

void topo_sort(int k)
{
	if (vis[k])
		return;
	vis[k]=true;
	int u=e[k].to,fa=e[k^1].to;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa)
			topo_sort(i);
	}
	id[tot++]=k;
}

int main()
{
	scanf("%d",&n);
	memset(first,-1,sizeof(first));
	for (int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
		d[u]++;
		d[v]++;
	}
	int s,m;
	scanf("%d%d",&s,&m);
	for (int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		cri[x]++;
	}
	for (int i=0;i<ec;i++)
	{
		dp[i][1][1]=get_dep(e[i].to,e[i^1].to)+e[i].w;
		for (int j=1;j<=m;j++)
			dp[i][j][0]=INF;
	}
	for (int i=0;i<ec;i++)
		if (!vis[i])
			topo_sort(i);
	for (int k=2;k<=m;k++)
		for (int u=0;u<ec;u++)
		{
			int eid=id[u],v=e[eid].to;
			if (d[v]!=1)
			{
				int fa=e[eid^1].to,*f=dp[eid][k];
				for (int i=first[v];i!=-1;i=e[i].nxt)
					if (e[i].to!=fa)
						for (int j=k;j>=1;j--)
							for (int l=1;l<=j;l++)
								f[j]=max(f[j],min(f[j-l],dp[i][k][l]));
				for (int j=1;j<=k;j++)
					f[j]+=e[eid].w;
			}
			else
				for (int i=1;i<=k;i++)
					dp[eid][k][i]=e[eid].w+dp[eid^1][k-i][k-i];
		}
	int ans=INF;
	for (int i=first[s];i!=-1;i=e[i].nxt)
	{
		int num=get_cri(e[i].to,s);
		if (num)
			ans=min(ans,dp[i][m][num]);
	}
	printf("%d",ans);
	return 0;
}