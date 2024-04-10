#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	vector<int> par(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<int> roots;
	vector<vector<int>> adj(n);
	for(auto i = 0; i < n; ++ i){
		cin >> par[i];
		if(~par[i]){
			-- par[i];
			adj[par[i]].push_back(i);
		}
		else{
			roots.push_back(i);
		}
	}
	vector<int> sz(n, 1), ord;
	long long res = 0;
	for(auto r: roots){
		function<void(int)> dfs = [&](int u){
			for(auto v: adj[u]){
				dfs(v);
				sz[u] += sz[v];
			}
			for(auto it = adj[u].begin(); it != partition(adj[u].begin(), adj[u].end(), [&](int u){ return a[u] >= 0; }); ++ it){
				a[u] += a[*it];
			}
			res += a[u];
		};
		dfs(r);
		function<void(int)> solve = [&](int u){
			int i = 0;
			for(; i < int(adj[u].size()) && a[adj[u][i]] >= 0; ++ i){
				solve(adj[u][i]);
			}
			ord.push_back(u);
			for(; i < int(adj[u].size()); ++ i){
				solve(adj[u][i]);
			}
		};
		solve(r);
	}
	cout << res << "\n";
	for(auto u: ord){
		cout << u + 1 << " ";
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