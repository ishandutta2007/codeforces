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
	int degree(int u){ // the degree (outdegree if directed) of u (without the ignoration rule)
		return (int)adj[u].size();
	}
	void set_ignoration_rule(const function<bool(int)> &f){
		ignore = f;
	}
	void reset_ignoration_rule(){
		ignore = nullptr;
	}
};

// returns an euler walk starting at s given that there are edge_cnt edges reachable from s
// Returns the edge list
// O(|V|+|E|)
template<class T>
optional<vector<int>> euler_walk(const graph<T> &g, int s, int edge_cnt){
	if(!edge_cnt) return {{}};
	int n = g.n, m = (int)g.edges.size();
	vector<int> deg(n), its(n), used(m), res_e;
	vector<array<int, 2>> st = {{s, -1}};
	++ deg[s]; // to allow Euler paths, not just cycles
	while(!st.empty()){
		auto [u, id] = st.back();
		int &it = its[u], end = (int)g.adj[u].size();
		if(g.ignore) while(it < end && g.ignore(g.adj[u][it])) ++ it;
		if(it == end){
			res_e.push_back(id), st.pop_back();
			continue;
		}
		int id_next = g.adj[u][it ++];
		if(!used[id_next]){
			auto &e = g.edges[id_next];
			int v = u ^ e.from ^ e.to;
			-- deg[u], ++ deg[v];
			used[id_next] = 1, st.push_back({v, id_next});
		}
	}
	for(auto d: deg) if(d < 0 || (int)res_e.size() != edge_cnt + 1) return {};
	return {{res_e.rbegin() + 1, res_e.rend()}};
}

// Requires graph
template<class T>
vector<int> edge_path_into_vertex_path(const graph<T> &g, int s, const vector<int> &edge_path){
	vector<int> vertex_path{s};
	for(auto id: edge_path){
		auto &e = g.edges[id];
		assert(e.from == vertex_path.back() || e.to == vertex_path.back());
		vertex_path.push_back(vertex_path.back() ^ e.from ^ e.to);
	}
	return vertex_path;
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
	for(auto u = 0; u < n; ++ u){
		if(auto path_p = euler_walk(g, u, m)){
			auto path = edge_path_into_vertex_path(g, u, *path_p);
			cout << (int)path.size() << "\n";
			for(auto u: path){
				cout << u + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	auto test = [&](int root)->optional<vector<int>>{
		vector<bool> bad(m);
		g.set_ignoration_rule([&](int id){ return bad[id]; });
		int ecnt = m;
		for(auto id: g.adj[root]){
			auto &e = g.edges[id];
			int u = root ^ e.from ^ e.to;
			if(g.degree(u) & 1){
				bad[id] = true;
				-- ecnt;
			}
		}
		if(auto path_p = euler_walk(g, root, ecnt)){
			auto path = edge_path_into_vertex_path(g, root, *path_p);
			reverse(path.begin(), path.end());
			path.push_back(-2);
			for(auto id: g.adj[root]){
				auto &e = g.edges[id];
				int u = root ^ e.from ^ e.to;
				if(bad[id]){
					path.push_back(u);
					path.push_back(root);
				}
			}
			return path;
		}
		++ ecnt;
		for(auto id: g.adj[root]){
			auto &e = g.edges[id];
			int u = root ^ e.from ^ e.to;
			if(g.degree(u) & 1){
				bad[id] = false;
				if(auto path_p = euler_walk(g, root, ecnt)){
					auto path = edge_path_into_vertex_path(g, root, *path_p);
					reverse(path.begin(), path.end());
					path.push_back(-2);
					for(auto id: g.adj[root]){
						auto &e = g.edges[id];
						int u = root ^ e.from ^ e.to;
						if(bad[id]){
							path.push_back(u);
							path.push_back(root);
						}
					}
					return path;
				}
				bad[id] = true;
			}
		}
		return {};
	};
	for(auto u = 0; u < n; ++ u){
		if(auto op = test(u)){
			cout << (int)op->size() << "\n";
			for(auto x: *op){
				cout << x + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////