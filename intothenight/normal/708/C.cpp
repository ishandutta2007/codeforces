#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> centroid(const vector<vector<int>> &adj){
	int n = int(adj.size());
	vector<int> sz(n, 1);
	function<void(int, int)> dfs_sz = [&](int u, int p){
		for(auto v: adj[u]) if(v != p){
			dfs_sz(v, u);
			sz[u] += sz[v];
		}
	};
	dfs_sz(0, -1);
	function<vector<int>(int, int)> dfs_cent = [&](int u, int p){
		for(auto v: adj[u]) if(v != p && sz[v] > n / 2) return dfs_cent(v, u);
		for(auto v: adj[u]) if(v != p && n - sz[v] <= n / 2) return vector<int>{u, v};
		return vector<int>{u};
	};
	return dfs_cent(0, -1);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> cent = centroid(adj), sz(n, 1), res(n);
	if(int(cent.size()) == 2){
		for(int i = 0; i < n; ++ i){
			cout << "1 ";
		}
		return 0;
	}
	int c = cent[0];
	res[c] = true;
	function<void(int, int)> dfs = [&](int u, int p){
		for(auto v: adj[u]){
			if(v != p){
				dfs(v, u);
				sz[u] += sz[v];
			}
		}
	};
	dfs(c, -1);
	sort(adj[c].begin(), adj[c].end(), [&](int u, int v){ return sz[u] < sz[v]; });
	for(int i = 0; i < int(adj[c].size()); ++ i){
		int t = i == int(adj[c].size()) - 1 ? adj[c][int(adj[c].size()) - 2] : adj[c].back();
		function<void(int, int)> solve = [&](int u, int p){
			if(n - sz[u] - sz[t] <= n / 2){
				res[u] = true;
				for(auto v: adj[u]){
					if(v != p){
						solve(v, u);
					}
				}
			}
		};
		solve(adj[c][i], c);
	}
	copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////