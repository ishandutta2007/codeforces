#include <bits/stdc++.h>
using namespace std;

template<class T>
struct graph{
	struct edge{
		int from, to;
		T cost;
	};
	int n;
	vector<edge> edges;
	vector<vector<int>> adj;
	function<bool(int)> ignore; // edge ignoration rule
	graph(int n): n(n), adj(n), ignore(nullptr){
	}
	int link(int u, int v, T w = 1){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = 1){ // insert a directed edge
		int id = (int)edges.size();
		adj[u].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		graph<int> g(n);
		for(auto i = 0; i < m; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			g.link(u, v);
		}
		vector<int> vis(n);
		int res = 0;
		for(auto u = 0; u < n; ++ u){
			if(!vis[u]){
				int cnt = 0, s = 0;
				function<void(int)> dfs = [&](int u){
					s += (int)g.adj[u].size();
					++ cnt;
					vis[u] = true;
					for(auto id: g.adj[u]){
						auto &e = g.edges[id];
						int v = u ^ e.from ^ e.to;
						if(!vis[v]){
							dfs(v);
						}
					}
				};
				dfs(u);
				if(cnt >= 2){
					if(s == cnt * 2){
						res += cnt + 1;
					}
					else{
						res += cnt - 1;
					}
				}
			}
		}
		cout << res << "\n";
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