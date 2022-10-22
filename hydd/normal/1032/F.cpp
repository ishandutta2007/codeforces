#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int n; ll dp[310000][4],tmp[4];
vector<int> vec[310000];
void dfs(int u,int f){
	dp[u][0]=1;
	for (int v:vec[u]){
		if (v==f) continue;
		dfs(v,u);
		tmp[0]=dp[u][0]*(dp[v][0]+dp[v][2])%Mod;
		tmp[1]=(dp[u][0]*dp[v][2]+dp[u][1]*(dp[v][0]+dp[v][2]+dp[v][2]))%Mod;
		tmp[2]=(dp[u][0]*(dp[v][0]+dp[v][1])+dp[u][1]*(dp[v][0]+dp[v][1])+dp[u][2]*(dp[v][0]+dp[v][2]+dp[v][2]))%Mod;
		dp[u][0]=tmp[0]; dp[u][1]=tmp[1]; dp[u][2]=tmp[2];
	}
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0);
	printf("%lld\n",(dp[1][0]+dp[1][2])%Mod);
	return 0;
}