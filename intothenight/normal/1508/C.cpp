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

// Requires graph and disjoint_set
template<class T>
vector<int> minimum_spanning_forest(const graph<T> &g){
	vector<int> order((int)g.edges.size());
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j){ return g.edges[i].cost < g.edges[j].cost; });
	disjoint_set dsu(g.n);
	vector<int> res;
	for(auto id: order){
		if(g.ignore && g.ignore(id)) continue;
		auto &e = g.edges[id];
		if(dsu.merge(e.from, e.to)) res.push_back(id);
	}
	return res;
}

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class T>
vector<array<int, 2>> complement_spanning_forest(const graph<T> &g){
	int n = g.n;
	auto adj = g.get_adjacency_list();
	for(auto &a: adj) sort(a.begin(), a.end());
	set<int> alive;
	for(auto u = 0; u < n; ++ u) alive.insert(u);
	vector<array<int, 2>> res;
	while(!alive.empty()){
		int u = *alive.begin(); alive.erase(alive.begin());
		deque<int> dq{u};
		while(!dq.empty()){
			int v = dq.front(); dq.pop_front();
			for(auto it = alive.begin(); it != alive.end(); ){
				if(auto it2 = lower_bound(adj[v].begin(), adj[v].end(), *it); it2 != adj[u].end() && *it2 == *it) ++ it;
				else dq.push_back(*it), res.push_back({u, *it}), it = alive.erase(it);
			}
		}
	}
	return res;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n);
	int xorsum = 0;
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		g.link(u, v, w);
		xorsum ^= w;
	}
	if(1LL * n * (n - 1) / 2 - m >= n){
		disjoint_set dsu(n);
		for(auto [u, v]: complement_spanning_forest(g)){
			dsu.merge(u, v);
		}
		long long res = 0;
		vector<int> id(m);
		iota(id.begin(), id.end(), 0);
		sort(id.begin(), id.end(), [&](int i, int j){ return g.edges[i].cost < g.edges[j].cost; });
		for(auto i: id){
			auto [u, v, w] = g.edges[i];
			if(dsu.merge(u, v)){
				res += w;
			}
		}
		cout << res << "\n";
		return 0;
	}
	vector<vector<int>> adjm(n, vector<int>(n));
	vector<vector<int>> id(n, vector<int>(n, -1));
	for(auto i = 0; i < m; ++ i){
		auto [u, v, w] = g.edges[i];
		adjm[u][v] = adjm[v][u] = w;
		id[u][v] = id[v][u] = i;
	}
	for(auto u = 0; u < n; ++ u){
		for(auto v = u + 1; v < n; ++ v){
			if(!adjm[u][v]){
				id[u][v] = id[v][u] = g.link(u, v);
			}
		}
	}
	m = (int)g.edges.size();
	auto f_e = minimum_spanning_forest(g);
	vector<int> used(m);
	long long res = 0;
	for(auto i: f_e){
		used[i] = true;
		res += g.edges[i].cost;
	}
	for(auto u = 0; u < n; ++ u){
		for(auto v = u + 1; v < n; ++ v){
			if(!adjm[u][v] && !used[id[u][v]]){
				cout << res << "\n";
				return 0;
			}
		}
	}
	vector<vector<array<int, 2>>> fadj(n);
	for(auto i: f_e){
		auto [u, v, w] = g.edges[i];
		fadj[u].push_back({v, w}), fadj[v].push_back({u, w});
	}
	int delta = numeric_limits<int>::max();
	for(auto i: f_e){
		auto [u, v, w] = g.edges[i];
		if(!w){
			vector<int> side(n);
			auto dfs = [&](auto dfs, int u, int p)->void{
				side[u] = true;
				for(auto [v, w]: fadj[u]){
					if(v != p){
						dfs(dfs, v, u);
					}
				}
			};
			dfs(dfs, u, v);
			for(auto i = 0; i < m; ++ i){
				auto [u, v, w] = g.edges[i];
				if(w && side[u] != side[v]){
					ctmin(delta, w);
				}
			}
		}
	}
	cout << res + min(xorsum, delta) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////