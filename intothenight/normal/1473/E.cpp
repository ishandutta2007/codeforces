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

// Requires graph
template<class T>
struct shortest_path_tree{
	T inf, minf;
	vector<T> dist;
	vector<int> pv, pe;
	shortest_path_tree(T inf = numeric_limits<T>::max() / 3, T minf = numeric_limits<T>::min() / 3): inf(inf), minf(minf){ }
	template<class U>
	void init(const graph<U> &g, const vector<int> &src = {0}){
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
	template<class U>
	int init_bfs(const graph<U> &g, const vector<int> &src = {0}){ // returns max dist
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
	template<class U>
	void init_dijkstra(const graph<U> &g, const vector<int> &src = {0}){
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
	template<class U>
	vector<int> init_bellman_ford(const graph<U> &g, const vector<int> &src = {0}){ // return edge ids of a negative cycle, {} if none exists
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
	template<class U>
	bool init_spfa(const graph<U> &g, const vector<int> &src = {0}){ // returns false if negative cycle
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
};
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }


int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n << 2);
	vector<array<int, 2>> N0;
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		if(!u || !v){
			N0.push_back({u + v, w});
		}
		g.link(u, v, w);
		g.link(u + n, v + n, w);
		g.link(u + 2 * n, v + 2 * n, w);
		g.link(u + 3 * n, v + 3 * n, w);
		g.orient(u, v + n, 0);
		g.orient(v, u + n, 0);
		g.orient(u + n, v + 3 * n, 2 * w);
		g.orient(v + n, u + 3 * n, 2 * w);
		g.orient(u, v + 2 * n, 2 * w);
		g.orient(v, u + 2 * n, 2 * w);
		g.orient(u + 2 * n, v + 3 * n, 0);
		g.orient(v + 2 * n, u + 3 * n, 0);
	}
	shortest_path_tree<long long> spt;
	spt.init_dijkstra(g);
	vector<long long> res{spt.dist.begin() + 3 * n, spt.dist.end()};
	for(auto [u, w]: N0){
		ctmin(res[u], w);
	}
	for(auto u = 1; u < n; ++ u){
		cout << res[u] << " ";
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