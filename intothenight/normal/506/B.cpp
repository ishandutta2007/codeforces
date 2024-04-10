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

// Requires graph
template<class T> // O(V + E)
void strongly_connected_components(const graph<T> &g, auto act_comp){
	int n = g.n, it = 0, ncomps = 0, v;
	vector<int> val(n), comp(n, -1), s, cur;
	auto dfs = [&](auto self, int u)->int{
		int low = val[u] = ++ it;
		s.push_back(u);
		for(auto id: g.adj[u]){
			if(g.ignore && g.ignore(id)) continue;
			int v = u ^ g.edges[id].from ^ g.edges[id].to;
			if(comp[v] < 0) low = min(low, val[v] ?: self(self, v));
		}
		if(low == val[u]){
			do{
				v = s.back(); s.pop_back();
				comp[v] = ncomps;
				cur.push_back(v);
			}while(v != u);
			act_comp(cur); // Process the component
			cur.clear();
			++ ncomps;
		}
		return val[u] = low;
	};
	for(auto u = 0; u < n; ++ u) if(comp[u] < 0) dfs(dfs, u);
} // accesses sccs in the reverse topological order

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int size(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g((int)p.size());
		for(auto i = 0; i < (int)p.size(); ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n);
	disjoint_set dsu(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.orient(u, v);
		dsu.merge(u, v);
	}
	vector<int> id(n);
	vector<vector<int>> C;
	auto act = [&](auto c)->void{
		for(auto u: c){
			id[u] = (int)C.size();
		}
		C.push_back(c);
	};
	strongly_connected_components(g, act);
	int res = 0;
	for(auto a: dsu.group_up()){
		vector<int> comps;
		for(auto u: a){
			comps.push_back(id[u]);
		}
		sort(comps.begin(), comps.end());
		comps.erase(unique(comps.begin(), comps.end()), comps.end());
		res += (int)a.size() - 1;
		if(any_of(comps.begin(), comps.end(), [&](int i){ return (int)C[i].size() >= 2; })){
			++ res;
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////