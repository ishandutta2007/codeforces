#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=3e5+9;
int n;
int dp[M][3],ans=0;
vector<int>g[M];
void dfs(int u,int fa){
	dp[u][2]=1;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			dp[u][0]=(2ll*dp[u][0]*dp[v][0]%mod+1ll*dp[u][1]*(dp[v][1]+dp[v][2])%mod+1ll*dp[u][0]*dp[v][2]%mod+1ll*dp[u][2]*(dp[v][2]+dp[v][1])%mod)%mod;
			dp[u][1]=(2ll*dp[u][1]*dp[v][0]%mod+1ll*dp[u][2]*dp[v][0]%mod+1ll*dp[u][1]*dp[v][2]%mod)%mod;
			dp[u][2]=1ll*dp[u][2]*(dp[v][0]+dp[v][2])%mod;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	printf("%d\n",(dp[1][0]+dp[1][2])%mod);
	return 0;
}