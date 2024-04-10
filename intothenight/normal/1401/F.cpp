#include <bits/stdc++.h>
using namespace std;

struct segment_tree{
	int n;
	vector<int> roots;

	using Q = long long; // Query Type
	Q merge(const Q &lval, const Q &rval, int l, int m, int r){
		return lval + rval;
	} // merge two nodes representing the intervals [l, m) and [m, r)
	Q id{};
	Q init(int p){
		return id;
	}

	vector<array<int, 2>> range; // Node u represents the range range[u] = [l, r)
	vector<Q> val;
	void init_range(){
		for(int i = n; i < n << 1; ++ i) range[i] = {i - n, i - n + 1};
		for(int i = n - 1; i > 0; -- i) range[i] = {range[i << 1][0], range[i << 1 | 1][1]};
	}
	void build(int l, int r){
		for(l += n, r += n - 1; l > 1; ){
			l >>= 1, r >>= 1;
			for(int i = r; i >= l; -- i) val[i] = merge(val[i << 1], val[i << 1 | 1], range[i << 1][0], range[i << 1][1], range[i << 1 | 1][1]);
		}
	}
	Q operator[](int p) const{
		return val[p + n];
	}
	template<typename IT>
	segment_tree(IT begin, IT end): n(distance(begin, end)), range(n << 1), val(n << 1, id){
		init_range();
		for(int i = 0; i < n; ++ i) val[i + n] = *(begin ++);
		build(0, n);
	}
	segment_tree(int n): n(n), range(n << 1), val(n << 1, id){
		init_range();
		for(int i = 0; i < n; ++ i) val[i + n] = init(i);
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
	void update(int p, Q x){
		for(val[p += n] = x; p >>= 1; ) val[p] = merge(val[p << 1], val[p << 1 | 1], range[p << 1][0], range[p << 1][1], range[p << 1 | 1][1]);
	}
	Q query(int ql, int qr){
		if(ql >= qr) return id;
		int mid;
		Q res_l = id, res_r = id;
		for(int l = ql + n, r = qr + n; l < r; l >>= 1, r >>= 1){
			if(l & 1) res_l = merge(res_l, val[l], ql, range[l][0], range[l][1]), mid = range[l][1], ++ l;
			if(r & 1) -- r, res_r = merge(val[r], res_r, range[r][0], range[r][1], qr), mid = range[r][0];
		}
		return merge(res_l, res_r, ql, mid, qr);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, qq;
	cin >> n >> qq;
	vector<int> a(1 << n);
	for(auto i = 0; i < 1 << n; ++ i){
		cin >> a[i];
	}
	segment_tree tr(a.begin(), a.end());
	int flip = 0;
	while(qq --){
		int type;
		cin >> type;
		if(type == 1){
			int p, x;
			cin >> p >> x, -- p;
			tr.update(p ^ flip, x);
		}
		else if(type == 2){
			int x;
			cin >> x;
			flip ^= (1 << x) - 1;
		}
		else if(type == 3){
			int x;
			cin >> x;
			flip ^= 1 << x;
		}
		else{
			int ql, qr;
			cin >> ql >> qr, -- ql;
			function<long long(int, int, int, int, int)> solve = [&](int ql, int qr, int l, int r, int t){
				if(qr <= l || r <= ql) return 0LL;
				if(ql <= l && r <= qr){
					return tr.query(l ^ t, (l ^ t) + r - l);
				}
				t |= flip & r - l >> 1;
				return solve(ql, qr, l, l + (r - l >> 1), t) + solve(ql, qr, l + (r - l >> 1), r, t);
			};
			cout << solve(ql, qr, 0, 1 << n, 0) << "\n";
		}
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