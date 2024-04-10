#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
const int mod = (int)1e9+7;
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
int mxn = 200005;
vector<vector<int>>adj(mxn);
vector<int>dp(mxn);
vector<int>dp2(mxn);
void dfs(int u, int p){
	dp[u] = 1;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		dp[u]*=(dp[nxt]+1)%mod;
		dp[u]%=mod;
	}
}

void dfs2(int u, int p){
	int v = dp2[u];
	vector<int>children; int cnt = 0; children.push_back(0);
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		cnt++;
		children.push_back(nxt);
	}
	vector<int>pre(cnt+1);
	vector<int>suf(cnt+2);
	pre[0] = 1; suf[cnt+1] = 1;
	for(int i = 1; i<=cnt; i++){
		pre[i] = pre[i-1]*(dp[children[i]]+1)%mod;
	}
	for(int i = cnt; i>=1; i--){
		suf[i] = suf[i+1]*(dp[children[i]]+1)%mod;
	}
	for(int i = 1; i<=cnt; i++){
		dp2[children[i]] = pre[i-1]*suf[i+1]%mod*dp2[u]%mod+1;
		dp2[children[i]]%=mod;
		dfs2(children[i],u);
	}
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
	dp2[1] = 1;
	dfs(1,0);
	dfs2(1,0);
	for(int i = 1; i<=n; i++){
		cout << dp[i]*dp2[i]%mod << " ";
	}
	cout << "\n";
	return 0;
}