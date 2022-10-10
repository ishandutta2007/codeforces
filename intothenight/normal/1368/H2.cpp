#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

struct lazy_segment_0{
	int n, h;
	vector<int> roots;

#define R array<int, 2>		// Range type
#define L int 				// Lazy type
#define Q int		// Query type
	L lop(const L &lazy, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return lazy ^ x;
	}
	Q qop(const Q &lval, const R &r0, const Q &rval, const R &r1){ // always r0[1] == r1[0]
		return lval + rval;
	}
	Q aop(const Q &val, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return x ? r0[1] - r0[0] - val : val;
	}
	const pair<L, Q> id{0, 0};
	Q init(const int &p){
		return {};
	}

	vector<R> range;
	vector<L> lazy;
	vector<Q> val;
	template<typename IT>
	lazy_segment_0(IT begin, IT end): n(distance(begin, end)), h(__lg(n) + 1), range(n << 1), lazy(n << 1, id.first), val(n, id.second){
		init_range();
		val.insert(val.end(), begin, end);
		build(0, n);
	}
	lazy_segment_0(int n): n(n), h(__lg(n) + 1), range(n << 1), lazy(n << 1, id.first), val(n << 1){
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

struct lazy_segment{
	int n, h;
	vector<int> roots;

#define R array<int, 2>		// Range type
#define L int 				// Lazy type
#define Q array<array<int, 4>, 4>		// Query type
	const int inf = numeric_limits<int>::max() / 2;
	L lop(const L &lazy, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return lazy ^ x;
	}
	Q qop(const Q &lval, const R &r0, const Q &rval, const R &r1){ // always r0[1] == r1[0]
		static array<array<int, 4>, 4> dp;
		dp.fill({inf, inf, inf, inf});
		for(auto s = 0; s < 4; ++ s){
			for(auto t = 0; t < 4; ++ t){
				for(auto u = 0; u < 2; ++ u){
					ctmin(dp[s][t], lval[s][(t & 1) + (u << 1)] + rval[s][u + (t & 2)]);
				}
			}
		}
		return dp;
	}
	Q aop(const Q &val, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return {val[x], val[x ^ 1], val[x ^ 2], val[x ^ 3]};
	}
	const pair<L, Q> id{0, {{{0, inf, inf, 0}, {0, inf, inf, 0}, {0, inf, inf, 0}, {0, inf, inf, 0}}}};
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
	int n, m, qq;
	cin >> n >> m >> qq;
	vector<lazy_segment_0> tr0;
	// left, right, top, bot
	// counts number of R
	vector<string> init(4);
	for(auto i = 0; i < 4; ++ i){
		cin >> init[i];
		vector<int> temp;
		for(auto c: init[i]){
			temp.push_back(c == 'R');
		}
		tr0.push_back({temp.begin(), temp.end()});
	}
	vector<lazy_segment> tr;
	// horizontal, vertical
	// calculate dp value
	string color("RB");
	for(auto rot = 1; rot >= 0; -- rot){
		vector<array<array<int, 4>, 4>> a;
		for(auto i = 0; i < m; ++ i){
			static array<array<int, 4>, 4> dp;
			for(auto s = 0; s < 4; ++ s){
				for(auto t = 0; t < 4; ++ t){
					dp[s][t] = (t % 3 ? n : 0) + (s & 1 ^ init[2][i] == color[t >> 1]) + (s >> 1 ^ init[3][i] == color[t >> 1]);
				}
			}
			a.push_back(dp);
		}
		tr.push_back({a.begin(), a.end()});
		swap(n, m), swap(init[0], init[2]), swap(init[1], init[3]);
	}
	auto get_answer = [&](){
		static array<int, 4> cnt;
		for(auto i = 0; i < 4; ++ i){
			cnt[i] = tr0[i].query(0, i < 2 ? n : m);
		}
		int res = numeric_limits<int>::max();
		for(auto rot = 0; rot < 2; ++ rot){ // (L->R), (U->D)
			auto x = tr[rot].query(0, m)[0];
			for(auto s = 0; s < 2; ++ s){
				for(auto t = 0; t < 2; ++ t){
					ctmin(res, (s ? n - cnt[0] : cnt[0]) + (t ? n - cnt[1] : cnt[1]) + x[s | t << 1]);
				}
			}
			swap(n, m), swap(cnt[0], cnt[2]), swap(cnt[1], cnt[3]);
		}
		return res;
	};
	cout << get_answer() << "\n";
	vector<int> dir(200);
	dir['R'] = 1, dir['U'] = 2, dir['D'] = 3;
	while(qq --){
		char type;
		int l, r;
		cin >> type >> l >> r, -- l;
		tr0[dir[type]].update(l, r, 1);
		tr[dir[type] < 2].update(l, r, 1 << (dir[type] & 1));
		cout << get_answer() << "\n";
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