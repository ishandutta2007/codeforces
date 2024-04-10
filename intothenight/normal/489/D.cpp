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



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n), radj(n), cnt(n, vector<int>(n)), rcnt(cnt), adjL(n, vector<int>(n));
	for(int i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v);
		radj[v].push_back(u);
		adjL[u][v] = true;
	}
	long long res = 0;
	for(int t = 0; t < n; ++ t){
		for(int i = 0; i < int(adj[t].size()); ++ i){
			for(int j = i + 1; j < int(adj[t].size()); ++ j){
				++ cnt[adj[t][i]][adj[t][j]];
			}
		}
		for(int i = 0; i < int(radj[t].size()); ++ i){
			for(int j = i + 1; j < int(radj[t].size()); ++ j){
				++ rcnt[radj[t][i]][radj[t][j]];
				if(adjL[t][radj[t][i]] && adjL[t][radj[t][j]]){
					-- res;
				}
			}
		}
	}
	for(int u = 0; u < n; ++ u){
		for(int v = u + 1; v < n; ++ v){
			res += 1LL * (cnt[u][v] + cnt[v][u]) * (rcnt[u][v] + rcnt[v][u]);
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