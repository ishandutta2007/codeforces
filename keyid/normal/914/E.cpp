#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define pb push_back
#define mp make_pair
#define fi first
#define sc second

const int MAXN=200005;

struct edge
{
	int to,nxt;
}e[MAXN*2];

int ec,first[MAXN],root,sum,maxson[MAXN],d[MAXN],cnt[1<<20],T,vis2[MAXN];
char w[MAXN];
bool vis[MAXN];
LL dp[MAXN],ans[MAXN];

void addedge(int u,int v)
{
	e[ec]={v,first[u]};
	first[u]=ec++;
}

int getroot(int u,int fa)
{
	int su=1;
	maxson[u]=0;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa&&!vis[v])
		{
			int sv=getroot(v,u);
			su+=sv;
			maxson[u]=max(maxson[u],sv);
		}
	}
	maxson[u]=max(maxson[u],sum-su);
	if (maxson[u]<maxson[root])
		root=u;
	return su;
}

int calsize(int u,int fa)
{
	int s=1;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa&&!vis[v])
			s+=calsize(v,u);
	}
	return s;
}

void work1(int u,int fa,int now)
{
	now^=1<<w[u];
	if (vis2[u]!=T)
	{
		vis2[u]=T;
		dp[u]=0;
	}
	dp[u]+=cnt[now];
	for (int i=0;i<20;i++)
		dp[u]+=cnt[now^(1<<i)];
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa&&!vis[v])
			work1(v,u,now);
	}
}

void work2(int u,int fa,int now)
{
	now^=1<<w[u];
	cnt[now]++;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa&&!vis[v])
			work2(v,u,now);
	}
}

void clear(int u,int fa,int now)
{
	now^=1<<w[u];
	cnt[now]=0;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa&&!vis[v])
			clear(v,u,now);
	}
}

void dfs2(int u,int fa)
{
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (v!=fa&&!vis[v])
		{
			dfs2(v,u);
			dp[u]+=dp[v];
		}
	}
	ans[u]+=dp[u];
}

void dfs(int u)
{
	vis[u]=true;
	int ct=0;
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (!vis[v])
			d[ct++]=v;
	}
	T++;
	for (int i=0;i<ct;i++)
	{
		work1(d[i],u,0);
		work2(d[i],u,1<<w[u]);
	}
	for (int i=0;i<ct;i++)
		clear(d[i],u,1<<w[u]);
	cnt[1<<w[u]]++;
	for (int i=ct-1;i>=0;i--)
	{
		work1(d[i],u,0);
		work2(d[i],u,1<<w[u]);
	}
	cnt[1<<w[u]]--;
	LL t=0;
	for (int i=0;i<ct;i++)
	{
		dfs2(d[i],u);
		t+=dp[d[i]];
	}
	t+=cnt[0];
	for (int i=0;i<20;i++)
		t+=cnt[1<<i];
	//t+=cnt[1<<w[u]];
	ans[u]+=t/2;
	for (int i=0;i<ct;i++)
		clear(d[i],u,1<<w[u]);
	for (int i=first[u];i!=-1;i=e[i].nxt)
	{
		int v=e[i].to;
		if (!vis[v])
		{
			root=0;
			sum=calsize(v,u);
			getroot(v,u);
			dfs(root);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		first[i]=-1;
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	scanf("%s",w+1);
	for (int i=1;i<=n;i++)
		w[i]-='a';
	maxson[root=0]=INT_MAX;
	sum=n;
	getroot(1,0);
	dfs(root);
	for (int i=1;i<=n;i++)
		printf("%lld ",ans[i]+1);
	return 0;
}