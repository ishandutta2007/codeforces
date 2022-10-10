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
	vector<int> deg(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
		++ deg[u], ++ deg[v];
	}
	vector<int> ded(n), leg(n);
	function<void(int, int)> dfs = [&](int u, int p){
		ded[u] = true;
		for(auto v: adj[u]){
			if(v != p){
				if(deg[v] < 3){
					dfs(v, u);	
				}
				else{
					++ leg[v];
				}
			}
		}
	};
	for(int u = 0; u < n; ++ u){
		if(deg[u] == 1){
			dfs(u, -1);
		}
	}
	for(int u = 0; u < n; ++ u){
		if(!ded[u]){
			int cnt = 0;
			for(auto v: adj[u]){
				if(!ded[v] && deg[v] - min(leg[v], 2) > 1){
					++ cnt;
				}
			}
			if(cnt > 2){
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////