#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct lazy_segment{
	int n, h;
	vector<int> roots;

#define R array<int, 2>		// Range type
#define L long long 				// Lazy type
#define Q long long		// Query type
	L lop(const L &lazy, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return lazy + x;
	}
	Q qop(const Q &lval, const R &r0, const Q &rval, const R &r1){ // always r0[1] == r1[0]
		return min(lval, rval);
	}
	Q aop(const Q &val, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return val + x;
	}
	const pair<L, Q> id{0, numeric_limits<long long>::max() / 8};
	Q init(const int &p){
		return 0;
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
	void push(int l, int r){
		int s = h;
		for(l += n, r += n - 1; s > 0; -- s){
			for(int i = l >> s; i <= r >> s; ++ i) if(lazy[i] != id.first){
				val[i << 1] = aop(val[i << 1], range[i << 1], lazy[i], range[i]);
				lazy[i << 1] = lop(lazy[i << 1], range[i << 1], lazy[i], range[i]);
				val[i << 1 | 1] = aop(val[i << 1 | 1], range[i << 1 | 1], lazy[i], range[i]);
				lazy[i << 1 | 1] = lop(lazy[i << 1 | 1], range[i << 1 | 1], lazy[i], range[i]);
				lazy[i] = id.first;
			}
		}
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
		push(l, l + 1);
		push(r - 1, r);
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
			//cout << u << "-th node represent [" << range[u][0] << ", " << range[u][1] << "), val = " << val[u] << ", lazy = " << lazy[u] << "\n";
		}
	}
#undef R
#undef L
#undef Q
};



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<long long> a(n);
	int x = 0;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		x ^= a[i] & 1;
	}
	a.push_back(x);
	++ n;
	sort(a.begin(), a.end(), greater{});
	int pos = n - 1;
	while(a[pos] != x){
		-- pos;
	}
	vector<long long> pref(n + 1);
	partial_sum(a.begin(), a.end(), pref.begin() + 1);
	auto sum = [&](int i, int j){
		return pref[j] - pref[i];
	};
	vector<long long> temp(n + 1);
	for(auto i = 0; i <= n; ++ i){
		int p = upper_bound(a.begin(), a.end(), i, greater{}) - a.begin();
		ctmax(p, i);
		temp[i] = 1LL * i * (i - 1) - sum(0, i) + sum(p, n) + 1LL * i * (p - i);
	}
	lazy_segment tr(temp.begin(), temp.end());
	bool flag = false;
	if(tr.query(0, n + 1) >= 0){
		cout << x << " ";
		flag = true;
	}
	while(1){
		auto inc = [&](){
			while(pos && a[pos - 1] == x){
				-- pos;
			}
			tr.update(min(x + 1, pos + 1), pos + 1, 1);
			tr.update(pos + 1, n + 1, -1);
			++ x;
			++ a[pos];
		};
		inc(), inc();
		if(x >= n){
			break;
		}
		if(tr.query(0, n + 1) >= 0){
			cout << x << " ";
			flag = true;
		}
	}
	if(!flag) cout << -1;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////