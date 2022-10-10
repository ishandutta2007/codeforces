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
	int n, k;
	cin >> n >> k;
	graph<int> g(k);
	for(auto i = 0; i < k; ++ i){
		for(auto j = 0; j < k; ++ j){
			g.orient(i, j);
		}
	}
	auto temp = euler_walk(g, 0, k * k);
	assert(temp);
	auto epath = *temp;
	while((int)epath.size() < n){
		epath.insert(epath.end(), epath.begin(), epath.end());
	}
	auto vpath = edge_path_into_vertex_path(g, 0, epath);
	vpath.resize(n);
	for(auto u: vpath){
		cout << char('a' + u);
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