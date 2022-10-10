#include "bits/stdc++.h"
using namespace std;

struct lazy_segment{
	int n, h;
	vector<int> roots;

#define R array<int, 2>		// Range type
#define L int 				// Lazy type
#define Q pair<array<int, 2>, int>		// Query type min, first occurence, max
	L lop(const L &lazy, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return lazy + x;
	}
	Q qop(const Q &lval, const R &r0, const Q &rval, const R &r1){ // always r0[1] == r1[0]
		return {min(lval.first, rval.first), max(lval.second, rval.second)};
	}
	Q aop(const Q &val, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return {{val.first[0] + x, val.first[1]}, val.second + x};
	}
	const pair<L, Q> id{0, Q{{{numeric_limits<int>::max() / 2, 0}}, 0}};
	Q init(const int &p){
		return {{0, p}, 0};
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
		if(l >= r) return;
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
	int find_last(){
		int i = int(roots.size()) - 1;
		while(i >= 0 && !val[roots[i]].second){
			-- i;
		}
		if(i < 0) return -1;
		int r = roots[i];
		while(r < n){
			push(r);
			r = val[r << 1 | 1].second ? r << 1 | 1 : r << 1;
		}
		return r - n;
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

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k, -- m;
	const int sz = n + 2 * k;
	lazy_segment tr(sz);
	tr.init_roots();
	set<array<int, 2>> s;
	while(k --){
		int x, y;
		cin >> x >> y, -- x, -- y;
		int t = y + abs(x - m);
		if(s.count({x, y})){
			s.erase({x, y});
			tr.update(t, tr.query(t, tr.query(t, sz).first[1]).first[1] + 1, -1);
		}
		else{
			s.insert({x, y});
			tr.update(t, tr.query(t, sz).first[1] + 1, 1);
		}
		cout << max(tr.find_last() - n + 1, 0) << "\n";
	}
	return 0;
}

/*
15     2       6       14
[0, 1) [1, 9)  [9, 13) [13, 15)
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////