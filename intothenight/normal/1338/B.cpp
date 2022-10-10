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
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<int> deg(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
		++ deg[u], ++ deg[v];
	}
	int root = 0;
	while(deg[root] == 1){
		++ root;
	}
	vector<int> par(n), depth(n);
	function<void(int, int)> dfs = [&](int u, int p){
		par[u] = p;
		for(auto v: adj[u]){
			if(v != p){
				depth[v] = depth[u] + 1;
				dfs(v, u);
			}
		}
	};
	dfs(root, -1);
	vector<int> flag(2), check(n);
	int mx = n - 1;
	for(auto u = 0; u < n; ++ u){
		if(deg[u] == 1){
			flag[depth[u] % 2] = true;
			if(check[par[u]]){
				-- mx;
			}
			else{
				check[par[u]] = true;
			}
		}
	}
	if(flag[0] && flag[1]){
		cout << "3 " << mx;
	}
	else{
		cout << "1 " << mx;
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