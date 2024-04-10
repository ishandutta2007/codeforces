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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	for(auto &x: a){
		if(!x){
			x = -1;
		}
	}
	vector<int> dp(a);
	function<void(int, int)> dfs_subtr = [&](int u, int p){
		for(auto v: adj[u]){
			if(v != p){
				dfs_subtr(v, u);
				if(dp[v] > 0){
					dp[u] += dp[v];
				}
			}
		}
	};
	dfs_subtr(0, -1);
	function<void(int, int, int)> solve = [&](int u, int p, int x){
		if(x > 0){
			dp[u] += x;
		}
		for(auto v: adj[u]){
			if(v != p){
				solve(v, u, dp[u] - (dp[v] > 0 ? dp[v] : 0));
			}
		}
	};
	solve(0, -1, 0);
	copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, " "));
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////