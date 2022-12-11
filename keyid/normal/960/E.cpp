#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=200005,MOD=1000000007;

int ans,val[MAXN],dp[MAXN][2],size[MAXN][2];
vector <int> G[MAXN];

void dfs(int u,int fa)
{
	size[u][1]=1;
	dp[u][1]=val[u];
	for (int v:G[u])
		if (v!=fa)
		{
			dfs(v,u);
			ans=(ans+(LL)size[u][0]*dp[v][1])%MOD;
			ans=(ans+(LL)dp[u][0]*size[v][1])%MOD;
			ans=(ans+(LL)size[u][1]*dp[v][0]%MOD+MOD)%MOD;
			ans=(ans+(LL)dp[u][1]*size[v][0])%MOD;
			size[u][0]+=size[v][1];
			size[u][1]+=size[v][0];
			dp[u][0]=(dp[u][0]+dp[v][1]-(LL)val[u]*size[v][1]%MOD+MOD)%MOD;
			dp[u][1]=(dp[u][1]+dp[v][0]+(LL)val[u]*size[v][0])%MOD;
		}
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
		val[i]=(val[i]+MOD)%MOD;
	}
	for (int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	ans=ans*2%MOD;
	for (int i=1;i<=n;i++)
		ans=(ans+val[i])%MOD;
	printf("%d",ans);
	return 0;
}