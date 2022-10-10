#include "bits/stdc++.h"
using namespace std;

struct S{
	int len = 0;
	int pref_l = 0, pref_r = 0;
	int suff_l = 0, suff_r = 0;
	int pref_src = 0, pref_snk = 0;
	int suff_src = 0, suff_snk = 0;
	int max_src = 0, max_snk = 0;
	void flip(){
		swap(pref_l, pref_r);
		swap(suff_l, suff_r);
		swap(pref_src, pref_snk);
		swap(suff_src, suff_snk);
		swap(max_src, max_snk);
	}
	friend ostream &operator<<(ostream &out, const S &x){
		out << "[len: " << x.len << "], [pref l: " << x.pref_l << ", r: " << x.pref_r << "], ";
		out << "[suff l: " << x.suff_l << ", r: " << x.suff_r << "], ";
		out << "[pref src: " << x.pref_src << ", snk: " << x.pref_snk << "], ";
		out << "[suff src: " << x.suff_src << ", snk: " << x.suff_snk << "], ";
		out << "[max src: " << x.max_src << ", snk: " << x.max_snk << "]";
		return out;
	}
};
int getif(int x, int y, int z){
	static const int minf = numeric_limits<int>::min() / 2;
	return y == z ? x : minf;
}
S operator+(const S &x, const S &y){
	return {
		x.len + y.len
		, max(x.pref_l, getif(x.len + y.pref_l, x.len, x.pref_l))
		, max(x.pref_r, getif(x.len + y.pref_r, x.len, x.pref_r))
		, max(getif(x.suff_l + y.len, y.len, y.suff_l), y.suff_l)
		, max(getif(x.suff_r + y.len, y.len, y.suff_r), y.suff_r)
		, max({x.pref_src, getif(x.len + y.pref_r, x.len, x.pref_src), getif(x.len + y.pref_src, x.len, x.pref_l)})
		, max({x.pref_snk, getif(x.len + y.pref_l, x.len, x.pref_snk), getif(x.len + y.pref_snk, x.len, x.pref_r)})
		, max({getif(x.suff_l + y.len, y.len, y.suff_src), getif(x.suff_src + y.len, y.len, y.suff_r), y.suff_src})
		, max({getif(x.suff_r + y.len, y.len, y.suff_snk), getif(x.suff_snk + y.len, y.len, y.suff_l), y.suff_snk})
		, max({x.max_src, y.max_src, x.suff_l + y.pref_src, x.suff_src + y.pref_r})
		, max({x.max_snk, y.max_snk, x.suff_r + y.pref_snk, x.suff_snk + y.pref_l})
	};
}

struct lazy_segment{
	int n, h;
	vector<int> roots;

#define R array<int, 2>		// Range type
#define L int 				// Lazy type
#define Q S		// Query type min, first occurence, max
	L lop(const L &lazy, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return lazy ^ x;
	}
	Q qop(const Q &lval, const R &r0, const Q &rval, const R &r1){ // always r0[1] == r1[0]
		return lval + rval;
	}
	Q aop(const Q &val, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		Q res(val);
		res.flip();
		return res;
	}
	const pair<L, Q> id{};
	Q init(const int &p){
		return {};
	}

	vector<R> range;
	vector<L> lazy;
	vector<Q> val;
	template<typename IT>
	lazy_segment(IT begin, IT end): n(distance(begin, end)), h(__lg(n) + 1), range(n << 1), lazy(n << 1, id.first), val(n, id.second){
		init_range();
		val.insert(val.end(), begin, end);
		build(0, n);
	}
	lazy_segment(int n): n(n), h(__lg(n) + 1), range(n << 1), lazy(n << 1, id.first), val(n << 1){
		init_range();
		for(int i = n; i < n << 1; ++ i) val[i] = init(i - n);
		build(0, n);
	}
	void init_roots(){
		vector<int> roots_r;
		for(auto l = n, r = n << 1; l < r; l >>= 1, r >>= 1){
			if(l & 1) roots.push_back(l ++);
			if(r & 1) roots_r.push_back(-- r);
		}
		roots.insert(roots.end(), roots_r.rbegin(), roots_r.rend());
	}
	void init_range(){
		for(int i = n; i < n << 1; ++ i) range[i] = {i - n, i - n + 1};
		for(int i = n - 1; i > 0; -- i) range[i] = {range[i << 1][0], range[i << 1 | 1][1]};
	}
	void refresh(int p){
		if(p < n) val[p] = qop(val[p << 1], range[p << 1], val[p << 1 | 1], range[p << 1 | 1]);
		if(lazy[p] != id.first) val[p] = aop(val[p], range[p], lazy[p], range[p]);
	}
	void build(int l, int r){
		for(l += n, r += n - 1; l > 1; ){
			l >>= 1, r >>= 1;
			for(int i = r; i >= l; -- i) refresh(i);
		}
	}
	void push(int p){ // push internal node p
		if(lazy[p] != id.first){
			val[p << 1] = aop(val[p << 1], range[p << 1], lazy[p], range[p]);
			lazy[p << 1] = lop(lazy[p << 1], range[p << 1], lazy[p], range[p]);
			val[p << 1 | 1] = aop(val[p << 1 | 1], range[p << 1 | 1], lazy[p], range[p]);
			lazy[p << 1 | 1] = lop(lazy[p << 1 | 1], range[p << 1 | 1], lazy[p], range[p]);
			lazy[p] = id.first;
		}
	}
	void push(int l, int r){ // push the range [l, r)
		int s = h;
		for(l += n, r += n - 1; s > 0; -- s) for(int i = l >> s; i <= r >> s; ++ i) push(i);
	}
	void update(int l, int r, L x){
		if(l >= r || x == id.first) return;
		const R update_range{l, r};
		push(l, l + 1), push(r - 1, r);
		bool cl = false, cr = false;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(cl) refresh(l - 1);
			if(cr) refresh(r);
			if(l & 1){
				val[l] = aop(val[l], range[l], x, update_range);
				if(l < n) lazy[l] = lop(lazy[l], range[l], x, update_range);
				++ l;
				cl = true;
			}
			if(r & 1){
				-- r;
				val[r] = aop(val[r], range[r], x, update_range);
				if(r < n) lazy[r] = lop(lazy[r], range[r], x, update_range);
				cr = true;
			}
		}
		for(-- l; r > 0; l >>= 1, r >>= 1){
			if(cl) refresh(l);
			if(cr && (!cl || l != r)) refresh(r);
		}
	}
	Q query(int l, int r){
		push(l, l + 1), push(r - 1, r);
		Q resl = id.second, resr = id.second;
		R l_range{l, l}, r_range{r, r};
		for(l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) resl = qop(resl, l_range, val[l], range[l]), l_range[1] = range[l][1], ++ l;
			if(r & 1) -- r, resr = qop(val[r], range[r], resr, r_range), r_range[0] = range[r][0];
		}
		return qop(resl, l_range, resr, r_range);
	}
	void print(){
		for(int u = 0; u < 2 * n; ++ u){
			// cout << u << "-th node represent [" << range[u][0] << ", " << range[u][1] << "), val = " << format(val[u]) << ", lazy = " << lazy[u] << "\n";
		}
	}
#undef R
#undef L
#undef Q
};

/*
	int len = 0;
	int pref_l = 0, pref_r = 0;
	int suff_l = 0, suff_r = 0;
	int pref_src = 0, pref_snk = 0;
	int suff_src = 0, suff_snk = 0;
	int max_src = 0, max_snk = 0;
*/

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, qq;
	string temp;
	cin >> n >> qq >> temp;
	vector<S> a(n);
	for(auto i = 0; i < n; ++ i){
		int t = temp[i] == '<';
		a[i] = {1, t, !t, t, !t, 1, 1, 1, 1, 1, 1};
	}
	lazy_segment tr(a.begin(), a.end());
	while(qq --){
		int l, r;
		cin >> l >> r, -- l;
		tr.update(l, r, 1);
		cout << tr.query(l, r).max_snk << "\n";
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