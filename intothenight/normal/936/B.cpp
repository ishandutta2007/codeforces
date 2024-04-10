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
template<class T, class Q, Q (*act)(T, Q), Q (*identity)()>
struct dfs_forest_base{
	void init(int n){
		this->n = n;
		pv.assign(n, -1);
		pe.assign(n, -1);
		order.clear();
		pos.assign(n, -1);
		end.assign(n, -1);
		sz.assign(n, 0);
		root.assign(n, -1);
		depth.assign(n, -1);
		min_depth.assign(n, -1);
		dist.assign(n, identity());
		was.assign(n, -1);
		attempt = 0;
	}
	int attempt;
	void dfs(const graph<T> &g, int u, bool clear_order = true){
		++ attempt;
		depth[u] = 0;
		dist[u] = identity();
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order) order.clear();
		function<void(int)> recurse = [&](int u){
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			sz[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g.adj[u]){
				if(id == pe[u] || g.ignore && g.ignore(id)) continue;
				auto &e = g.edges[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = act(e.cost, dist[u]);
				pv[v] = u;
				pe[v] = id;
				root[v] = root[u];
				recurse(v);
				sz[u] += sz[v];
				min_depth[u] = min(min_depth[u], min_depth[v]);
			}
			end[u] = (int)order.size();
		};
		recurse(u);
	}
	void dfs_all(const graph<T> &g){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs(g, u, false);
	}
	int n;
	vector<Q> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	dfs_forest_base(int n){ init(n); }
};
template<class T, class Q> Q df_act(T x, Q y){
	return x + y;
}
template<class Q> Q df_id(){
	return {};
}
template<class T, class Q>
using dfs_forest = dfs_forest_base<T, Q, df_act<T, Q>, df_id<Q>>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	graph<int> g(n << 1);
	vector<int> obj;
	for(auto u = 0; u < n; ++ u){
		int k;
		cin >> k;
		if(!k){
			obj.push_back(u);
		}
		for(auto i = 0; i < k; ++ i){
			int v;
			cin >> v, -- v;
			g.orient(u, v + n);
			g.orient(u + n, v);
		}
	}
	int s;
	cin >> s, -- s;
	dfs_forest<int, int> df(n << 1);
	df.dfs(g, s);
	for(auto u: obj){
		if(~df.depth[u + n]){
			u += n;
			vector<int> path;
			while(u != s){
				path.push_back(u < n ? u : u - n);
				u = df.pv[u];
			}
			path.push_back(u);
			reverse(path.begin(), path.end());
			cout << "Win\n";
			for(auto u: path){
				cout << u + 1 << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	vector<int> vis(n << 1), onstack(n << 1);
	function<void(int)> dfs = [&](int u){
		onstack[u] = true;
		vis[u] = true;
		for(auto id: g.adj[u]){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			if(onstack[v]){
				cout << "Draw\n";
				exit(0);
			}
			if(vis[v]){
				continue;
			}
			dfs(v);
		}
		onstack[u] = false;
	};
	dfs(s);
	cout << "Lose\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////