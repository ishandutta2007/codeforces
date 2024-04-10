#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> sz(n, 1), depth(n, 1);
	function<void(int, int)> dfs = [&](int u, int p){
		for(auto v: adj[u]){
			if(v != p){
				depth[v] = depth[u] + 1;
				dfs(v, u);
				sz[u] += sz[v];
			}
		}
	};
	dfs(0, -1);
	priority_queue<array<int, 3>> q;
	q.push({sz[0] - depth[0], 0, -1});
	long long res = 0;
	for(auto i = 0; i < n - k; ++ i){
		auto [d, u, p] = q.top();
		q.pop();
		res += d;
		for(auto v: adj[u]){
			if(v != p){
				q.push({sz[v] - depth[v], v, u});
			}
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////