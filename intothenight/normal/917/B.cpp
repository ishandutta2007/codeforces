#include <bits/stdc++.h>
using namespace std;

template<class Graph>
vector<int> toposort(const Graph &adj){
	int n = int(adj.size());
	vector<int> indeg(n), res;
	for(int u = 0; u < n; ++ u) for(auto [v, ignore]: adj[u]) ++ indeg[v];
	deque<int> q;
	for(int u = 0; u < n; ++ u) if (!indeg[u]) q.push_back(u);
	while(q.size() > 0){
		int u = q.front();
		q.pop_front();
		res.push_back(u);
		for(auto [v, ignore]: adj[u]) if (!(-- indeg[v])) q.push_back(v);
	}
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		char c;
		cin >> u >> v >> c, -- u, -- v;
		adj[u].push_back({v, c - 'a'});
	}
	auto order = toposort(adj);
	assert((int)order.size() == n);
	vector<string> res(n, string(n, 'B'));
	vector dp(n, vector(n, vector(26, -1)));
	function<int(int, int, int)> get_dp = [&](int u, int v, int c){
		if(~dp[u][v][c]){
			return dp[u][v][c];
		}
		for(auto [u_next, c_next]: adj[u]){
			if(c_next >= c && !get_dp(v, u_next, c_next)){
				return dp[u][v][c] = true;
			}
		}
		return dp[u][v][c] = false;
	};
	for(auto i = n - 1; i >= 0; -- i){
		int u = order[i];
		for(auto j = n - 1; j >= 0; -- j){
			int v = order[j];
			if(get_dp(u, v, 0)){
				res[u][v] = 'A';
			}
		}
	}
	for(auto s: res){
		cout << s << "\n";
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