#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(int i = 1; i < n; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	array<int, 2> cnt{};
	function<void(int, int, int)> dfs = [&](int u, int p, int c){
		++ cnt[c];
		for(auto v: adj[u]){
			if(v != p){
				dfs(v, u, !c);
			}
		}
	};
	dfs(0, 0, 0);
	cout << min(cnt[0], cnt[1]) - 1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////