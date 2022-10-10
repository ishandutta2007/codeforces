#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class T>
struct graph{
	struct E{
		int from, to;
		T cost;
	};
	int n;
	vector<E> edge;
	vector<vector<int>> adj;
	function<bool(int)> ignore;
	graph(int n): n(n), adj(n){ }
	int link(int u, int v, T w = {}){ // insert an undirected edge
		int id = (int)edge.size();
		adj[u].push_back(id), adj[v].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	int orient(int u, int v, T w = {}){ // insert a directed edge
		int id = (int)edge.size();
		adj[u].push_back(id), edge.push_back({u, v, w});
		return id;
	}
	graph transposed() const{ // the transpose of the directed graph
		graph res(n);
		for(auto &e: edge) res.orient(e.to, e.from, e.cost);
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
			auto &e = edge[id];
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

template<class U, class F1, class F2>
struct reverse_segment_tree{
	int n, size, log;
	vector<U> updates;
	F1 UU; // semigroup operation (superset, subset)
	F2 U_init; // semigroup default element for the interval [l, r)
	reverse_segment_tree(int n, F1 UU, F2 U_init){
		vector<U> a(n);
		for(auto i = 0; i < n; ++ i) a[i] = U_init(i, i + 1);
		*this = reverse_segment_tree(a, UU, U_init);
	}
	reverse_segment_tree(int n, U init, F1 UU, F2 U_init): reverse_segment_tree(vector<U>(n, init), UU, U_init){ }
	reverse_segment_tree(const vector<U> &a, F1 UU, F2 U_init): n((int)a.size()), UU(UU), U_init(U_init){
		log = __lg(max(n - 1, 1)) + 1, size = 1 << log;
		updates = vector<U>(size << 1);
		copy(a.begin(), a.end(), updates.begin() + size);
		for(auto i = 1; i < size; ++ i){
			int h = log - __lg(i);
			updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
		}
	}
	void update(int l, int r, U x){
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return;
		l += size, r += size;
		for(auto i = log; i >= 1; -- i){ // for non-commutative operations
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) updates[l ++] = UU(x, updates[l]);
			if(r & 1) updates[r] = UU(x, updates[-- r]);
		}
	}
	U query(int p){
		assert(0 <= p && p < n);
		U res = U_init(p, p + 1);
		for(p += size; p > 0; p >>= 1) res = UU(updates[p], res);
		return res;
	}
	void push(int i){
		updates[i << 1] = UU(updates[i], updates[i << 1]);
		updates[i << 1 | 1] = UU(updates[i], updates[i << 1 | 1]);
		int h = log - __lg(i);
		updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
	}
	void push_all(){
		for(auto i = 1; i < n; ++ i) push(i);
	}
	template<class output_stream>
	friend output_stream &operator<<(output_stream &out, const reverse_segment_tree<U, F1, F2> &seg){
		out << "[";
		for(auto i = 0; i < seg.n; ++ i){
			out << seg.query(i);
			if(i != seg.n - 1) out << ", ";
		}
		return out << ']';
	}
};

// Requires graph
template<int VALS_IN_EDGES = 0>
struct heavy_light_decomposition{
	int n;
	vector<vector<int>> adj; // stores edge ids
	vector<int> roots; // root of the component
	vector<int> pv;
	vector<int> pe;
	vector<int> sz;
	vector<int> depth;
	vector<int> next; // highest point of the heavy path
	vector<int> prev; // lowest point of the heavy path
	vector<int> pos;
	vector<int> end;
	vector<int> order;
	template<class T>
	heavy_light_decomposition(const graph<T> &g, const vector<int> &roots): n(g.n), roots(roots), adj(n), pv(n, -1), pe(n, -1), sz(n, 1), depth(n), next(n), prev(n), pos(n), end(n){
		iota(prev.begin(), prev.end(), 0);
		for(auto id = 0; id < (int)g.edge.size(); ++ id){
			if(g.ignore && g.ignore(id)) continue;
			auto &e = g.edge[id];
			adj[e.from].push_back(id), adj[e.to].push_back(id);
		}
		auto dfs_init = [&](auto self, int u, int root)->void{
			next[u] = root;
			if(~pe[u]) adj[u].erase(find(adj[u].begin(), adj[u].end(), pe[u]));
			for(auto &id: adj[u]){
				auto &e = g.edge[id];
				int v = u ^ e.from ^ e.to;
				pv[v] = u, pe[v] = id, depth[v] = depth[u] + 1;
				self(self, v, u);
				sz[u] += sz[v];
				auto &f = g.edge[adj[u][0]];
				if(sz[v] > sz[u ^ f.from ^ f.to]) swap(id, adj[u][0]);
			}
			if(!adj[u].empty()){
				auto &e = g.edge[adj[u][0]];
				prev[u] = prev[u ^ e.from ^ e.to];
			}
		};
		int timer = 0;
		auto dfs_hld = [&](auto self, int u)->void{
			pos[u] = timer ++;
			order.push_back(u);
			if(!adj[u].empty()){
				auto &f = g.edge[adj[u][0]];
				int hv = u ^ f.from ^ f.to;
				for(auto id: adj[u]){
					auto &e = g.edge[id];
					int v = u ^ e.from ^ e.to;
					next[v] = (v == hv ? next[u] : v);
					self(self, v);
				}
			}
			end[u] = timer;
		};
		for(auto r: roots) assert(!~pv[r]), dfs_init(dfs_init, r, r), dfs_hld(dfs_hld, r);
	}
	int lca(int u, int v) const{
		for(; next[u] != next[v]; v = pv[next[v]]) if(depth[next[u]] > depth[next[v]]) swap(u, v);
		return depth[u] < depth[v] ? u : v;
	}
	int steps(int u, int v, int w = -1) const{
		return depth[u] + depth[v] - 2 * depth[~w ? w : lca(u, v)];
	}
	// f reads the position in the data structure
	// One application of f
	void querynode(int u, auto f) const{
		f(pos[u]);
	}
	// One application of f
	void querysubtree(int u, auto f) const{
		f(pos[u] + VALS_IN_EDGES, end[u]);
	}
	// f(left, right, (left->right ?))
	// O(log n) applications of f
	void querypath(int u, int v, auto f) const{
		bool dir = true;
		for(; next[u] != next[v]; v = pv[next[v]]){
			if(depth[next[u]] > depth[next[v]]) swap(u, v), dir = !dir;
			f(pos[next[v]], pos[v] + 1, dir);
		}
		if(depth[u] > depth[v]) swap(u, v), dir = !dir;
		f(pos[u] + VALS_IN_EDGES, pos[v] + 1, dir);
	}
	// Pair of indices {l, r} in the data structure. resr is reversed(v->next[v], pv[next[v]]-> ...)
	// O(log n)
	auto getpath(int u, int v) const{
		vector<pair<int, int>> resl, resr;
		querypath(u, v, [&](int l, int r, bool dir){ (dir ? resl : resr).push_back({l, r}); });
		return pair{resl, resr};
	}
	vector<int> partition, weights;
	template<class T>
	void process_weight(const graph<T> &g){
		weights.assign(n, 1);
		vector<bool> is_head(n, true);
		for(auto u = 0; u < n; ++ u){
			if(g.degree(u)){
				auto &e = g.edge[adj[u][0]];
				int v = u ^ e.from ^ e.to;
				is_head[pos[v]] = false;
				weights[pos[u]] = sz[u] - sz[v];
			}
		}
		for(auto l = 0; l < n; ){
			int r = find(is_head.begin() + l + 1, is_head.end(), true) - is_head.begin();
			partition.push_back(r - l);
			l = r;
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v, 1);
	}
	heavy_light_decomposition hld(g, {0});
	reverse_segment_tree seg(n, 0, [&](int f, int g){ return ~f ? f : g; }, [&](int, int){ return -1; });
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int type, u;
		cin >> type >> u, -- u;
		if(type == 1){
			hld.querysubtree(u, [&](int l, int r){ seg.update(l, r, 1); });
		}
		else if(type == 2){
			hld.querypath(0, u, [&](int l, int r, bool){ seg.update(l, r, 0); });
		}
		else{
			hld.querynode(u, [&](int p){ cout << seg.query(p) << "\n"; });
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