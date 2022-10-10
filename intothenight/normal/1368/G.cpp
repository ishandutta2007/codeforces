#include "bits/stdc++.h"
using namespace std;

struct lazy_segment{
	int n, h;
	vector<int> roots;

#define R array<int, 2>		// Range type
#define L int 				// Lazy type add to range
#define Q array<int, 2>		// Query type min_val, occur
	L lop(const L &lazy, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return lazy + x;
	}
	Q qop(const Q &lval, const R &r0, const Q &rval, const R &r1){ // always r0[1] == r1[0]
		return lval[0] == rval[0] ? Q{lval[0], lval[1] + rval[1]} : min(lval, rval);
	}
	Q aop(const Q &val, const R &r0, const L &x, const R &r1){ // r1 always contain r0
		return {val[0] + x, val[1]};
	}
	const pair<L, Q> id{0, Q{numeric_limits<int>::max() / 2, 0}};
	Q init(const int &p){
		return {0, 1};
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
	int n, m;
	cin >> n >> m;
	int tot = n * m / 2;
	vector<vector<int>> numb(n, vector<int>(m));
	vector<string> board(n);
	for(auto i = 0; i < n; ++ i){
		cin >> board[i];
		static int ind = 0;
		for(auto j = 0; j < m; ++ j){
			if(board[i][j] == 'U'){
				numb[i][j] = numb[i + 1][j] = ind ++;
			}
			else if(board[i][j] == 'L'){
				numb[i][j] = numb[i][j + 1] = ind ++;
			}
		}
	}
	array<vector<vector<int>>, 2> adj{vector<vector<int>>(tot), vector<vector<int>>(tot)};
	array<vector<int>, 2> indeg{vector<int>(tot), vector<int>(tot)};
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < m; ++ j){
			if(board[i][j] == 'U'){
				if(i + 2 < n){
					adj[i + j & 1][numb[i + 2][j]].push_back(numb[i][j]);
					++ indeg[i + j & 1][numb[i][j]];
				}
				if(i - 1 >= 0){
					adj[i + j + 1 & 1][numb[i - 1][j]].push_back(numb[i + 1][j]);
					++ indeg[i + j + 1 & 1][numb[i + 1][j]];
				}
			}
			else if(board[i][j] == 'L'){
				if(j + 2 < m){
					adj[i + j & 1][numb[i][j + 2]].push_back(numb[i][j]);
					++ indeg[i + j & 1][numb[i][j]];
				}
				if(j - 1 >= 0){
					adj[i + j + 1 & 1][numb[i][j - 1]].push_back(numb[i][j + 1]);
					++ indeg[i + j + 1 & 1][numb[i][j + 1]];
				}
			}
		}
	}
	array<vector<int>, 2> roots;
	for(auto p = 0; p < 2; ++ p){
		for(auto u = 0; u < tot; ++ u){
			if(!indeg[p][u]){
				roots[p].push_back(u);
			}
		}
	}
	vector<int> tin(tot), tout(tot); // euler tour for odd vertices
	for(auto u: roots[1]){
		static int timer = 0;
		function<void(int, int)> dfs = [&](int u, int p){
			tin[u] = timer ++;
			for(auto v: adj[1][u]){
				if(v != p){
					dfs(v, u);
				}
			}
			tout[u] = timer;
		};
		dfs(u, u);
	}
	lazy_segment tr(tot);
	long long res = 1LL * tot * tot;
	for(auto u: roots[0]){
		function<void(int, int)> dfs = [&](int u, int p){
			tr.update(tin[u], tout[u], 1);
			auto [min_val, cnt] = tr.query(0, tot);
			if(!min_val) res -= cnt;
			for(auto v: adj[0][u]){
				if(v != p){
					dfs(v, u);
				}
			}
			tr.update(tin[u], tout[u], -1);
		};
		dfs(u, u);
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////