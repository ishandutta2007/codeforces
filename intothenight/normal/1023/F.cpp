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

template<class L, L (*composite)(L, L), L (*identity_update)(int, int)>
struct reverse_segment_tree_base{
	reverse_segment_tree_base(): reverse_segment_tree_base(0){}
	reverse_segment_tree_base(int n): n(n){
		vector<L> v(n);
		for(int i = 0; i < n; ++ i) v[i] = identity_update(i, i + 1);
		*this = reverse_segment_tree_base(v);
	}
	reverse_segment_tree_base(const vector<L> &v): n((int)v.size()){
		log = __lg(n + 1) + 1, size = 1 << log;
		lazy = vector<L>(size << 1);
		copy(v.begin(), v.end(), lazy.begin() + size);
		for(int i = 1; i < size; ++ i){
			int h = log - __lg(i);
			lazy[i] = identity_update((i << h) - size, (i + 1 << h) - size);
		}
	}
	void update(int l, int r, L x){
		if(l >= r) return;
		l += size, r += size;
		for(int i = log; i >= 1; -- i){ // for non-commutative operations
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) lazy[l ++] = composite(x, lazy[l]);
			if(r & 1) lazy[r] = composite(x, lazy[-- r]);
		}
	}
	L query(int p){
		L res = identity_update(p, p + 1);
		for(p += size; p > 0; p >>= 1) res = composite(lazy[p], res);
		return res;
	}
	void push(int i){
		lazy[i << 1] = composite(lazy[i], lazy[i << 1]);
		lazy[i << 1 | 1] = composite(lazy[i], lazy[i << 1 | 1]);
		int h = log - __lg(i);
		lazy[i] = identity_update((i << h) - size, (i + 1 << h) - size);
	}
	void push_all(){
		for(int i = 1; i < n; ++ i) push(i);
	}
	int n, size, log;
	vector<L> lazy;
};
using L = int; // Semigroup (Lazy Type)
L composite(L f, L g){ // composites superset and subset 
	return !~f ? g : f;
}
L identity_update(int l, int r){
	return -1;
}
using reverse_segment_tree = reverse_segment_tree_base<L, composite, identity_update>;

// Requires graph
template<int VALS_IN_EDGES = 0>
struct heavy_light_decomposition{
	int n;
	vector<int> roots;
	vector<vector<int>> adj;
	vector<int> pv, pe, sz, depth, next, pos, end, order; // next stores the highest point of the heavy path
	template<class T>
	heavy_light_decomposition(graph<T> &g, vector<int> roots = {0}): n(g.n), roots(roots), adj(n), pv(n, -1), pe(n, -1), sz(n, 1), depth(n), next(n), pos(n), end(n){
		for(auto id = 0; id < (int)g.edges.size(); ++ id){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edges[id];
			adj[e.from].push_back(id), adj[e.to].push_back(id);
		}
		function<void(int, int)> dfs_init = [&](int u, int root){
			next[u] = root;
			if(~pe[u]) adj[u].erase(find(adj[u].begin(), adj[u].end(), pe[u]));
			for(auto &id: adj[u]){
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				pv[v] = u, pe[v] = id, depth[v] = depth[u] + 1;
				dfs_init(v, u);
				sz[u] += sz[v];
				auto &f = g.edges[adj[u][0]];
				if(sz[v] > sz[u ^ f.from ^ f.to]) swap(id, adj[u][0]);
			}
		};
		int timer = 0;
		function<void(int)> dfs_hld = [&](int u){
			pos[u] = timer ++;
			order.push_back(u);
			auto &f = g.edges[adj[u][0]];
			int hv = u ^ f.from ^ f.to;
			for(auto id: adj[u]){
				auto &e = g.edges[id];
				int v = u ^ e.from ^ e.to;
				next[v] = (v == hv ? next[u] : v);
				dfs_hld(v);
			}
			end[u] = timer;
		};
		for(auto r: roots) assert(!~pv[r]), dfs_init(r, r), dfs_hld(r);
	}
	int lca(int u, int v){
		for(; next[u] != next[v]; v = pv[next[v]]) if(depth[next[u]] > depth[next[v]]) swap(u, v);
		return depth[u] < depth[v] ? u : v;
	}
	int dist(int u, int v, int w = -1){
		return depth[u] + depth[v] - 2 * depth[~w ? w : lca(u, v)];
	}
	// function f reads the position in the data structure
	void querynode(int u, function<void(int)> f){ f(pos[u]); } // one application of f
	void querysubtree(int u, function<void(int, int)> f){ f(pos[u] + VALS_IN_EDGES, end[u]); } // one application of f
	void querypath(int u, int v, function<void(int, int, bool)> f){ // left, right, (left->right ?), O(log N) applications of f
		bool dir = true;
		for(; next[u] != next[v]; v = pv[next[v]]){
			if(depth[next[u]] > depth[next[v]]) swap(u, v), dir = !dir;
			f(pos[next[v]], pos[v] + 1, dir);
		}
		if(depth[u] > depth[v]) swap(u, v), dir = !dir;
		f(pos[u] + VALS_IN_EDGES, pos[v] + 1, dir);
	}
	auto getpath(int u, int v){ // O(log N)
		vector<pair<int, int>> resl, resr; // pair of indices {l, r} in the data structure; resr is reversed(v->next[v], pv[next[v]]-> ...)
		querypath(u, v, [&](int l, int r, bool dir){ (dir ? resl : resr).push_back({l, r}); });
		return pair{resl, resr};
	}
};

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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k, m;
	cin >> n >> k >> m;
	graph<int> g(n); // 1: original edges, 0: added edges
	disjoint_set dsu(n);
	for(auto i = 0; i < k; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, 1);
		dsu.merge(u, v);
	}
	vector<array<int, 3>> edges(m);
	for(auto i = 0; i < m; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		edges[i] = {w, u, v};
		if(dsu.merge(u, v)){
			g.link(u, v, 0);
		}
	}
	heavy_light_decomposition<true> hld(g);
	sort(edges.rbegin(), edges.rend());
	reverse_segment_tree seg(n);
	for(auto [w, u, v]: edges){
		hld.querypath(u, v, [&](int l, int r, bool){ seg.update(l, r, w); });
	}
	vector<int> isroot(n);
	for(auto u: hld.roots){
		isroot[u] = true;
	}
	long long res = 0;
	for(auto i = 0; i < n; ++ i){
		if(!isroot[hld.order[i]]){
			int w = seg.query(i);
			if(!~w){
				cout << "-1\n";
				return 0;
			}
			int id = hld.pe[hld.order[i]];
			if(g.edges[id].cost){
				res += w;
			}
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