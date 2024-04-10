#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, w;
	cin >> n >> m >> w;
	vector<int> weight(n), beauty(n);
	for(auto i = 0; i < n; ++ i){
		cin >> weight[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> beauty[i];
	}
	vector<vector<int>> adj(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> vis(n), gw, gb;
	vector<vector<int>> group;
	for(auto u = 0; u < n; ++ u){
		if(!vis[u]){
			group.emplace_back();
			gw.emplace_back();
			gb.emplace_back();
			function<void(int)> dfs = [&](int u){
				vis[u] = true;
				group.back().push_back(u);
				gw.back() += weight[u];
				gb.back() += beauty[u];
				for(auto v: adj[u]){
					if(!vis[v]){
						dfs(v);
					}
				}
			};
			dfs(u);
		}
	}
	int g = int(group.size());
	vector<vector<int>> dp(g + 1, vector<int>(w + 1)); // max beauty first i group weight equal or less than j
	for(auto i = 0; i < g; ++ i){
		for(auto j = 0; j <= w; ++ j){
			ctmax(dp[i + 1][j], dp[i][j]);
			if(j + gw[i] <= w){
				ctmax(dp[i + 1][j + gw[i]], dp[i][j] + gb[i]);
			}
			for(auto u: group[i]){
				if(j + weight[u] <= w){
					ctmax(dp[i + 1][j + weight[u]], dp[i][j] + beauty[u]);
				}
			}
		}
	}
	cout << dp[g][w] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////