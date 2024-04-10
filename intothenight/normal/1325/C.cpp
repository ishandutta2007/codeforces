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
	vector<pair<int, int>> edge(n - 1);
	vector<vector<pair<int, int>>> adj(n);
	vector<int> deg(n);
	for(int i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
		edge[i] = {u, v};
		++ deg[u], ++ deg[v];
	}
	for(int u = 0; u < n; ++ u){
		if(deg[u] >= 3){
			vector<int> res(n - 1, -1);
			for(int i = 0; i < 3; ++ i){
				res[adj[u][i].second] = i;
			}
			for(int i = 0; i < n - 1; ++ i){
				static int cnt = 3;
				if(res[i] == -1){
					res[i] = cnt ++;
				}
			}
			copy(res.begin(), res.end(), ostream_iterator<int>(cout, "\n"));
			return 0;
		}
	}
	for(int i = 0; i < n - 1; ++ i){
		cout << i << "\n";
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