#include "bits/stdc++.h"
using namespace std;

template<typename Graph>
vector<int> toposort(const Graph &adj){
	int n = int(adj.size());
	vector<int> indeg(n), res;
	for(int u = 0; u < n; ++ u) for(auto v: adj[u]) ++ indeg[v];
	deque<int> q;
	for(int u = 0; u < n; ++ u) if (!indeg[u]) q.push_back(u);
	while(q.size() > 0){
		int u = q.front();
		q.pop_front();
		res.push_back(u);
		for(auto v: adj[u]) if (!(-- indeg[v])) q.push_back(v);
	}
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n);
		vector<array<int, 2>> dir, udir;
		for(auto i = 0; i < m; ++ i){
			int t, u, v;
			cin >> t >> u >> v, -- u, -- v;
			if(t){
				adj[u].push_back(v);
				dir.push_back({u, v});
			}
			else{
				udir.push_back({u, v});
			}
		}
		auto t = toposort(adj);
		if(int(t.size()) < n){
			cout << "NO\n";
		}
		else{
			vector<int> pos(n);
			for(auto i = 0; i < n; ++ i){
				pos[t[i]] = i;
			}
			cout << "YES\n";
			for(auto [u, v]: dir){
				cout << u + 1 << " " << v + 1 << "\n";
			}
			for(auto [u, v]: udir){
				if(pos[u] > pos[v]){
					swap(u, v);
				}
				cout << u + 1 << " " << v + 1 << "\n";
			}
		}
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
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