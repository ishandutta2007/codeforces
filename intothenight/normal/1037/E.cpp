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
	graph(int n): n(n), adj(n){ }
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
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
	int degree(int u){ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	set<pair<int, int>> s;
	vector<int> deg(n);
	for(auto u = 0; u < n; ++ u){
		s.insert({deg[u] = g.degree(u), u});
	}
	vector<int> res(m), cut(m);
	for(auto i = m - 1; i >= 0; -- i){
		while(!s.empty() && s.begin()->first < k){
			auto [ignore, u] = *s.begin(); s.erase(s.begin());
			for(auto id: g.adj[u]){
				if(!cut[id]){
					cut[id] = true;
					auto &e = g.edges[id];
					int v = u ^ e.from ^ e.to;
					s.erase({deg[v], v});
					s.insert({-- deg[v], v});
				}
			}
		}
		res[i] = (int)s.size();
		if(!cut[i]){
			cut[i] = true;
			auto [u, v, ignore] = g.edges[i];
			for(auto x: {u, v}){
				s.erase({deg[x], x});
				s.insert({-- deg[x], x});
			}
		}
	}
	for(auto x: res){
		cout << x << "\n";
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