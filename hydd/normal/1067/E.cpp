#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
const int inv2=(Mod+1)>>1;
int n,dp[510000],ans;
vector<int> vec[510000];
void dfs(int u,int f){
	dp[u]=1;
	for (int v:vec[u]){
		if (v==f) continue; dfs(v,u);
		dp[u]=(1+1ll*(Mod-inv2)*dp[v])%Mod*dp[u]%Mod;
	}
	ans=(ans+Mod+1-dp[u])%Mod;
}
int main(){
	scanf("%d",&n); int u,v;
	for (int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		vec[u].push_back(v); vec[v].push_back(u);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++) ans=(ans<<1)%Mod;
	printf("%d\n",ans);
	return 0;
}