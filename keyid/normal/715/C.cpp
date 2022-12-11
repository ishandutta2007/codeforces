#include <bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long LL;

const int MAXN=100005;

struct edge
{
	int to,c;
};

int MOD,n,root,sum,maxson[MAXN],b10[MAXN],inv[MAXN];
bool vis[MAXN];
LL ans;
vector <edge> G[MAXN];
map <int,int> ms;

void gcd(int a,int b,int &x,int &y)
{
	if (b) { gcd(b,a%b,y,x); y-=a/b*x; }
	else { x=1; y=0; }
}

int getinv(int a,int n)
{
	int x,y;
	gcd(a,n,x,y);
	return (x+n)%n;
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

void work1(int u,int fa,int d,int now)
{
	ans+=ms[(LL)(MOD-now)*inv[d]%MOD];
	now=(LL)now*10%MOD;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa&&!vis[v])
			work1(v,u,d+1,(now+G[u][i].c)%MOD);
	}
}

void work2(int u,int fa,int d,int now)
{
	ms[now]++;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa&&!vis[v])
			work2(v,u,d+1,(now+(LL)G[u][i].c*b10[d])%MOD);
	}
}

void work3(int u,int fa,int d,int now)
{
	if (now==0) ans++;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (v!=fa&&!vis[v])
			work3(v,u,d+1,(now+(LL)G[u][i].c*b10[d])%MOD);
	}
}

void dfs(int u)
{
	vis[u]=true;
	ms[0]++;
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (!vis[v])
		{
			work1(v,u,1,G[u][i].c);
			work2(v,u,1,G[u][i].c);
			work3(v,u,1,G[u][i].c);
		}
	}
	ms.clear();
	for (int i=G[u].size()-1;i>=0;i--)
	{
		int v=G[u][i].to;
		if (!vis[v])
		{
			work1(v,u,1,G[u][i].c);
			work2(v,u,1,G[u][i].c);
		}
	}
	ms.clear();
	for (int i=0;i<G[u].size();i++)
	{
		int v=G[u][i].to;
		if (!vis[v])
		{
			root=n;
			sum=calsize(v,u);
			getroot(v,u);
			dfs(root);
		}
	}
}

int main()
{
	scanf("%d%d",&n,&MOD);
	for (int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		w%=MOD;
		G[u].pb((edge){v,w});
		G[v].pb((edge){u,w});
	}
	b10[0]=1;
	for (int i=1;i<=n;i++)
		b10[i]=b10[i-1]*10LL%MOD;
	for (int i=0;i<=n;i++)
		inv[i]=getinv(b10[i],MOD);
	sum=n;
	maxson[root=n]=INT_MAX;
	getroot(0,-1);
	dfs(root);
	printf("%lld",ans);
	return 0;
}