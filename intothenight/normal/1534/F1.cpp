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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	graph<int> g(n * m);
	int res = 0;
	static const vector<pair<int, int>> dr{{0, 1}, {0, -1}};
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(a[i][j] == '#'){
				if(i && a[i - 1][j] == '#'){
					g.orient(i * m + j, (i - 1) * m + j);
				}
				int k = i;
				while(k < n && (k == i || a[k][j] == '.')){
					for(auto [dk, dj]: dr){
						int nk = k + dk, nj = j + dj;
						if(0 <= nk && nk < n && 0 <= nj && nj < m && a[nk][nj] == '#'){
							g.orient(i * m + j, nk * m + nj);
						}
					}
					++ k;
				}
				if(k < n){
					g.orient(i * m + j, k * m + j);
				}
			}
			else{
				-- res;
			}
		}
	}
	vector<vector<int>> comp;
	vector<int> id(n * m);
	auto act = [&](vector<int> c)->void{
		for(auto u: c){
			id[u] = (int)comp.size();
		}
		comp.push_back(c);
	};
	strongly_connected_components(g, act);
	vector<int> deg((int)comp.size());
	for(auto [u, v, w]: g.edges){
		if(id[u] != id[v]){
			++ deg[id[v]];
		}
	}
	for(auto i = 0; i < (int)comp.size(); ++ i){
		if(!deg[i]){
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