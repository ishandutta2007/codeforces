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
	graph transposed() const{ // returns the transpose of the directed graph
		graph res(n);
		for(auto &e: edges) res.orient(e.to, e.from, e.cost);
		res.ignore = ignore;
		return res;
	}
};

// Requires graph
template<class T, T (*merge)(T, T), T (*identity)()>
struct dfs_forest_base{
	int n;
	vector<T> dist;
	vector<int> pv, pe, order, pos, end, sz, root, depth, min_depth, was;
	dfs_forest_base(int n){ init(n); }
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
	void dfs(graph<T> &g, int u, bool clear_order = true){
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
	void dfs_all(graph<T> &g){
		for(auto u = 0; u < n; ++ u) if(!~depth[u]) dfs(u, false);
	}
};
long long add_merge(long long x, long long y){
	return x + y;
}
long long add_id(){
	return {};
}
using dfs_forest = dfs_forest_base<long long, add_merge, add_id>;

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct segment_tree_base{
	segment_tree_base(): segment_tree_base(0){}
	segment_tree_base(int n): segment_tree_base(vector<Q>(n)){}
	segment_tree_base(const vector<Q> &v): n((int)v.size()){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		tree = vector<Q>(size << 1, identity());
		copy(v.begin(), v.end(), tree.begin() + size);
		for(int i = size - 1; i >= 1; -- i) refresh(i);
	}
	void set(int p, Q x){ // O(log n)
		assert(0 <= p && p < n);
		tree[p += size] = x;
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	Q query(int p){ // O(1)
		assert(0 <= p && p < n);
		return tree[p + size];
	}
	Q query(int l, int r){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		Q sml = identity(), smr = identity();
		for(l += size, r += size; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = merge(sml, tree[l ++]);
			if(r & 1) smr = merge(tree[-- r], smr);
		}
		return merge(sml, smr);
	}
	Q query_all(){ return tree[1]; } // O(1)
	template<class F> int max_pref(int l, F f){ // O(log n)
		assert(0 <= l && l <= n);
		if(l == n) return n;
		l += size;
		Q sm = identity();
		do{
			while(~l & 1) l >>= 1;
			if(!f(merge(sm, tree[l]))){
				while(l < size){
					l = l << 1;
					if(f(merge(sm, tree[l]))) sm = merge(sm, tree[l ++]);
				}
				return l - size;
			}
			sm = merge(sm, tree[l ++]);
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class F> int min_suff(int r, F f){ // O(log n)
		assert(0 <= r && r <= n);
		if(r == 0) return 0;
		r += size;
		Q sm = identity();
		do{
			-- r;
			while (r > 1 && r & 1) r >>= 1;
			if(!f(merge(tree[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(f(merge(tree[r], sm))) sm = merge(tree[r --], sm);
				}
				return r + 1 - size;
			}
			sm = merge(tree[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
	int n, size, log;
	vector<Q> tree;
	void refresh(int i){ tree[i] = merge(tree[i << 1], tree[i << 1 | 1]); }
};
using Q = int; // Monoid (Query Type)
Q merge(Q x, Q y){ // merges adjacent intervals
	return x + y;
}
Q identity(){ // Monoid Identity
	return 0;
}
using segment_tree = segment_tree_base<Q, merge, identity>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	graph<long long> g(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		long long w;
		cin >> u >> v >> w, -- u, -- v;
		g.link(u, v, w);
	}
	dfs_forest df(n);
	df.dfs(g, 0);
	int u = max_element(df.dist.begin(), df.dist.end()) - df.dist.begin();
	df.dfs(g, u);
	vector<long long> dist = df.dist;
	int v = max_element(df.dist.begin(), df.dist.end()) - df.dist.begin();
	df.dfs(g, v);
	for(auto u = 0; u < n; ++ u){
		ctmax(dist[u], df.dist[u]);
	}
	debug(dist);
	debug(u, v);
	int root = -1;
	for(auto u = 0; u < n; ++ u){
		for(auto id: g.adj[u]){
			auto &e = g.edges[id];
			int v = u ^ e.from ^ e.to;
			if(dist[u] > dist[v]){
				goto FAIL;
			}
		}
		root = u;
		break;
		FAIL:;
	}
	debug(root);
	df.dfs(g, root);
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int u, int v){ return dist[u] == dist[v] ? df.depth[u] > df.depth[v] : dist[u] > dist[v]; });
	for(auto u = 0; u < n; ++ u){
		if(u != root){
			assert(dist[u] >= dist[df.pv[u]]);
		}
	}
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		long long th;
		cin >> th;
		segment_tree seg(n);
		int res = 0;
		for(auto i = 0, j = 0; i < n; ++ i){
			seg.set(df.pos[order[i]], seg.query(df.pos[order[i]]) + 1);
			while(dist[order[j]] - dist[order[i]] > th){
				seg.set(df.pos[order[j]], seg.query(df.pos[order[j]]) - 1);
				++ j;
			}
			debug(j, i, order[j], order[i]);
			ctmax(res, seg.query(df.pos[order[i]], df.end[order[i]]));
		}
		cout << res << "\n";
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