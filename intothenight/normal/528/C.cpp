#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

pair<vector<int>, vector<int>> euler_walk(const vector<vector<pair<int, int>>> &adj, int m, int source = 0){
	int n = int(adj.size());
	vector<int> deg(n), its(n), used(m), res_v, res_e;
	vector<pair<int, int>> q = {{source, -1}};
	++ deg[source]; // to allow Euler paths, not just cycles
	while(!q.empty()){
		auto [u, e] = q.back();
		int &it = its[u], end = int(adj[u].size());
		if(it == end){ res_v.push_back(u); res_e.push_back(e); q.pop_back(); continue; }
		auto [v, f] = adj[u][it ++];
		if(!used[f]){
			-- deg[u], ++ deg[v];
			used[f] = 1; q.emplace_back(v, f);
		}
	}
	for(auto d: deg) if(d < 0 || int(res_v.size()) != m + 1) return {};
	return {{res_v.rbegin(), res_v.rend()}, {res_e.rbegin() + 1, res_e.rend()}};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	vector<pair<int, int>> edge(m);
	vector<int> deg(n);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		edge[i] = {u, v};
		++ deg[u], ++ deg[v];
		adj[u].push_back({v, i}), adj[v].push_back({u, i});
	}
	vector<int> incomp;
	for(int u = 0; u < n; ++ u){
		if(deg[u] & 1){
			incomp.push_back(u);
		}
	}
	for(int i = 1; i < incomp.size(); i += 2){
		int u = incomp[i - 1], v = incomp[i];
		adj[u].push_back({v, m}), adj[v].push_back({u, m});
		edge.push_back({u, v});
		++ deg[u], ++ deg[v];
		++ m;
	}
	if(m & 1){
		adj[0].push_back({0, m}), adj[0].push_back({0, m});
		edge.push_back({0, 0});
		deg[0] += 2;
		++ m;
	}
	auto [V, E] = euler_walk(adj, m);
	cout << m << "\n";
	for(int i = 1; i <= m; ++ i){
		int u = V[i - 1], v = V[i];
		i & 1 ? cout << u + 1 << " " << v + 1 << "\n" : cout << v + 1 << " " << u + 1 << "\n";
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