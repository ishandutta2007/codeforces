#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = (int)1e9+7;
int modpow(int x, int y) {
	return !y?1:((y % 2 ? x : 1) * modpow((x * x) % mod, y / 2)) % mod;
}
vector<vector<int>>F(201,vector<int>(201));
vector<vector<int>>adj(201);
int ln = 10;
vector<vector<int>>dp(201,vector<int>(ln));
vector<int>lvl(201);
int n;
void dfs(int u, int p){
	lvl[u] = lvl[p]+1;
	dp[u][0] = p;
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
	}
}
int lca(int x, int y){
	if(lvl[x]<lvl[y])swap(x,y);
	int dif = lvl[x]-lvl[y];
	for(int i = 0; i<ln; i++){
		if((1<<i)&dif){
			x = dp[x][i];
		}
	}
	if(x==y)return x;
	for(int i = ln-1; i>=0; i--){
		if(dp[x][i]!=dp[y][i]){
			x = dp[x][i]; y = dp[y][i];
		}
	}
	return dp[x][0];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i = 1; i<=200; i++){
		F[i][0] = 1;
	}
	for(int i = 1; i<=200; i++){
		for(int j = 1; j<=200; j++){
			F[i][j] = (F[i][j-1]+F[i-1][j])*modpow(2,mod-2);
			F[i][j]%=mod;
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		for(int u = 1; u<=200; u++){
			lvl[u] = 0;
			for(int j = 0; j<ln; j++){
				dp[u][j] = 0;
			}
		}
		dfs(i,0);
		for(int u = 1; u<=n; u++){
			for(int v = u+1; v<=n; v++){
				int x = lca(u,v);
				int d1 = lvl[u]-lvl[x]; int d2 = lvl[v]-lvl[x];
				ans+=F[d1][d2]; ans%=mod;
			}
		}
	}
	ans*=modpow(n,mod-2); ans%=mod;
	cout << ans << "\n";
	return 0;
}