#include <bits/stdc++.h>
using namespace std;

struct segment_tree{
	int n;
	vector<int> roots;

	using Q = int; // Query Type
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
	int n, m;
	cin >> n >> m;
	const int mx = 1e6;

	vector<vector<array<int, 2>>> event_h(mx + 2);
	vector<int> hposy(n);
	for(auto i = 0; i < n; ++ i){
		int xl, xr;
		cin >> hposy[i] >> xl >> xr;
		event_h[xl].push_back({0, i}), event_h[xr + 1].push_back({1, i});
	}
	vector<vector<array<int, 2>>> vert(mx + 1);
	vert[0].push_back({0, mx});
	for(auto i = 0; i < m; ++ i){
		int x, yl, yr;
		cin >> x >> yl >> yr;
		vert[x].push_back({yl, yr});
	}
	vert[mx].push_back({0, mx});
	segment_tree tr(mx + 1);
	tr.update(0, 1), tr.update(mx, 1);
	long long vcnt = 2 * (n + m + 4), ecnt = n + m + 4;
	for(auto x = 0; x <= mx; ++ x){
		for(auto [type, ih]: event_h[x]){
			if(!type){
				tr.update(hposy[ih], tr[hposy[ih]] + 1);
			}
			else{
				tr.update(hposy[ih], tr[hposy[ih]] - 1);
			}
		}
		for(auto [yl, yr]: vert[x]){
			int t = tr.query(yl, yr + 1);
			vcnt += t, ecnt += 2 * t;
		}
	}
	cout << ecnt - vcnt + 1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////