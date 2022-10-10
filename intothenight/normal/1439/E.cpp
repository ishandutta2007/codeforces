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

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct sparse_table{
	int n;
	vector<vector<Q>> val;
	sparse_table(vector<Q> &a): n((int)a.size()), val({a}){ // O(n log n)
		for(int p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
			val.emplace_back(n - (p << 1) + 1);
			for(int j = 0; j < (int)val[i].size(); ++ j) val[i][j] = merge(val[i - 1][j], val[i - 1][j + p]);
		}
	}
	sparse_table(){ }
	Q query(int l, int r){ // O(1)
		if(l >= r) return identity();
		int d = __lg(r - l);
		return merge(val[d][l], val[d][r - (1 << d)]);
	}
};
int min_op(int x, int y){
	return min(x, y);
}
int min_id(){
	return numeric_limits<int>::max() / 2;
}
//	sparse_table<int, min_op, min_id> st;

// Requires graph and sparse_table
struct lca_solver{
	int n;
	vector<int> pos, order, porder;
	sparse_table<int, min_op, min_id> rmq;
	template<class T>
	lca_solver(graph<T> &g, vector<int> roots = {0}): n(g.n), pos(n, -1){
		int it = 0;
		function<void(int, int)> dfs = [&](int u, int pe){
			pos[u] = it ++;
			for(auto id: g.adj[u]) if(id != pe){
				if(g.ignore && g.ignore(id)) continue;
				order.push_back(u), porder.push_back(pos[u]);
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
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
};

// Requires graph
template<class T, T (*merge)(T, T), T (*identity)()>
struct dfs_forest{
	int n;
	graph<T> *g;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
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
		dist.assign(n, identity());
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
	void dfs(int u, bool clear_order = true){
		++ attempt;
		depth[u] = 0;
		dist[u] = identity();
		root[u] = u;
		pv[u] = pe[u] = -1;
		if(clear_order){
			order.clear();
		}
		function<void(int)> recurse = [&](int u){
			was[u] = attempt;
			pos[u] = (int)order.size();
			order.push_back(u);
			sz[u] = 1;
			min_depth[u] = depth[u];
			for(auto id: g->adj[u]){
				if(id == pe[u] || g->ignore && g->ignore(id)){
					continue;
				}
				auto &e = g->edges[id];
				int v = e.from ^ e.to ^ u;
				if(was[v] == attempt){
					min_depth[u] = min(min_depth[u], depth[v]);
					continue;
				}
				depth[v] = depth[u] + 1;
				dist[v] = merge(dist[u], e.cost);
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
		order.clear();
		for(auto u = 0; u < n; ++ u){
			if(!~depth[u]){
				dfs(u, false);
			}
		}
		assert((int)order.size() == n);
	}
};
int add_merge(int x, int y){
	return x + y;
}
int add_id(){
	return {};
}
//	dfs_forest<int, add_merge, add_id> df;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int m;
	cin >> m;
	using P = pair<int, int>;
	vector<array<P, 2>> a(m);
	for(auto &[p, q]: a){
		cin >> p.first >> p.second >> q.first >> q.second;
	}
	auto depth = [&](P p){
		return p.first + p.second;
	};
	auto next = [&](P p){
		if(!p.second || p.first && (p.first & -p.first) < (p.second & -p.second)){
			p.first -= p.first & -p.first;
		}
		else{
			p.second -= p.second & -p.second;
		}
		return p;
	};
	auto get_lca = [&](P p, P q){
		if(p == q){
			return p;
		}
		int bit = max(
			p.first != q.first ? __lg(p.first ^ q.first) : -1
			, p.second != q.second ? __lg(p.second ^ q.second) : -1
		);
		int x = 0, y = 0;
		for(auto b = 30; b > bit; -- b){
			x |= p.first & 1 << b;
			y |= p.second & 1 << b;
		}
		int mask = (1 << bit + 1) - 1;
		p.first &= mask, p.second &= mask, q.first &= mask, q.second &= mask;
		int ps = ((p.first & 1 << bit) >> bit) | ((p.second & 1 << bit) >> bit) << 1;
		int qs = ((q.first & 1 << bit) >> bit) | ((q.second & 1 << bit) >> bit) << 1;
		assert(ps != qs);
		if(ps && qs) return P{x, y};
		if(ps){
			swap(ps, qs);
			swap(p, q);
		}
		if(qs == 1){
			if(p.first <= p.second){
				return P{x, y};
			}
			while(p.first && p.second){
				p = next(p);
			}
			return P{x + p.first, y + p.second};
		}
		else{
			if(p.first >= p.second){
				return P{x, y};
			}
			while(p.first && p.second){
				p = next(p);
			}
			return P{x + p.first, y + p.second};
		}
	};
	auto cmp_pos = [&](P p, P q){
		if(p == q){
			return false;
		}
		int bit = max(
			p.first != q.first ? __lg(p.first ^ q.first) : -1
			, p.second != q.second ? __lg(p.second ^ q.second) : -1
		);
		int mask = (1 << bit + 1) - 1;
		p.first &= mask, p.second &= mask, q.first &= mask, q.second &= mask;
		int ps = ((p.first & 1 << bit) >> bit) | ((p.second & 1 << bit) >> bit) << 1;
		int qs = ((q.first & 1 << bit) >> bit) | ((q.second & 1 << bit) >> bit) << 1;
		assert(ps != qs);
		if(ps && qs) return ps < qs;
		else if(!ps){
			if(qs == 2) return true;
			else return !p.second;
		}
		else{
			if(ps == 2) return false;
			else return !!q.second;
		}
	};
	vector<P> order;
	for(auto [p, q]: a){
		order.push_back(p), order.push_back(q);
	}
	sort(order.begin(), order.end(), cmp_pos);
	for(auto i = 1, sz = (int)order.size(); i < sz; ++ i){
		order.push_back(get_lca(order[i - 1], order[i]));
	}
	sort(order.begin(), order.end(), cmp_pos), order.erase(unique(order.begin(), order.end()), order.end());
	auto labelling = order;
	sort(labelling.begin(), labelling.end()), labelling.erase(unique(labelling.begin(), labelling.end()), labelling.end());
	auto label = [&](P p){
		return lower_bound(labelling.begin(), labelling.end(), p) - labelling.begin();
	};
	int n = (int)labelling.size();
	graph<int> g(n);
	for(auto i = 1; i < (int)order.size(); ++ i){
		g.link(label(get_lca(order[i - 1], order[i])), label(order[i]));
		int u = label(get_lca(order[i - 1], order[i])), v = label(order[i]);
	}
	lca_solver lca(g);
	dfs_forest<int, add_merge, add_id> df;
	df.init(&g);
	df.dfs(0);
	vector<int> pref(n), vpref(n);
	for(auto [p, q]: a){
		int u = label(p), v = label(q), w = lca.query(u, v);
		++ pref[u], ++ pref[v], pref[w] -= 2;
		++ vpref[u], ++ vpref[v], -- vpref[w];
		if(~df.pv[w]){
			-- vpref[df.pv[w]];
		}
	}
	vector<int> cnt((int)g.edges.size());
	for(auto i = (int)df.order.size() - 1; i >= 0; -- i){
		int u = df.order[i];
		for(auto id: g.adj[u]){
			if(id != df.pe[u]){
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				pref[u] += pref[v];
				vpref[u] += vpref[v];
				if(pref[v]){
					cnt[id] = true;
				}
			}
		}
	}
	vector<int> pivots;
	for(auto i = 0; i < (int)cnt.size(); ++ i){
		if(cnt[i]){
			auto &e = g.edges[i];
			int u = e.from, v = e.to;
			if(depth(labelling[u]) > depth(labelling[v])){
				swap(u, v);
			}
			pivots.push_back(depth(labelling[u]));
			pivots.push_back(depth(labelling[v]) + 1);
		}
	}
	for(auto u = 0; u < n; ++ u){
		int adjcnt = 0;
		for(auto id: g.adj[u]){
			adjcnt += !!cnt[id];
		}
		if(vpref[u] && adjcnt % 2 == 0){
			pivots.push_back(depth(labelling[u]));
			pivots.push_back(depth(labelling[u]) + 1);
		}
	}
	sort(pivots.begin(), pivots.end());
	vector<array<int, 2>> ranges;
	for(auto i = 0; i < (int)pivots.size(); i += 2){
		int l = pivots[i], r = pivots[i + 1];
		if(l != r){
			if(ranges.empty() || ranges.back()[1] < l){
				ranges.push_back({l, r});
			}
			else{
				ranges.back()[1] = r;
			}
		}
	}
	int res = (int)ranges.size() * 2;
	if(!ranges.empty() && !ranges[0][0]){
		-- res;
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