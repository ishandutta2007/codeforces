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
	for(int u = 0; u < n; ++ u){
		int v;
		cin >> v;
		if(v){
			-- v;
			adj[u].push_back(v), adj[v].push_back(u);
			++ deg[u], ++ deg[v];
		}
	}
	if(n & 1){
		vector<int> res, ded(n);
		function<void(int, int)> solve = [&](int u, int p){
			for(auto v: adj[u]){
				if(v != p && !ded[v]){
					solve(v, u);
				}
			}
			function<void(int, int)> kill = [&](int u, int p){
				if(deg[u] % 2 == 0){
					ded[u] = true;
					res.push_back(u);
					for(auto v: adj[u]){
						if(!ded[v]){
							-- deg[v];
						}
					}
					for(auto v: adj[u]){
						if(v != p && !ded[v]){
							kill(v, u);
						}
					}
				}
			};
			kill(u, p);
		};
		solve(0, -1);
		if(int(res.size()) == n){
			cout << "YES\n";
			for(auto u: res){
				cout << u + 1 << "\n";
			}
		}
		else{
			cout << "NO";
		}
	}
	else{
		cout << "NO";
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