#include <bits/stdc++.h>
using namespace std;

// O(V + E sqrt(E)) for graphs without loops or multiedges
void find_4_cycles(int n, const vector<array<int, 2>> &init_edges, auto process, int th = 1){
	vector<int> deg(n), order(n), pos(n);
	for(auto [u, v]: init_edges) ++ deg[u], ++ deg[v];
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int u, int v){ return deg[u] > deg[v]; });
	for(auto i = 0; i < n; ++ i) pos[order[i]] = i; // reorder for cache
	vector<vector<int>> adj(n);
	vector<array<int, 2>> edges(init_edges.size());
	for(auto i = 0; i < (int)edges.size(); ++ i){
		int u = pos[init_edges[i][0]], v = pos[init_edges[i][1]];
		edges[i] = {u, v}, adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<vector<int>> found(n);
	for(auto u = 0; u < n; ++ u){
		for(auto v: adj[u]) if(u < v) for(auto w: adj[v]) if(u < w) found[w].clear();
		for(auto v: adj[u]) if(u < v) for(auto w: adj[v]) if(u < w){
			for(auto x: found[w]){
				if(!(th --)) return;
				process(order[u], order[v], order[w], order[x]);
			}
			found[w].push_back(v);
		}
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> X;
		vector<array<int, 2>> edges;
		for(auto i = 0; i < n; ++ i){
			int k;
			cin >> k;
			for(auto j = 0; j < k; ++ j){
				int x;
				cin >> x;
				X.push_back(x);
				edges.push_back({i, x});
			}
		}
		sort(X.begin(), X.end()), X.erase(unique(X.begin(), X.end()), X.end());
		int m = (int)X.size();
		for(auto &[u, v]: edges){
			v = lower_bound(X.begin(), X.end(), v) - X.begin() + n;
		}
		bool found = false;
		auto process = [&](int u, int v, int w, int x){
			if(u < n) cout << u + 1 << " ";
			if(v < n) cout << v + 1 << " ";
			if(w < n) cout << w + 1 << " ";
			if(x < n) cout << x + 1 << " ";
			found = true;
		};
		find_4_cycles(n + m, edges, process, 1);
		if(!found){
			cout << "-1";
		}
		cout << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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