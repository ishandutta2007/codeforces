#include<bits/stdc++.h>
using namespace std;
const int N=3000005,M=998244353;
int n,m,i,j,t,k,f[5005],tot,head[N],Next[N],adj[N],siz[5005],sz[5005];
long long dp[5005][1505];
vector<int> g[5005];
struct str{
	int u,v;
}e[N];
void Push(int u,int v)
{
	Next[++tot]=head[u];
	head[u]=tot;
	adj[tot]=v;
}
int Find(int x)
{
	return f[x]?f[x]=Find(f[x]):x;
}
void dfs(int i)
{
	if(i<=n)
	{
		siz[i]=1;
		dp[i][1]=1;
		return;
	}
	int j,k,l;
	long long tmp[1505];
	memset(tmp,0,sizeof(tmp));
	dp[i][0]=1;
	for(j=head[i];j;j=Next[j])
	{
		dfs(adj[j]);
		for(k=0;k<=siz[i];++k)
			tmp[k]=0;
		for(k=0;k<=siz[i];++k)
			for(l=0;l<=siz[adj[j]];++l)
				tmp[k+l]=(tmp[k+l]+dp[i][k]*dp[adj[j]][l])%M;
		siz[i]+=siz[adj[j]];
		for(k=0;k<=siz[i];++k)
			dp[i][k]=tmp[k];
	}
	++dp[i][1];
	/*cout<<i<<endl;
	for(j=1;j<=n;++j)
		cout<<dp[i][j]<<' ';
	cout<<endl;*/
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		{
			int a;
			scanf("%d",&a);
			e[a]=(str){i,j};
		}
	for(i=1;i<=n;++i)
	{
		g[i].push_back(i);
		siz[i]=1;
	}
	k=n;
	for(i=1;i<=n*(n-1)/2;++i)
	{
		int a=Find(e[i].u),b=Find(e[i].v);
		if(a!=b)
		{
			f[a]=b;
			for(auto it:g[a])
				g[b].push_back(it);
			g[a].clear();
			siz[b]+=siz[a];
			sz[b]+=sz[a];
		}
		++sz[b];
		if(sz[b]==siz[b]*(siz[b]-1)/2)
		{
			++k;
			for(auto it:g[b])
			{
				//cout<<k<<' '<<it<<endl;
				Push(k,it);
			}
			g[b].clear();
			g[b].push_back(k);
		}
	}
	memset(siz,0,sizeof(siz));
	dfs(k);
	for(i=1;i<=n;++i)
		printf("%d ",dp[k][i]);
}