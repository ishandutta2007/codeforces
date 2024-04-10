#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 200005;
vector<vector<int>>adj(mxn);
vector<int>dp(mxn);
vector<int>dis(mxn);
int n;
int ans = 0;
void dfs(int u, int p){
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		dis[u] = max(dis[u],dis[nxt]);
		dp[u]+=dp[nxt];
	}
	dis[u]++;
	dp[u] = max(dp[u],dis[u]);
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 2; i<=n; i++){
		int x;
		cin >> x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	dfs(1,0);
	cout << dp[1] << '\n';
	return 0;
}