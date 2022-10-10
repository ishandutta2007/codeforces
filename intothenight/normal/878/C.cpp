#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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

struct disjoint_set{
	vector<int> p, L, R;
	disjoint_set(int n): p(n, -1), L(n), R(n){ iota(L.begin(), L.end(), 0), iota(R.begin(), R.end(), 0); }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		ctmin(L[u], L[v]), ctmax(R[u], R[v]);
		return true;
	}
	int left(int u){
		return L[root(u)];
	}
	int right(int u){
		return R[root(u)];
	}
};

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct segment_tree_base{
	segment_tree_base(): segment_tree_base(0){}
	segment_tree_base(int n, Q init = identity()): segment_tree_base(vector<Q>(n, init)){}
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
template<class Q> Q merge(Q x, Q y){ // merges adjacent intervals
	return {min(x[0], y[0]), max(x[1], y[1])};
}
template<class Q> Q identity(){ // Monoid Identity
	return {numeric_limits<int>::max(), numeric_limits<int>::min()};
}
template<class Q>
using segment_tree = segment_tree_base<Q, merge<Q>, identity<Q>>;

template<class Q>
struct fenwick_tree{
	fenwick_tree(): n(0){}
	fenwick_tree(int n): n(n), tree(n){}
	fenwick_tree(const vector<Q> &v): n((int)v.size()), tree(v){
		for(int i = 1; i <= n; ++ i) if(i + (i & -i) <= n) tree[i + (i & -i) - 1] += tree[i - 1];
	}
	void update(int p, Q x){
		assert(0 <= p && p < n);
		for(++ p; p <= n; p += p & -p) tree[p - 1] += x;
	}
	Q query(int r){
		Q s{};
		for(; r > 0; r -= r & -r) s += tree[r - 1];
		return s;
	}
	Q query(int l, int r){
		assert(0 <= l && l <= r && r <= n);
		return query(r) - query(l);
	}
	template<class F> int max_pref(F f){
		int p = 0;
		Q pref{};
		for(int i = __lg(n + 1); i >= 0; -- i) if(p + (1 << i) <= n && f(pref + tree[p + (1 << i) - 1])){
			pref += tree[p + (1 << i) - 1];
			p += 1 << i;
		}
		return p;
	} // f(sum[0, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	int n;
	vector<Q> tree;
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> s(n, vector<int>(k + 1));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < k; ++ j){
			cin >> s[i][j];
		}
		s[i][k] = i;
	}
	sort(s.begin(), s.end());
	vector<int> pos(n);
	for(auto i = 0; i < n; ++ i){
		pos[s[i][k]] = i;
	}
	vector<vector<int>> order(k, vector<int>(n));
	vector<vector<int>> kpos(k, vector<int>(n));
	for(auto x = 1; x < k; ++ x){
		iota(order[x].begin(), order[x].end(), 0);
		sort(order[x].begin(), order[x].end(), [&](int i, int j){ return s[i][x] < s[j][x]; });
		for(auto i = 0; i < n; ++ i){
			kpos[x][order[x][i]] = i;
		}
	}
	vector<segment_tree<array<int, 2>>> seg(k, segment_tree<array<int, 2>>(n));
	fenwick_tree<int> ds(n);
	disjoint_set dsu(n);
	int maxpos = -1;
	for(auto i: pos){
		ctmax(maxpos, i);
		debug(i);
		ds.update(i, 1);
		for(auto x = 1; x < k; ++ x){
			seg[x].set(kpos[x][i], {i, i});
			int p = seg[x].query(0, kpos[x][i])[1];
			if(i < p){
				debug("Smaller", i, p);
				while(dsu.root(p) != dsu.root(i)){
					debug(p, dsu.left(p), dsu.right(p));
					dsu.merge(dsu.left(p), dsu.left(p) - 1);
				}
			}
			p = seg[x].query(kpos[x][i] + 1, n)[0];
			if(p < i){
				debug("Larger", i, p);
				while(dsu.root(p) != dsu.root(i)){
					debug(p, dsu.left(p), dsu.right(p));
					dsu.merge(dsu.right(p), dsu.right(p) + 1);
				}
			}
		}
		cout << ds.query(dsu.left(maxpos), dsu.right(maxpos) + 1) << "\n";
		debug("\n");
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