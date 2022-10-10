#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> adj(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> par(n), depth(n, -1);
	function<void(int, int)> dfs = [&](int u, int p){
		par[u] = p;
		for(auto v: adj[u]){
			if(v != p){
				if(~depth[v] && depth[u] > depth[v]){
					if(depth[u] - depth[v] <= k - 1){
						cout << "2\n" << depth[u] - depth[v] + 1 << "\n";
						while(u != v){
							cout << u + 1 << " ";
							u = par[u];
						}
						cout << v + 1 << "\n";
						exit(0);
					}
				}
				else if(!~depth[v]){
					depth[v] = depth[u] + 1;
					dfs(v, u);
				}
			}
		}
	};
	depth[0] = 0;
	dfs(0, 0);
	for(auto u = 0; u < n; ++ u){
		if(depth[u] >= k - 1){
			int t = (k + 1) / 2, s = 1;
			cout << "1\n";
			while(t){
				if(s){
					cout << u + 1 << " ";
					-- t;
				}
				u = par[u];
				s = !s;
			}
			return 0;
		}
	}
	array<vector<int>, 2> cnt;
	for(auto u = 0; u < n; ++ u){
		cnt[depth[u] % 2].push_back(u);
	}
	int t = int(cnt[0].size()) <= int(cnt[1].size());
	cout << "1\n";
	for(auto i = 0; i < (k + 1) / 2; ++ i){
		cout << cnt[t][i] + 1 << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////