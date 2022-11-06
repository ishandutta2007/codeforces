#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>adj(200005);
vector<int>dp(200005);
int ans = 0;
void dfs(int u, int p){
	dp[u] = (int)1e18;
	int children = 0;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		children++;
		dp[u] = min(dp[u],dp[nxt]+1);
	}
	if(children==0){
		dp[u] = 0;
		return;
	}
	vector<int>arr;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		arr.push_back(dp[nxt]+1);
	}
	sort(arr.begin(),arr.end());
	for(int i = 0; i<arr.size()-1; i++){
		arr[i]++;
		ans = max(ans,arr[i]);
	}
	if(u==1)ans = max(ans,arr[arr.size()-1]);
	else ans = max(ans,arr[arr.size()-1]+1);
}
void reset(int n){
	for(int i = 1; i<=n; i++){
		adj[i].clear();
		dp[i] = 0;
	}
	ans = 0;
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i = 0; i<n-1; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs(1,0);
		cout << ans << "\n";
		reset(n);
	}
	return 0;
}