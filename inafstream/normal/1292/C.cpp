#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,sz[3005],s[3005][3005],isp[3005][3005],fa[3005];
long long dp[3005][3005],ans;
vector<int> adj[3005];

void dfs(int x,int fa)
{
	::fa[x]=fa;
	sz[x]=1;
	int i;
	rep(i,adj[x].size())
	{
		int y=adj[x][i-1];
		if (y==fa) continue;
		dfs(y,x);
		sz[x]+=sz[y];
	}
}

int son(int x,int y)
{
	int i;
	rep(i,adj[x].size())
	{
		if (adj[x][i-1]==fa[x]) continue;
		if (adj[x][i-1]==y||isp[adj[x][i-1]][y])
		{
			return adj[x][i-1];
		}
	}
	exit(-1);
}

long long calc(int x,int y)
{
	if (dp[x][y]!=-1) return dp[x][y];
	dp[x][y]=0;
	if (!isp[x][y]) dp[x][y]=max(dp[x][y],calc(fa[x],y)+s[x][y]);
	else {int t=son(x,y);dp[x][y]=max(dp[x][y],calc(t,y)+s[x][y]);}
	if (!isp[y][x]) dp[x][y]=max(dp[x][y],calc(x,fa[y])+s[x][y]);
	else {int t=son(y,x);dp[x][y]=max(dp[x][y],calc(x,t)+s[x][y]);}
	return dp[x][y];
}


int main()
{
	int i,j;
	scanf("%d",&n);
	rep(i,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(1,0);
	rep(i,n) rep(j,n) if (i!=j) s[i][j]=sz[i]*sz[j];
	rep(i,n)
	{
		j=i;
		while (j!=1)
		{
			j=fa[j];
			s[i][j]=s[j][i]=sz[i]*(n-sz[son(j,i)]);
			isp[j][i]=1;
		}
	}
	
	memset(dp,-1,sizeof(dp));
	rep(i,n) dp[i][i]=0;
	rep(i,n) rep(j,n) ans=max(ans,calc(i,j));
	
	cout<<ans<<endl;
	return 0;
}