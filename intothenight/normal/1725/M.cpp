#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct graph{
	struct E{
		int from, to;
		T cost;
	};
	int n;
	vector<E> edge;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n = 0): n(n), adj(n){ }
	graph(const vector<vector<int>> &adj, bool undirected = true): n(n){
		if(undirected) for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) if(u < v) link(u, v);
		else for(auto u = 0; u < n; ++ u) for(auto v: adj[u]) orient(u, v);
	}
	graph(const vector<vector<pair<int, T>>> &adj, bool undirected = true): n(n){
		if(undirected) for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) if(u < v) link(u, v, w);
		else for(auto u = 0; u < n; ++ u) for(auto [v, w]: adj[u]) orient(u, v, w);
	}
	graph(int n, vector<array<int, 2>> &edge, bool undirected = true): n(n){
		for(auto [u, v]: edge) undirected ? link(u, v) : orient(u, v);
	}
	graph(int n, vector<tuple<int, int, T>> &edge, bool undirected = true): n(n){
		for(auto [u, v, w]: edge) undirected ? link(u, v, w) : orient(u, v, w);
	}
	int operator()(int u, int id) const{
		#ifdef LOCAL
		assert(0 <= id && id < (int)edge.size());
		assert(edge[id].from == u || edge[id].to == u);
		#endif
		return u ^ edge[id].from ^ edge[id].to;
	}
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edge.size();
		adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edge.size();
		adj[u].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edge) res.orient(e.to, e.from, e.cost);
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
			auto &e = edge[id];
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
	friend ostream &operator<<(ostream &out, const graph &g){
		for(auto id = 0; id < (int)g.edge.size(); ++ id){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			out << "{" << e.from << ", " << e.to << ", " << e.cost << "}\n";
		}
		return out;
	}
};

template<class T>
struct dijkstra{
	int n;
	vector<T> dist;
	vector<int> pv, pe, was, order;
	dijkstra(int n){ init(n); }
	void init(int n){
		this->n = n;
		dist.assign(n, numeric_limits<T>::max());
		pv.assign(n, -1);
		pe.assign(n, -1);
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
	// O((|V| + |E|) * log |V|) where
	// V is the set of vertices reachable from src and
	// E is the set of edges reachable from src
	// Requires graph
	template<class Graph>
	void run(const Graph &g, const vector<int> &src){
		assert(n == g.n);
		++ attempt;
		for(auto u: src){
			was[u] = attempt;
			pq.push({dist[u] = {}, u});
			pv[u] = -1;
			pe[u] = -1;
		}
		order.clear();
		while(!pq.empty()){
			T d;
			int u;
			tie(d, u) = pq.top();
			pq.pop();
			if(d != dist[u]) continue;
			order.push_back(u);
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				if(was[v] != attempt || dist[u] + e.cost < dist[v]){
					pq.push({dist[v] = dist[u] + e.cost, v});
					pv[v] = u, pe[v] = id, was[v] = attempt;
				}
			}
		}
	}
	// The graph is represented implicitly
	// get_deg(u) returns the degree of u
	// get_adj(u, i) returns a pair of the i-th neighbor of u, possibly -1 representing an invalid node, and the weight of the edge joining them
	// O((|V| + |E|) * log |V|) where
	// V is the set of vertices reachable from src and
	// E is the set of edges reachable from src
	void run_implicitly(auto get_deg, auto get_adj, const vector<int> &src){
		++ attempt;
		for(auto u: src){
			was[u] = attempt;
			pq.push({dist[u] = {}, u});
			pv[u] = -1;
			pe[u] = -1;
		}
		order.clear();
		while(!pq.empty()){
			auto [d, u] = pq.top();
			pq.pop();
			if(d != dist[u]) continue;
			order.push_back(u);
			for(auto i = 0, deg = get_deg(u); i < deg; ++ i){
				auto [v, w] = get_adj(u, i);
				if(!~v) continue;
				if(was[v] != attempt || d + w < dist[v]){
					pq.push({dist[v] = d + w, v});
					pv[v] = u, pe[v] = i, was[v] = attempt;
				}
			}
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n << 1);
	for(auto u = 0; u < n; ++ u){
		g.orient(u, u + n, 0);
	}
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		g.orient(u, v, w);
		g.orient(v + n, u + n, w);
	}
	dijkstra<long long> D(n << 1);
	D.run(g, {0});
	for(auto u = 1; u < n; ++ u){
		long long res = numeric_limits<long long>::max();
		for(auto v = u; v < n << 1; v += n){
			if(D.was[v] == D.attempt){
				res = min(res, D.dist[v]);
			}
		}
		if(res == numeric_limits<long long>::max()){
			res = -1;
		}
		cout << res << " ";
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