#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<vector<int>>adj(1000010);
int ln = 20;
vector<int>lvl(1000001);
vector<int>sz(1000001);
vector<bool>psa(1000001);
vector<vector<int>>dp(1000001,vector<int>(ln));
void dfs(int u, int p){
	lvl[u] = lvl[p]+1;
	dp[u][0] = p;
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}
	sz[u] = 1;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		sz[u]+=sz[nxt];
	}
	//cout << "! " << u << " " << sz[u] << "\n";
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(n,0);
	k = n-k;
	for(int i = n; i>=1; i--){
		if(psa[i]==0){
			int cur = i;
			for(int j = ln-1; j>=0; j--){
				int u = dp[cur][j];
				if(u>0&&psa[u]==0){
					cur = u;
				}
			}
			int v = lvl[i]-lvl[cur]+1;
			if(v>k)continue;
			//cout << i << " " << cur << " " << v << "\n";
			k-=v;
			cur = i;
			while(v--){
				psa[cur] = 1;
				cur = dp[cur][0];
			}
		}
	}
	for(int i = 1; i<=n; i++){
		if(!psa[i])cout << i << " ";
	}
	return 0;
}