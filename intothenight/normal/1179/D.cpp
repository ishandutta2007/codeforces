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
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	const long long inf = numeric_limits<long long>::max() / 3;
	long long res = inf;
	auto cal = [&](int x){
		return 1LL * x * (x - 1) / 2;
	};
	vector<int> sz(n, 1);
	function<void(int, int)> dfs_sz = [&](int u, int p){
		for(auto v: adj[u]){
			if(v != p){
				dfs_sz(v, u);
				sz[u] += sz[v];
			}
		}
	};
	dfs_sz(0, -1);
	vector<pair<long long, int>> dp(n, {inf, inf});
	function<void(int, int)> solve = [&](int u, int p){
		int cnt = 0;
		for(auto v: adj[u]){
			if(v != p){
				solve(v, u);
				if(cnt){
					// update res
					int w = dp[u].second;
					ctmin(res, dp[u].first - cal(sz[u] - sz[w]) + dp[v].first + cal(n - sz[v] - sz[w]));
				}
				// update dp
				ctmin(dp[u], {dp[v].first + cal(sz[u] - sz[v]), v});
				++ cnt;
			}
		}
		if(!cnt){
			dp[u] = {0, 0};
		}
	};
	solve(0, -1);
	cout << cal(n) * 2 - min(res, dp[0].first);
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////