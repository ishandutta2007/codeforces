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

template<class Q, Q (*merge)(Q, Q), Q (*identity)()>
struct segment_tree{
	segment_tree(): segment_tree(0){}
	segment_tree(int n): segment_tree(vector<Q>(n)){}
	segment_tree(const vector<Q> &v): n((int)v.size()){ // O(n)
		log = __lg(n + 1) + 1, size = 1 << log;
		val = vector<Q>(size << 1, identity());
		copy(v.begin(), v.end(), val.begin() + size);
		for(int i = size - 1; i >= 1; -- i) refresh(i);
	}
	void set(int p, Q x){ // O(log n)
		assert(0 <= p && p < n);
		val[p += size] = x;
		for(int i = 1; i <= log; ++ i) refresh(p >> i);
	}
	Q query(int p){ // O(1)
		assert(0 <= p && p < n);
		return val[p + size];
	}
	Q query(int l, int r){ // O(log n)
		assert(0 <= l && l <= r && r <= n);
		Q sml = identity(), smr = identity();
		for(l += size, r += size; l < r; l >>= 1, r >>= 1){
			if(l & 1) sml = merge(sml, val[l ++]);
			if(r & 1) smr = merge(val[-- r], smr);
		}
		return merge(sml, smr);
	}
	Q query_all(){ return val[1]; } // O(1)
	template<class F> int partition_point_pref(int l, F f){ // O(log n)
		assert(0 <= l && l <= n);
		if(l == n) return n;
		l += size;
		Q sm = identity();
		do{
			while(~l & 1) l >>= 1;
			if(!f(merge(sm, val[l]))){
				while(l < size){
					l = l << 1;
					if(f(sm + val[l])) sm = merge(sm, val[l ++]);
				}
				return l - size;
			}
			sm = merge(sm, val[l ++]);
		}while((l & -l) != l);
		return n;
	} // f(sum[l, r)) is T, T, ..., T, F, F, ..., F, returns max r with T
	template<class F> int partition_point_suff(int r, F f){ // O(log n)
		assert(0 <= r && r <= n);
		if(r == 0) return 0;
		r += size;
		Q sm = identity();
		do{
			-- r;
			while (r > 1 && r & 1) r >>= 1;
			if(!f(merge(val[r], sm))){
				while(r < size){
					r = r << 1 | 1;
					if(f(merge(val[r], sm))) sm = merge(val[r --], sm);
				}
				return r + 1 - size;
			}
			sm = merge(val[r], sm);
		}while((r & -r) != r);
		return 0;
	} // f(sum[l, r)) is F, F, ..., F, T, T, ..., T, returns min l with T
	int n, size, log;
	vector<Q> val;
	void refresh(int i){ val[i] = merge(val[i << 1], val[i << 1 | 1]); }
};
struct Q{
	int len = 0;
	int ans = 0;
	int prefans = 0;
	int suffans = 0;
	int prefminus = 0;
	int suffplus = 0;
	Q(){}
	Q(long long x){
		if(x){
			++ ans;
		}
		prefans = suffans = ans;
		if(x < 0){
			++ prefminus;
		}
		if(x > 0){
			++ suffplus;
		}
		++ len;
	}
	Q(int a, int b, int c, int d, int e, int f)
	: len(a), ans(b), prefans(c), suffans(d), prefminus(e), suffplus(f){
	}
};
Q merge(Q x, Q y){ // merges adjacent intervals
	return {
		x.len + y.len
		, max({x.ans, y.ans, x.suffans + y.prefminus, x.suffplus + y.prefans})
		, x.suffplus == x.len ? x.suffplus + y.prefans : x.ans == x.len ? x.ans + y.prefminus : x.prefans
		, y.prefminus == y.len ? x.suffans + y.prefminus : y.ans == y.len ? x.suffplus + y.ans : y.suffans
		, x.prefminus == x.len ? x.prefminus + y.prefminus : x.prefminus
		, y.suffplus == y.len ? y.suffplus + x.suffplus : y.suffplus
	};
}
Q identity(){ // Monoid Identity
	return {};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<long long> dif(n - 1);
	vector<Q> temp(n - 1);
	for(auto i = 0; i < n - 1; ++ i){
		temp[i] = {dif[i] = a[i + 1] - a[i]};
	}
	debug(dif);
	segment_tree<Q, merge, identity> seg(temp);
	int qn;
	cin >> qn;
	for(auto qi = 0; qi < qn; ++ qi){
		int l, r, x;
		cin >> l >> r >> x, -- l;
		if(l){
			seg.set(l - 1, {dif[l - 1] += x});
		}
		if(r < n){
			seg.set(r - 1, {dif[r - 1] -= x});
		}
		debug(dif);
		cout << seg.query(0, n - 1).ans + 1 << "\n";
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