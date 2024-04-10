#include <bits/stdc++.h>
using namespace std;

// DEBUG BEGIN
#ifdef LOCAL
template<class L, class R> ostream &operator<<(ostream &out, const pair<L, R> &p){
	return out << "(" << p.first << ", " << p.second << ")";
}
template<class Tuple, size_t N> struct TuplePrinter{
	static ostream &print(ostream &out, const Tuple &t){ return TuplePrinter<Tuple, N-1>::print(out, t) << ", " << get<N-1>(t); }
};
template<class Tuple> struct TuplePrinter<Tuple, 1>{
	static ostream &print(ostream &out, const Tuple& t){ return out << get<0>(t); }
};
template<class... Args> ostream &print_tuple(ostream &out, const tuple<Args...> &t){
	return TuplePrinter<decltype(t), sizeof...(Args)>::print(out << "(", t) << ")";
}
template<class ...Args> ostream &operator<<(ostream &out, const tuple<Args...> &t){
	return print_tuple(out, t);
}
template<class T> ostream &operator<<(enable_if_t<!is_same<T, string>::value, ostream> &out, const T &arr){
	out << "{"; for(auto &x: arr) out << x << ", ";
	return out << (arr.size() ? "\b\b" : "") << "}";
}
template<size_t S> ostream &operator<<(ostream &out, const bitset<S> &b){
	for(int i = 0; i < S; ++ i) out << b[i];
	return out;
}
void debug_out(){ cerr << "\b\b " << endl; }
template<class Head, class... Tail>
void debug_out(Head H, Tail... T){ cerr << H << ", ", debug_out(T...); }
void debug2_out(){ cerr << "-----DEBUG END-----\n"; }
template<class Head, class... Tail>
void debug2_out(Head H, Tail... T){ cerr << "\n"; for(auto x: H) cerr << x << "\n"; debug2_out(T...); }
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#define debug2(...) cerr << "----DEBUG BEGIN----\n[" << #__VA_ARGS__ << "]:", debug2_out(__VA_ARGS__)
#else
#define debug(...) 42
#define debug2(...) 42
#endif
// DEBUG END

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
struct dfs_tree{
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
	void dfs(int u, bool clear_order = true){
		++ attempt;
		depth[u] = 0;
		dist[u] = id;
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
		order.clear();
		for(auto u = 0; u < n; ++ u){
			if(!~depth[u]){
				dfs(u, false);
			}
		}
		assert((int)order.size() == n);
	}
	inline T bin_op(T x, T y){
		return x ^ y;
	}
	T id = {};
};

template<class Q,
					Q (*merge)(Q, Q),
					Q (*identity)(),
					class L,
					L (*composite)(L, L),
					L (*identity_action)(int, int),
					Q (*act)(L, Q)>
struct lazy_segment_tree{
	lazy_segment_tree(): lazy_segment_tree(0){}
	lazy_segment_tree(int n): lazy_segment_tree(vector<Q>(n)){}
	lazy_segment_tree(const vector<Q> &v): n((int)v.size()){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		val = vector<Q>(size << 1, identity()), lazy = vector<L>(size);
		copy(v.begin(), v.end(), val.begin() + size);
		for(int i = 1; i < size; ++ i){
			int h = log - __lg(i);
			lazy[i] = identity_action((i << h) - size, (i + 1 << h) - size);
		}
		for(int i = size - 1; i >= 1; -- i) refresh(i);
	}
	Q query(int p){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i >= 1; -- i) push(p >> i);
		return val[p];
	}
	Q query(int l, int r){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return identity();
		l += size, r += size;
		for(int i = log; i >= 1; -- i) {
			if(((l >> i) << i) != l) push(l >> i);
			if(((r >> i) << i) != r) push(r >> i);
		}
		Q sml = identity(), smr = identity();
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = merge(sml, val[l ++]);
			if(r & 1) smr = merge(val[-- r], smr);
		}
		return merge(sml, smr);
	}
	Q query_all(){ return val[1]; } // O(1)
	void set(int p, Q x){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i >= 1; -- i) push(p >> i);
		val[p] = x;
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int p, L f){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i >= 1; -- i) push(p >> i);
		val[p] = act(f, val[p]);
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int l, int r, L f){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return;
		l += size, r += size;
		for(int i = log; i >= 1; -- i){
			if(((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push(r - 1 >> i);
		}
		int l2 = l, r2 = r;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) apply(l ++, f);
			if(r & 1) apply(-- r, f);
		}
		l = l2, r = r2;
		for(int i = 1; i <= log; ++ i){
			if(((l >> i) << i) != l) refresh(l >> i);
			if(((r >> i) << i) != r) refresh((r - 1) >> i);
		}
	}
	template<class G> int partition_point_pref(int l, G g){ // O(log n)
		assert(0 <= l && l <= n), assert(g({}));
		if(l == n) return n;
		l += size;
		for(int i = log; i >= 1; ++ i) push(l >> i);
		Q sm = identity();
		do{
			while(~l & 1) l >>= 1;
			if(!g(sm + val[l])){
				while(l < size){
					push(l);
					l = l << 1;
					if(g(merge(sm, val[l]))) sm = merge(sm, val[l ++]);
				}
				return l - size;
			}
			sm = merge(sm, val[l]);
			++ l;
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class G> int partition_point_suff(int r, G g){ // O(log n)
		assert(0 <= r && r <= n), assert(g({}));
		if(r == 0) return 0;
		r += size;
		for(int i = log; i >= 1; -- i) push(r - 1 >> i);
		Q sm = identity();
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!g(merge(val[r], sm))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(g(merge(val[r], sm))) sm = merge(val[r --], sm);
				}
				return r + 1 - size;
			}
			sm = merge(val[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
	int n, size, log;
	vector<Q> val;
	vector<L> lazy;
	void refresh(int i){ val[i] = merge(val[i << 1], val[i << 1 | 1]); }
	void apply(int i, L f){
		val[i] = act(f, val[i]);
		if(i < size) lazy[i] = composite(f, lazy[i]);
	}
	void push(int i){
		apply(i << 1, lazy[i]), apply(i << 1 | 1, lazy[i]);
		int h = log - __lg(i);
		lazy[i] = identity_action((i << h) - size, (i + 1 << h) - size);
	}
};
using Q = pair<int, int>; // Monoid (Query Type)
Q merge(Q x, Q y){ // merges adjacent intervals
	return {max(x.first, y.first), max(x.second, y.second)};
}
const int minf = numeric_limits<int>::min() / 2;
Q identity(){ // Monoid Identity
	return {minf, minf};
}
using L = int; // Semigroup (Lazy Type)
L composite(L f, L g){ // composites superset and subset 
	return f ^ g;
}
L identity_action(int l, int r){
	return 0;
}
Q act(L f, Q x){ // semigroup action of L on Q, act superset onto subset
	if(f){
		swap(x.first, x.second);
	}
	return x;
}
// lazy_segment_tree<Q, merge, identity, L, composite, identity_action, act> seg(a);

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	graph<int> g(n);
	for(auto i = 1; i < n; ++ i){
		int u, v, w;
		cin >> u >> v >> w, -- u, -- v;
		g.link(u, v, w);
	}
	dfs_tree<int> dtx, dty;
	dtx.init(&g);
	dty.init(&g);
	dtx.dfs(0);
	int x = max_element(dtx.depth.begin(), dtx.depth.end()) - dtx.depth.begin();
	dtx.dfs(x);
	int y = max_element(dtx.depth.begin(), dtx.depth.end()) - dtx.depth.begin();
	debug(x, y);
	dty.dfs(y);
	vector<Q> X(n), Y(n);
	for(auto i = 0; i < n; ++ i){
		if(!dtx.dist[dtx.order[i]]){
			X[i] = {dtx.depth[dtx.order[i]], minf};
		}
		else{
			X[i] = {minf, dtx.depth[dtx.order[i]]};
		}
		if(!dty.dist[dty.order[i]]){
			Y[i] = {dty.depth[dty.order[i]], minf};
		}
		else{
			Y[i] = {minf, dty.depth[dty.order[i]]};
		}
	}
	debug(X);
	debug(Y);
	lazy_segment_tree<Q, merge, identity, L, composite, identity_action, act> segx(X), segy(Y);
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int id;
		cin >> id, -- id;
		int u = g.edges[id].from, v = g.edges[id].to;
		debug(u, v);
		if(dtx.depth[u] < dtx.depth[v]){
			swap(u, v);
		}
		debug("updating", u);
		segx.update(dtx.pos[u], dtx.end[u], 1);
		if(dty.depth[u] < dty.depth[v]){
			swap(u, v);
		}
		debug("updating", u);
		segy.update(dty.pos[u], dty.end[u], 1);
		auto [a, b] = segx.query_all();
		auto [c, d] = segy.query_all();
		cout << max(a, c) << "\n";
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