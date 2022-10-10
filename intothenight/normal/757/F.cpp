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
template<class T>
struct dijkstra{
	int n;
	vector<T> dist;
	vector<int> pv, pe, was;
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
	// O(|E_C| log |V_C|) where
	// V_C is the set of vertices reachable from src and
	// E_C is the set of edges reachable from src
	template<class U>
	void run(const graph<U> &g, const vector<int> &src){
		assert(n == g.n);
		++ attempt;
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		for(auto u: src){
			was[u] = attempt;
			pq.push({dist[u] = {}, u});
			pv[u] = pe[u] = -1;
		}
		while(!pq.empty()){
			auto [d, u] = pq.top(); pq.pop();
			if(d != dist[u]) continue;
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(was[v] != attempt || dist[u] + e.cost < dist[v]){
					pq.push({dist[v] = dist[u] + e.cost, v});
					pv[v] = u, pe[v] = id, was[v] = attempt;
				}
			}
		}
	}
};

// Requries graph
template<class T>
vector<int> find_dominators(const graph<T> &g, int root){
	int n = g.n;
	vector<int> pos(n, -1), order, parent(n, -1);
	auto dfs = [&](auto dfs, int u)->void{
		pos[u] = (int)order.size();
		order.push_back(u);
		for(auto id : g.adj[u]){
			if(g.ignore != nullptr && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = e.to;
			if(!~pos[v]){
				parent[v] = u;
				dfs(dfs, v);
			}
		}
	};
	dfs(dfs, root);
	vector<int> p(n), best(n), sdom = pos;
	iota(p.begin(), p.end(), 0), iota(best.begin(), best.end(), 0);
	auto find_best = [&](auto find_best, int x)->int{
		if(p[x] != x){
			int u = find_best(find_best, p[x]);
			if(sdom[u] < sdom[best[x]]) best[x] = u;
			p[x] = p[p[x]];
		}
		if(sdom[best[p[x]]] < sdom[best[x]]) best[x] = best[p[x]];
		return best[x];
	};
	graph<int> g_rev = g.transposed();
	vector<int> idom(n, -1), link(n, -1);
	vector<vector<int>> bucket(n);
	for(auto it = (int)order.size() - 1; it >= 0; -- it){
		int w = order[it];
		for(auto id : g_rev.adj[w]){
			if(g_rev.ignore != nullptr && g_rev.ignore(id)) continue;
			auto &e = g_rev.edges[id];
			int u = e.to;
			if(~pos[u]) sdom[w] = min(sdom[w], sdom[find_best(find_best, u)]);
		}
		idom[w] = order[sdom[w]];
		for(auto u: bucket[w]) link[u] = find_best(find_best, u);
		for(auto id: g.adj[w]){
			if(g.ignore != nullptr && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int u = e.to;
			if(parent[u] == w) p[u] = w;
		}
		bucket[order[sdom[w]]].push_back(w);
	}
	for(auto it = 1; it < (int)order.size(); ++ it) idom[order[it]] = idom[link[order[it]]];
	return idom; // idom[i] -- immediate dominator for vertex i
}

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, root;
	cin >> n >> m >> root, -- root;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		g.link(u, v, w);
	}
	dijkstra<long long> D(n);
	D.run(g, {root});
	graph<int> abr(n);
	for(auto [u, v, w]: g.edges){
		for(auto rep = 0; rep < 2; ++ rep){
			if(D.was[u] == D.attempt && D.dist[u] + w == D.dist[v]){
				abr.orient(u, v);
			}
			swap(u, v);
		}
	}
	auto dom = find_dominators(abr, root);
	abr = {n};
	vector<int> cnt(n);
	for(auto u = 0; u < n; ++ u){
		if(~dom[u]){
			if(u == dom[u]){
				root = u;
			}
			else{
				abr.orient(dom[u], u);
				++ cnt[u];
			}
		}
	}
	y_combinator([&](auto self, int u, int pe)->void{
		for(auto id: abr.adj[u]){
			if(id == pe || abr.ignore && abr.ignore(id)) continue;
			auto &e = abr.edges[id];
			int v = u ^ e.from ^ e.to;
			self(v, id);
			cnt[u] += cnt[v];
		}
	})(root, -1);
	cnt[root] = 0;
	cout << *max_element(cnt.begin(), cnt.end()) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////