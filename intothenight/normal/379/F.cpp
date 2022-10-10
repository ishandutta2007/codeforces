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

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct sparse_table_base{
	int n;
	vector<vector<Q>> val;
	sparse_table_base(vector<Q> &a): n((int)a.size()), val({a}){ // O(n log n)
		for(int p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			val.emplace_back(n - (p << 1) + 1);
			for(int j = 0; j < (int)val[i].size(); ++ j) val[i][j] = merge(val[i - 1][j], val[i - 1][j + p]);
		}
	}
	sparse_table_base(){ }
	Q query(int l, int r){ // O(1)
		if(l >= r) return identity();
		int d = __lg(r - l);
		return merge(val[d][l], val[d][r - (1 << d)]);
	}
};
template<class Q> Q min_op(Q x, Q y){ // Must be idempotent
	return min(x, y);
}
template<class Q> Q min_id(){
	return numeric_limits<Q>::max() / 2;
}
template<class Q>
using sparse_table = sparse_table_base<Q, min_op<Q>, min_id<Q>>;

// Requires graph and sparse_table
struct lca_solver{
	int n;
	vector<int> pos, depth, order, porder;
	sparse_table<int> rmq; // int, min, inf
	template<class T>
	lca_solver(const graph<T> &g, const vector<int> &roots = {0}): n(g.n), depth(n), pos(n, -1){
		int it = 0;
		function<void(int, int)> dfs = [&](int u, int pe){
			pos[u] = it ++;
			for(auto id: g.adj[u]) if(id != pe){
				if(g.ignore && g.ignore(id)) continue;
				order.push_back(u), porder.push_back(pos[u]);
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				depth[v] = depth[u] + 1;
				dfs(v, id);
			}
		};
		for(auto root: roots) if(!~pos[root]) dfs(root, -1);
		rmq = {porder};
	}
	int query(int u, int v){
		if(u == v) return u;
		tie(u, v) = minmax(pos[u], pos[v]);
		return order[rmq.query(u, v)];
	}
	int steps(int u, int v, int w = -1){ return depth[u] + depth[v] - 2 * depth[~w ? w : query(u, v)]; }
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int qn;
	cin >> qn;
	int n = 2 * qn + 4;
	graph<int> g(n);
	for(auto u = 1; u < 4; ++ u){
		g.orient(0, u);
	}
	for(auto qi = 0, sz = 4; qi < qn; ++ qi){
		int p;
		cin >> p, -- p;
		g.orient(p, sz ++), g.orient(p, sz ++);
	}
	lca_solver lca(g);
	for(auto qi = 0, dx = 1, dy = 2, diam = 2, sz = 4; qi < qn; ++ qi){
		int u = sz ++, v = sz ++;
		if(diam < lca.steps(u, dx)){
			diam = lca.steps(u, dx);
			dy = u;
		}
		if(diam < lca.steps(u, dy)){
			diam = lca.steps(u, dy);
			dx = u;
		}
		if(diam < lca.steps(v, dx)){
			diam = lca.steps(v, dx);
			dy = v;
		}
		if(diam < lca.steps(v, dy)){
			diam = lca.steps(v, dy);
			dx = v;
		}
		cout << diam << "\n";
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