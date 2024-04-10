#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=200005,MOD=1000000007;

int ans,val[MAXN],dp[MAXN][2],size[MAXN][2],n;
vector <int> G[MAXN];

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

void dfs(int u,int fa)
{
	size[u][1]=1;
	dp[u][1]=val[u];
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(v!=fa)
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
}

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		val[i]=read();
		val[i]=(val[i]+MOD)%MOD;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=read(); v=read();
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	ans=ans*2%MOD;
	for(int i=1;i<=n;i++) ans=(ans+val[i])%MOD;
	printf("%d",ans);
	return 0;
}