// Hydro submission #616ebb6d21d049bbf2e60264@1634646893623
#include<bits/stdc++.h> // 
using namespace std;

int n,m,k;

long long dp[(1<<19)][19];

int node[19];

int edge[19][19];

int tot,S=0;

void dfs(int now,int cnt,int go)
{
	if(cnt==go)
	{
		for(int i=1; i<=n; ++i)
		{
			if(!((S>>i-1)&1)) continue;
			int now=1,s=S;
			while(s)
			{
				if(s&1)
				{
					if(edge[i][now]==0x3f3f3f3f) dp[S][i]=max(dp[S][i],dp[S-(1<<i-1)][now]+node[i]);
					else dp[S][i]=max(dp[S][i],dp[S-(1<<i-1)][now]+node[i]+edge[i][now]);
				}
				s>>=1;
				++now;
			}
		}
		return;
	}
	for(int i=now; i<=n; ++i)
	{
		S+=(1<<i-1);
		dfs(i+1,cnt+1,go);
		S-=(1<<i-1);
	}
}

int main()
{
	memset(edge,0x3f,sizeof(edge));
	int u,v,w;
	long long ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d",&node[i]);
		dp[1<<i-1][i]=node[i];
	}
	for(int i=1; i<=k; ++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		edge[u][v]=w;
	}
	for(int i=2; i<=m; ++i)
	{
		dfs(1,0,i);
	}
	for(int i=0; i<(1<<n); ++i)
	{
		for(int j=1; j<=n; ++j)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%lld",ans);
	return 0;
}