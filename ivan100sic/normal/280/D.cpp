#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int v, l, r;
	bool operator< (const seg& b) const {
		return v < b.v;
	}
	seg operator+ (const seg& b) const {
		return {v+b.v, min(l, b.l), max(r, b.r)};
	}
};

struct node {
	seg any, pref, suff, both;

	node operator+ (const node& b) const {
		node t;
		t.both = both + b.both;
		t.suff = max(b.suff, suff + b.both);
		t.pref = max(pref, both + b.pref);
		t.any = max({any, b.any, suff + b.pref});
		return t;
	}

	node() {
		any = pref = suff = both = {0, 123123123, -123123123};
	}

	node(int i, int x) {
		both = {x, i, i};
		if (x > 0) {
			any = pref = suff = both;
		} else {
			any = pref = {0, i, i-1};
			suff = {0, i+1, i};
		}
	}
};

const int maxn = 131072;

struct segtree {
	vector<node> a;

	segtree() : a(2*maxn) {}

	node query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l)
			return {};
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
	}

	void update(int x, int y) {
		a[x+maxn] = node(x, y);
		x += maxn;
		while (x > 1) {
			x >>= 1;
			a[x] = a[2*x] + a[2*x+1];
		}
	}
};

int n, q;
int a[100005];
segtree pos, neg;

struct parce {
	int l, r;
	bool poz;
	seg val;

	parce(int l, int r, bool poz) : l(l), r(r), poz(poz) {
		val = (poz ? pos : neg).query(l, r).any;
	}

	bool operator< (const parce& b) const {
		return val.v < b.val.v;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		pos.update(i, a[i]);
		neg.update(i, -a[i]);
	}

	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, k;
			cin >> l >> r >> k;
			vector<parce> v;
			v.emplace_back(l, r, true);
			int ans = 0;
			while (k--) {
				auto it = max_element(v.begin(), v.end());
				auto p = *it;
				if (p.val.v <= 0)
					break;
				ans += p.val.v;
				v.erase(it);
				v.emplace_back(p.l, p.val.l-1, p.poz);
				v.emplace_back(p.val.l, p.val.r, !p.poz);
				v.emplace_back(p.val.r+1, p.r, p.poz);
			}
			cout << ans << '\n';
		} else {
			int x, y;
			cin >> x >> y;
			a[x] = y;
			pos.update(x, y);
			neg.update(x, -y);
		}
	}
}