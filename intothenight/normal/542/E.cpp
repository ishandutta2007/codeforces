#include <bits/stdc++.h>
using namespace std;

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
};

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
	graph reversed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges){
			res.orient(e.to, e.from, e.cost);
		}
		return res;
	}
};

// Requires graph
template<class T>
struct shortest_path_tree{
	shortest_path_tree(T inf = numeric_limits<T>::max() / 3, T minf = numeric_limits<T>::min() / 3): inf(inf), minf(minf){ }
	void init(const graph<T> &g, const vector<int> &src = {0}){
		int n = g.n;
		if((int)dist.size() != n) dist.assign(n, inf), pv.assign(n, -1), pe.assign(n, -1);
		else{
			function<void(int)> dfs = [&](int u){
				dist[u] = inf, pv[u] = pe[u] = -1;
				for(auto id: g.adj[u]){
					if(g.ignore && g.ignore(id)) continue;
					auto &e = g.edges[id];
					int v = u ^ e.from ^ e.to;
					if(dist[v] != inf) dfs(v);
				}
			};
			for(auto s: src) dfs(s);
		}
	}
	int init_bfs(const graph<T> &g, const vector<int> &src = {0}){ // returns max dist
		init(g, src);
		deque<int> dq;
		for(auto s: src){
			dist[s] = {};
			dq.push_back(s);
		}
		T max_dist = minf;
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(dist[v] == inf){
					max_dist = dist[v] = dist[u] + 1;
					pv[v] = u, pe[v] = id;
					dq.push_back(v);
				}
			}
		}
		return max_dist;
	}
	void init_dijkstra(const graph<T> &g, const vector<int> &src = {0}){
		init(g, src);
		priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
		for(auto s: src) pq.push({dist[s] = {}, s});
		while(!pq.empty()){
			auto [d, u] = pq.top(); pq.pop();
			if(d != dist[u]) continue;
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				if(dist[u] + e.cost < dist[v]){
					pq.push({dist[v] = dist[u] + e.cost, v});
					pv[v] = u, pe[v] = id;
				}
			}
		}
	}
	// To find any negative cycle, put every vertices into src
	vector<int> init_bellman_ford(const graph<T> &g, const vector<int> &src = {0}){ // return edge ids of a negative cycle, {} if none exists
		init(g, src); // For undirected graph, call graph::orient twice instead of graph::link
		for(auto s: src) dist[s] = {};
		int x;
		for(int rep = 0; rep < g.n; ++ rep){
			x = -1;
			for(int id = 0; id < (int)g.edges.size(); ++ id){
				if(g.ignore && g.ignore(id)) continue;
				auto [u, v, w] = g.edges[id];
				if(dist[u] < inf && dist[u] + w < dist[v]){
					dist[v] = minf < dist[u] + w ? dist[u] + w : minf;
					pv[v] = u, pe[v] = id;
					x = v;
				}
			}
		}
		if(x == -1) return {};
		else{
			for(int i = 0; i < g.n; ++ i) x = pv[x];
			vector<int> cycle;
			for(int u = x; u != x || cycle.empty(); u = g->edges[pe[u]].from) cycle.push_back(pe[u]);
			return {cycle.rbegin(), cycle.rend()};
		}
	}
	bool init_spfa(const graph<T> &g, const vector<int> &src = {0}){ // returns false if negative cycle
		init(g.n);
		vector<int> cnt(g.n);
		vector<bool> inq(g.n);
		deque<int> dq;
		for(auto s: src) dist[s] = {}, dq.push_back(s), inq[s] = true;
		while(!dq.empty()){
			int u = dq.front(); dq.pop_front();
			inq[u] = false;
			for(auto id: g.adj[u]){
				if(g.ignore && g.ignore(id)) continue;
				auto [u, v, w] = g.edges[id];
				if(dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
					pv[v] = u, pe[v] = id;
					if(!inq[v]){
						dq.push_back(v), inq[v] = true, ++ cnt[v];
						if(cnt[v] > g.n) return false;
					}
				}
			}
		}
		return true;
	}
	vector<int> path_from_root(int u){
		vector<int> path;
		for(; pv[u] != -1; u = pv[u]) path.push_back(pe[u]);
		return {path.rbegin(), path.rend()};
	}
	T inf, minf;
	vector<T> dist;
	vector<int> pv, pe;
};

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	disjoint_set dsu(n << 1);
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		dsu.merge(u, v + n), dsu.merge(v, u + n);
		if(dsu.share(u, u + n)){
			cout << "-1\n";
			return 0;
		}
		g.link(u, v);
	}
	int res = 0;
	shortest_path_tree<int> spt;
	vector<int> vis(n);
	for(auto s = 0; s < n; ++ s){
		if(!vis[s]){
			vector<int> cur;
			function<void(int)> dfs = [&](int u){
				vis[u] = true;
				cur.push_back(u);
				for(auto id: g.adj[u]){
					auto &e = g.edges[id];
					int v = u ^ e.from ^ e.to;
					if(!vis[v]){
						dfs(v);
					}
				}
			};
			dfs(s);
			int cur_max = 0;
			for(auto u: cur){
				ctmax(cur_max, spt.init_bfs(g, {u}));
			}
			res += cur_max;
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