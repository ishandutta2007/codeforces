#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct graph{
	int n;
	struct edge{
		int from, to;
		T cost;
	};
	vector<edge> edges;
	vector<vector<int>> adj;
	graph(int n): n(n), adj(n){
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
template<typename T>
struct dfs_tree{
	int n;
	graph<T> *g;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, dist, was;
	void init(graph<T> *h){
		g = h;
		n = g->n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		sz.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		dist.assign(n, id);
		was.assign(n, -1);
		attempt = 0;
	}
	void clear(){
		pv.clear();
		pe.clear();
		order.clear();
		pos.clear();
		end.clear();
		sz.clear();
		root.clear();
		depth.clear();
		min_depth.clear();
		dist.clear();
		was.clear();
	}
	int attempt = 0;
	void dfs(int u){
		++ attempt;
		depth[u] = 0;
		dist[u] = id;
		root[u] = u;
		pv[u] = pe[u] = -1;
		function<void(int)> recurse = [&](int u){
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			sz[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g->adj[u]){
				if(id == pe[u]){
					continue;
				}
				auto &e = g->edges[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = bin_op(dist[u], e.cost);
				pv[v] = u;
				pe[v] = id;
				root[v] = ~root[u] ? root[u] : v;
				recurse(v);
				sz[u] += sz[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(u);
	}
	void dfs_all(){
		for(auto u = 0; u < n; ++ u){
			if(!~depth[u]){
				dfs(u);
			}
		}
		assert((int)order.size() == n);
	}
	inline T bin_op(T x, T y){
		return x + y;
	}
	T id = {};
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, a, b, da, db;
		cin >> n >> a >> b >> da >> db, -- a, -- b;
		graph<int> g(n);
		for(auto i = 0; i < n - 1; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			g.link(u, v);
		}
		if(2 * da >= db){
			cout << "Alice\n";
			return 0;
		}
		dfs_tree<int> dt;
		dt.init(&g);
		dt.dfs(a);
		if(dt.depth[b] <= da){
			cout << "Alice\n";
			return 0;
		}
		int u = max_element(dt.depth.begin(), dt.depth.end()) - dt.depth.begin();
		dt.dfs(u);
		*max_element(dt.depth.begin(), dt.depth.end()) <= 2 * da ? cout << "Alice\n" : cout << "Bob\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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