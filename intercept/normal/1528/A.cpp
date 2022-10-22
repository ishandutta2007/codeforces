#include<bits/stdc++.h>
#define ll long long
#define eb emplace_back
using namespace std;
const int M=2e5+9;
ll dp[M][2];
int n;
int l[M],r[M];
vector<int>g[M];
void dfs(int u,int fa){
	dp[u][0]=dp[u][1]=0;
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			dp[u][0]+=max(dp[v][0]+abs(l[u]-l[v]),dp[v][1]+abs(l[u]-r[v]));
			dp[u][1]+=max(dp[v][0]+abs(r[u]-l[v]),dp[v][1]+abs(r[u]-r[v]));
		}
	}
}
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]),g[i].clear();
	for(int i=1,u,v;i<n;++i){
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	printf("%lld\n",max(dp[1][0],dp[1][1]));
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}