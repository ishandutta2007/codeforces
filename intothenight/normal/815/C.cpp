#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, b;
	cin >> n >> b;
	vector<array<int, 2>> w(n);
	vector<vector<int>> adj(n);
	for(auto u = 0; u < n; ++ u){
		cin >> w[u][0] >> w[u][1], w[u][1] = w[u][0] - w[u][1];
		if(u){
			int p;
			cin >> p, -- p;
			adj[p].push_back(u);
		}
	}
	vector<vector<int>> use(n, vector<int>(n + 1, b + 1)); // min cost to buy at least
	vector<vector<int>> notuse(n, vector<int>(n + 1, b + 1));
	vector<int> sz(n, 1);
	function<void(int)> dfs = [&](int u){
		notuse[u][0] = 0;
		if(w[u][0] <= b){
			notuse[u][1] = w[u][0];
		}
		if(w[u][1] <= b){
			use[u][1] = w[u][1];
		}
		for(auto v: adj[u]){
			dfs(v);
			vector<int> use_next(n + 1, b + 1), notuse_next(n + 1, b + 1);
			for(auto i = 0; i <= sz[u]; ++ i){
				for(auto j = 0; j <= sz[v]; ++ j){
					ctmin(use_next[i + j], use[u][i] + min(use[v][j], notuse[v][j]));
					ctmin(notuse_next[i + j], notuse[u][i] + notuse[v][j]);
				}
			}
			swap(use[u], use_next), swap(notuse[u], notuse_next);
			sz[u] += sz[v];
		}
	};
	dfs(0);
	for(auto sz = n; sz >= 0; -- sz){
		if(use[0][sz] <= b || notuse[0][sz] <= b){
			cout << sz << "\n";
			return 0;
		}
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////