#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct Tree {
	int n;
	vector<ll> t;
	Tree(int n) : n(n), t(2 * n) {}
	void update(int l, int r, ll val) {
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) t[l++] += val;
			if (r & 1) t[--r] += val;
		}
	}
	ll query(int idx) {
		ll res;
		for (res = t[idx += n]; idx /= 2;) res += t[idx];
		return res;
	}
};


void ProGamerMove() {
	int n, q;
	cin >> n >> q;
	Tree t(n);
	vector<ll> cdiff(n + 1);
	set<tuple<int, int, int>> ints;
	ints.insert({0, n, 1});
	auto er = [&](int l, int r) {
		auto it = ints.lower_bound({l, r, 0});
		t.update(l, r, cdiff[get<2>(*it)]);
		ints.erase(it);
	};
	auto ins = [&](int l, int r, int c) {
		if (l < r) {
			t.update(l, r, -cdiff[c]);
			ints.insert({l, r, c});
		}
	};
	while (q--) {
		string s; cin >> s;
		if (s == "Add") {
			int c, v; cin >> c >> v;
			cdiff[c] += v;
		} else if (s == "Color") {
			int l, r, c; cin >> l >> r >> c, --l;
			auto it = ints.lower_bound({l, 0, 0});
			if (it != ints.begin()) it = prev(it);
			for(; it != ints.end(); ){
				auto [cl, cr, cc] = *it;
				if (r <= cl) break;
				if (l <= cl && cr <= r) er(cl, cr);
				else if (cl <= l && r <= cr) {
					er(cl, cr);
					ins(cl, l, cc);
					ins(r, cr, cc);
				} else if (cl <= l && cr <= r) {
					er(cl, cr);
					ins(cl, l, cc);
				} else if (l <= cl && cl <= r) {
					er(cl, cr);
					ins(r, cr, cc);
				}
				it = ints.lower_bound({cr, 0, 0});
			}
			ins(l, r, c);
		} else if (s == "Query") {
			int l; cin >> l, --l;
			auto it = ints.lower_bound({l, 0, 0});
			if (it != ints.begin()) it = prev(it);
			int col = 0;
			for(; it != ints.end(); it = next(it)){
				auto [cl, cr, cc] = *it;
				if (cl <= l && l <= cr) col = cc;
				if (l <= cl) break;
			}
			cout << t.query(l) + cdiff[col] << "\n";
		} else assert(0);
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}