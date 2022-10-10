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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, qn;
	cin >> n >> m >> qn;
	graph<int> g(n);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		g.orient(u, v, w);
	}
	shortest_path_tree<long long> spt;
	spt.init_dijkstra<int>(g, {0});
	auto dist = spt.dist;
	for(auto qi = 0, cnt = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int u;
			cin >> u, -- u;
			static vector<int> delta(n);
			fill(delta.begin(), delta.end(), numeric_limits<int>::max() / 3);
			delta[0] = 0;
			vector<vector<int>> que(cnt + 1);
			que[0].push_back(0);
			for(auto c = 0; c <= cnt; ++ c){
				while(!que[c].empty()){
					int u = que[c].back(); que[c].pop_back();
					if(delta[u] == c){
						for(auto id: g.adj[u]){
							auto &e = g.edges[id];
							int v = e.to, w = e.cost;
							if(dist[v] + delta[v] > dist[u] + delta[u] + w){
								delta[v] = dist[u] + delta[u] + w - dist[v];
								if(delta[v] <= cnt){
									que[delta[v]].push_back(v);
								}
							}
						}
					}
				}
			}
			for(auto u = 0; u < n; ++ u){
				dist[u] = min(dist[u] + delta[u], spt.inf);
			}
			dist[u] != spt.inf ? cout << dist[u] << "\n" : cout << "-1\n";
			cnt = 0;
		}
		else{
			int k;
			cin >> k;
			cnt += k;
			for(auto i = 0; i < k; ++ i){
				int id;
				cin >> id, -- id;
				++ g.edges[id].cost;
			}
		}
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