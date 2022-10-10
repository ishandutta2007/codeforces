#include <bits/stdc++.h>
using namespace std;

template<class T, class U>
struct lazy_segment_tree{
	int n, size, log;
	vector<T> data;
	vector<U> updates;
	function<T(T, T)> TT; // monoid operation (always adjacent)
	T T_id; // monoid identity
	function<U(U, U)> UU; // semigroup operation (superset, subset)
	function<U(int, int)> U_init; // semigroup default element for the interval [l, r)
	function<T(U, T)> UT; // action of U on T (superset, subset)
	lazy_segment_tree(int n,
		function<T(T, T)> TT, T T_id,
		function<U(U, U)> UU, function<U(int, int)> U_init,
		function<T(U, T)> UT
	): lazy_segment_tree(vector<T>(n, T_id), TT, T_id, UU, U_init, UT){ }
	lazy_segment_tree(int n, T init,
		function<T(T, T)> TT, T T_id,
		function<U(U, U)> UU, function<U(int, int)> U_init,
		function<T(U, T)> UT
	): lazy_segment_tree(vector<T>(n, init), TT, T_id, UU, U_init, UT){ }
	lazy_segment_tree(const vector<T> &a,
		function<T(T, T)> TT, T T_id,
		function<U(U, U)> UU, function<U(int, int)> U_init,
		function<T(U, T)> UT
	): n((int)a.size()), TT(TT), T_id(T_id), UU(UU), U_init(U_init), UT(UT){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		data = vector<T>(size << 1, T_id), updates = vector<U>(size);
		copy(a.begin(), a.end(), data.begin() + size);
		for(auto i = 1; i < size; ++ i){
			int h = log - __lg(i);
			updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
		}
		for(auto i = size - 1; i >= 1; -- i) refresh(i);
	}
	void refresh(int i){ data[i] = TT(data[i << 1], data[i << 1 | 1]); }
	void apply(int i, U f){
		data[i] = UT(f, data[i]);
		if(i < size) updates[i] = UU(f, updates[i]);
	}
	void push(int i){
		apply(i << 1, updates[i]), apply(i << 1 | 1, updates[i]);
		int h = log - __lg(i);
		updates[i] = U_init((i << h) - size, (i + 1 << h) - size);
	}
	T query(int p){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		return data[p];
	}
	T query(int l, int r){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return T_id;
		l += size, r += size;
		for(auto i = log; i >= 1; -- i) {
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		T res_left = T_id, res_right = T_id;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) res_left = TT(res_left, data[l ++]);
			if(r & 1) res_right = TT(data[-- r], res_right);
		}
		return TT(res_left, res_right);
	}
	T query_all(){ return data[1]; } // O(1)
	void set(int p, T x){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = x;
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int p, U f){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(auto i = log; i >= 1; -- i) push(p >> i);
		data[p] = UT(f, data[p]);
		for(auto i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int l, int r, U f){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return;
		l += size, r += size;
		for(auto i = log; i >= 1; -- i){
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		int l2 = l, r2 = r;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) apply(l ++, f);
			if(r & 1) apply(-- r, f);
		}
		l = l2, r = r2;
		for(auto i = 1; i <= log; ++ i){
			if(l >> i << i != l) refresh(l >> i);
			if(r >> i << i != r) refresh(r - 1 >> i);
		}
	}
	template<class G> int max_pref(int l, G g){ // O(log n)
		assert(0 <= l && l <= n), assert(g(T_id));
		if(l == n) return n;
		l += size;
		for(auto i = log; i >= 1; -- i) push(l >> i);
		T sm = T_id;
		do{
			while(~l & 1) l >>= 1;
			if(!g(TT(sm, data[l]))){
				while(l < size){
					push(l);
					l = l << 1;
					if(g(TT(sm, data[l]))) sm = TT(sm, data[l ++]);
				}
				return l - size;
			}
			sm = TT(sm, data[l]);
			++ l;
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class G> int min_suff(int r, G g){ // O(log n)
		assert(0 <= r && r <= n), assert(g(T_id));
		if(r == 0) return 0;
		r += size;
		for(auto i = log; i >= 1; -- i) push(r - 1 >> i);
		T sm = T_id;
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!g(TT(data[r], sm))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(g(TT(data[r], sm))) sm = TT(data[r --], sm);
				}
				return r + 1 - size;
			}
			sm = TT(data[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
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
template<int VALS_IN_EDGES = 0>
struct heavy_light_decomposition{
	int n;
	vector<int> roots;
	vector<vector<int>> adj;
	vector<int> pv, pe, sz, depth, next, pos, end, order; // next stores the highest point of the heavy path
	template<class T>
	heavy_light_decomposition(const graph<T> &g, vector<int> roots = {0}): n(g.n), roots(roots), adj(n), pv(n, -1), pe(n, -1), sz(n, 1), depth(n), next(n), pos(n), end(n){
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
			if(!adj[u].empty()){
				auto &f = g.edges[adj[u][0]];
				int hv = u ^ f.from ^ f.to;
				for(auto id: adj[u]){
					auto &e = g.edges[id];
					int v = u ^ e.from ^ e.to;
					next[v] = (v == hv ? next[u] : v);
					dfs_hld(v);
				}
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
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, qn;
	cin >> n >> m >> qn;
	graph<int> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		g.link(u, v);
	}
	vector<vector<int>> rem(n);
	for(auto i = 1; i <= m; ++ i){
		int u;
		cin >> u, -- u;
		rem[u].push_back(i);
	}
	for(auto u = 0; u < n; ++ u){
		reverse(rem[u].begin(), rem[u].end());
	}
	heavy_light_decomposition hld(g);
	vector<pair<long long, int>> init(n);
	const long long inf = numeric_limits<long long>::max() / 2;
	using T = pair<long long, int>;
	using U = long long;
	for(auto u = 0; u < n; ++ u){
		init[hld.pos[u]] = rem[u].empty() ? T{inf, -1} : T{rem[u].back(), u};
	}
	auto TT = [&](auto x, auto y){
		return min(x, y);
	};
	T T_id = {inf, -1};
	auto UU = [&](auto x, auto y){
		return x + y;
	};
	auto U_id = [&](int l, int r){
		return 0LL;
	};
	auto UT = [&](auto x, auto y){
		return T{y.first + x, y.second};
	};
	lazy_segment_tree<T, U> ds(init, TT, T_id, UU, U_id, UT);
	for(auto qi = 0; qi < qn; ++ qi){
		int type;
		cin >> type;
		if(type == 1){
			int u, v, k;
			cin >> u >> v >> k, -- u, -- v;
			vector<int> res;
			for(auto rep = 0; rep < k; ++ rep){
				T cur = T_id;
				hld.querypath(u, v, [&](int l, int r, bool){
					ctmin(cur, ds.query(l, r));
				});
				if(cur.first >= inf){
					break;
				}
				auto [x, u] = cur;
				long long delta = x - rem[u].back();
				res.push_back(rem[u].back());
				rem[u].pop_back();
				if(rem[u].empty()){
					ds.set(hld.pos[u], T_id);
				}
				else{
					ds.set(hld.pos[u], {rem[u].back() + delta, u});
				}
			}
			cout << (int)res.size() << " ";
			for(auto i: res){
				cout << i << " ";
			}
			cout << "\n";
		}
		else{
			int u, k;
			cin >> u >> k, -- u;
			hld.querysubtree(u, [&](int l, int r){
				ds.update(l, r, k);
			});
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