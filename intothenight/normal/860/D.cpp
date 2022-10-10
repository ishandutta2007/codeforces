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
	function<bool(int)> ignore;
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edges.size();
		adj[u].push_back(id), adj[v].push_back(id), edges.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
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
	int degree(int u) const{ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	vector<vector<int>> get_adjacency_list() const{
		vector<vector<int>> res(n);
		for(auto u = 0; u < n; ++ u) for(auto id: adj[u]){
			if(ignore && ignore(id)) continue;
			auto &e = edges[id];
			int v = u ^ e.from ^ e.to;
			res[u].push_back(v);
		}
		return res;
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
};

template<class T>
void decompose_into_paths_of_length_2(const graph<T> &g, auto process_p3, auto process_edge){
	int n = g.n;
	vector<int> depth(n, -1);
	auto recurse = [&](auto self, int u, int pe)->bool{
		int rem = -1;
		for(auto id: g.adj[u]){
			if(id == pe || g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			if(~depth[v] && depth[u] > depth[v] || !~depth[v] && (depth[v] = depth[u] + 1, self(self, v, id))){
				if(~rem) process_p3(rem, u, id), rem = -1;
				else rem = id;
			}
		}
		if(!~rem) return true;
		~pe ? process_p3(pe, u, rem) : process_edge(rem);
		return false;
	};
	for(auto u = 0; u < n; ++ u) if(!~depth[u]) depth[u] = 0, recurse(recurse, u, -1);
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	vector<array<int, 3>> res;
	auto process = [&](int i, int u, int j)->void{
		auto &e = g.edges[i], &f = g.edges[j];
		int v = u ^ e.from ^ e.to, w = u ^ f.from ^ f.to;
		res.push_back({v, u, w});
	};
	decompose_into_paths_of_length_2(g, process, [&](int){  });
	cout << (int)res.size() << "\n";
	for(auto [u, v, w]: res){
		cout << u + 1 << " " << v + 1 << " " << w + 1 << "\n";
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