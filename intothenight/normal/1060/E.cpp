#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(auto i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> sz(n, 1);
	vector<long long> sum(n);
	array<int, 2> cnt{};
	long long res = 0;
	function<void(int, int, bool)> dfs = [&](int u, int p, bool t){
		++ cnt[t];
		for(auto v: adj[u]){
			if(v ^ p){
				dfs(v, u, !t);
				res += sum[u] * sz[v] + sz[u] * sum[v] + 1LL * sz[u] * sz[v];
				sz[u] += sz[v];
				sum[u] += sum[v] + sz[v];
			}
		}
	};
	dfs(0, -1, false);
	cout << (res + 1LL * cnt[0] * cnt[1]) / 2 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////