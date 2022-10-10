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

template<class Q,
					Q (*merge)(Q, Q),
					Q (*identity)(),
					class L,
					L (*composite)(L, L),
					L (*identity_action)(int, int),
					Q (*act)(L, Q)>
struct lazy_segment_tree_base{
	Q query(int p){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i >= 1; -- i) push(p >> i);
		return tree[p];
	}
	Q query(int l, int r){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return identity();
		l += size, r += size;
		for(int i = log; i >= 1; -- i) {
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		Q sml = identity(), smr = identity();
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = merge(sml, tree[l ++]);
			if(r & 1) smr = merge(tree[-- r], smr);
		}
		return merge(sml, smr);
	}
	Q query_all(){ return tree[1]; } // O(1)
	void set(int p, Q x){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i >= 1; -- i) push(p >> i);
		tree[p] = x;
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int p, L f){ // O(log n)
		assert(0 <= p && p < n);
		p += size;
		for(int i = log; i >= 1; -- i) push(p >> i);
		tree[p] = act(f, tree[p]);
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	void update(int l, int r, L f){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		if(l == r) return;
		l += size, r += size;
		for(int i = log; i >= 1; -- i){
			if(l >> i << i != l) push(l >> i);
			if(r >> i << i != r) push(r - 1 >> i);
		}
		int l2 = l, r2 = r;
		for(; l < r; l >>= 1, r >>= 1){
			if(l & 1) apply(l ++, f);
			if(r & 1) apply(-- r, f);
		}
		l = l2, r = r2;
		for(int i = 1; i <= log; ++ i){
			if(l >> i << i != l) refresh(l >> i);
			if(r >> i << i != r) refresh(r - 1 >> i);
		}
	}
	template<class G> int max_pref(int l, G g){ // O(log n)
		assert(0 <= l && l <= n), assert(g(identity()));
		if(l == n) return n;
		l += size;
		for(int i = log; i >= 1; -- i) push(l >> i);
		Q sm = identity();
		do{
			while(~l & 1) l >>= 1;
			if(!g(merge(sm, tree[l]))){
				while(l < size){
					push(l);
					l = l << 1;
					if(g(merge(sm, tree[l]))) sm = merge(sm, tree[l ++]);
				}
				return l - size;
			}
			sm = merge(sm, tree[l]);
			++ l;
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class G> int min_suff(int r, G g){ // O(log n)
		assert(0 <= r && r <= n), assert(g(identity()));
		if(r == 0) return 0;
		r += size;
		for(int i = log; i >= 1; -- i) push(r - 1 >> i);
		Q sm = identity();
		do{
			-- r;
			while(r > 1 && r & 1) r >>= 1;
			if(!g(merge(tree[r], sm))){
				while(r < size){
					push(r);
					r = r << 1 | 1;
					if(g(merge(tree[r], sm))) sm = merge(tree[r --], sm);
				}
				return r + 1 - size;
			}
			sm = merge(tree[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
	int n, size, log;
	vector<Q> tree;
	vector<L> lazy;
	void refresh(int i){ tree[i] = merge(tree[i << 1], tree[i << 1 | 1]); }
	void apply(int i, L f){
		tree[i] = act(f, tree[i]);
		if(i < size) lazy[i] = composite(f, lazy[i]);
	}
	void push(int i){
		apply(i << 1, lazy[i]), apply(i << 1 | 1, lazy[i]);
		int h = log - __lg(i);
		lazy[i] = identity_action((i << h) - size, (i + 1 << h) - size);
	}
	lazy_segment_tree_base(): lazy_segment_tree_base(0){}
	lazy_segment_tree_base(int n): lazy_segment_tree_base(vector<Q>(n)){}
	lazy_segment_tree_base(const vector<Q> &v): n((int)v.size()){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		tree = vector<Q>(size << 1, identity()), lazy = vector<L>(size);
		copy(v.begin(), v.end(), tree.begin() + size);
		for(int i = 1; i < size; ++ i){
			int h = log - __lg(i);
			lazy[i] = identity_action((i << h) - size, (i + 1 << h) - size);
		}
		for(int i = size - 1; i >= 1; -- i) refresh(i);
	}
};
struct Q{
	long long min, len;
};
Q merge(Q x, Q y){ // merges adjacent intervals
	if(x.min < y.min) return x;
	else if(x.min > y.min) return y;
	else return {x.min, x.len + y.len};
}
Q identity(){ // Monoid Identity
	return {numeric_limits<long long>::max() / 2, 0};
}
using L = long long; // Semigroup (Lazy Type)
L composite(L f, L g){ // composites superset and subset 
	return f + g;
}
L identity_action(int l, int r){
	return 0;
}
Q act(L f, Q x){ // semigroup action of L on Q, act superset onto subset
	x.min += f;
	return x;
}
using lazy_segment_tree = lazy_segment_tree_base<Q, merge, identity, L, composite, identity_action, act>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<array<int, 2>> a(n);
	vector<int> cmpr;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0] >> a[i][1], a[i][1] += a[i][0];
		cmpr.push_back(a[i][0]), cmpr.push_back(a[i][1]);
	}
	sort(cmpr.begin(), cmpr.end()), cmpr.erase(unique(cmpr.begin(), cmpr.end()), cmpr.end());
	auto ind = [&](int x){
		return lower_bound(cmpr.begin(), cmpr.end(), x) - cmpr.begin();
	};
	const int mx = (int)cmpr.size();
	vector<Q> init(mx);
	for(auto i = 0; i < mx; ++ i){
		init[i] = {0, cmpr[i + 1] - cmpr[i]};
	}
	lazy_segment_tree seg(init);
	int qn;
	cin >> qn;
	vector<vector<array<int, 2>>> query(n);
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r;
		cin >> l >> r, -- l, -- r;
		query[l].push_back({r, qi});
	}
	vector<long long> res(qn);
	for(auto l = n - 1; l >= 0; -- l){
		seg.update(ind(a[l][0]), ind(a[l][1]), 1);
		for(auto [r, qi]: query[l]){
			auto cur = seg.query(ind(a[l][0]), ind(a[r][0]));
			debug(l, r, qi);
			debug(cur.min, cur.len);
			if(!cur.min){
				res[qi] = cur.len;
			}
		}
	}
	for(auto x: res){
		cout << x << "\n";
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