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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> visited(n), prev(n, -1);
	vector<pair<int, int>> cent; // Node, radius
	auto bfs = [&](int s){ // returns endpoint, dist
		deque<array<int, 3>> q{array<int, 3>{0, s, -1}};
		pair<int, int> res;
		while(!q.empty()){
			auto [dist, u, p] = q.front();
			q.pop_front();
			res = {u, dist};
			prev[u] = p;
			visited[u] = true;
			for(auto v: adj[u]){
				if(v != p){
					q.push_back({dist + 1, v, u});
				}
			}
		}
		return res;
	};
	for(int s = 0; s < n; ++ s){
		if(!visited[s]){
			auto [u, d] = bfs(bfs(s).first);
			vector<int> path;
			while(u != -1){
				path.push_back(u);
				u = prev[u];
			}
			cent.emplace_back(path[int(path.size()) / 2], d / 2);
		}
	}
	auto recover = adj;
	pair<int, vector<pair<int, int>>> res{numeric_limits<int>::max(), 0};
	for(int i = 0; i < int(cent.size()); ++ i){
		auto [u, ru] = cent[i];
		vector<pair<int, int>> temp;
		for(int j = 0; j < int(cent.size()); ++ j){
			if(i != j){
				auto [v, rv] = cent[j];
				adj[u].push_back(v);
				adj[v].push_back(u);
				temp.emplace_back(u + 1, v + 1);
			}
		}
		ctmin(res, {bfs(bfs(0).first).second, temp});
		adj = recover;
	}
	cout << res.first << "\n";
	for(auto [u, v]: res.second){
		cout << u << " " << v << "\n";
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