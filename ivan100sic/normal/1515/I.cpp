// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct fenwick {
	vector<T> a;
	T e;
	F f;

	fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

	void add(int p, const T& v) {
		for (p++; p <= (int)a.size(); p += p & -p)
			a[p-1] = f(a[p-1], v);
	}

	T operator() (int p) const {
		T v = e;
		for (; p; p -= p & -p)
			v = f(v, a[p-1]);
		return v;
	}
};

struct diamond {
	ll a, w, v, id;

	bool operator< (const diamond& b) const {
		if (v != b.v) return v > b.v;
		return w < b.w;
	}
};

struct stores {
	ll weight_tot = 0;
	ll val_tot = 0;

	stores operator+ (const stores& b) const {
		return {weight_tot + b.weight_tot, val_tot + b.val_tot};
	}
};

int n, q;
diamond d[300005];
int dord[300005];

struct inner_tree {
	fenwick<stores> st;
	vector<int> uw;

	inner_tree() : st(1) {}

	inner_tree(diamond* b, diamond* e) : st(e-b) {
		for (auto t=b; t!=e; ++t) {
			uw.push_back(t->w);
		}
		sort(begin(uw), end(uw));
		uw.erase(unique(begin(uw), end(uw)), end(uw));
	}

	void add(int p, const stores& v) {
		p = lower_bound(begin(uw), end(uw), p) - begin(uw);
		st.add(p, v);
	}

	stores operator() (ll r) {
		int h = upper_bound(begin(uw), end(uw), r) - begin(uw);
		return st(h);
	}
};

namespace outer_tree {
	const int maxn = 1 << 18;

	inner_tree a[2 * maxn];

	void init() {
		for (int i=1; i<2*maxn; i++) {
			int w = 1 << (__builtin_clz(i) - 13);
			int l = i - (1 << (31 - __builtin_clz(i)));
			l *= w;
			int r = l + w;
			r = min(n+1, r);
			l = max(1, l);
			if (l < r) {
				a[i] = inner_tree(d+l, d+r);
			}
		}
	}

	void add(int x, int y, stores amt) {
		for (int p=x+maxn; p; p>>=1) {
			a[p].add(y, amt);
		}
	}

	void add(int i, ll k) {
		add(i, d[i].w, {k * d[i].w, k * d[i].v});
	}

	stores solve(ll cap, int x = 1, int xl = 0, int xr = maxn) {
		stores loc = a[x](cap);
		if (loc.weight_tot <= cap) {
			// buy everything
			return loc;
		}

		// list?
		if (xr - xl == 1) {
			ll k = min(cap / d[xl].w, d[xl].a);
			return {k * d[xl].w, k * d[xl].v};
		}

		int xm = (xl+xr) >> 1;
		auto lhs = solve(cap, 2*x, xl, xm);
		cap -= lhs.weight_tot;
		return lhs + solve(cap, 2*x+1, xm, xr);
	}
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> d[i].a >> d[i].w >> d[i].v;
		d[i].id = i;
	}

	sort(d+1, d+n+1);
	for (int i=1; i<=n; i++) {
		dord[d[i].id] = i;
	}

	outer_tree::init();

	for (int i=1; i<=n; i++) {
		outer_tree::add(i, d[i].a);
	}

	ll last_cap = -1;
	ll last_sol = -1;

	while (q--) {
		int t;
		cin >> t;
		if (t < 3) {
			int k, i;
			cin >> k >> i;
			if (t == 2) {
				k = -k;
			}

			i = dord[i];
			d[i].a += k;
			outer_tree::add(i, k);
			last_cap = -1;
		} else {
			ll cap;
			cin >> cap;

			if (cap != last_cap) {
				last_sol = outer_tree::solve(cap).val_tot;
				last_cap = cap;
			}

			cout << last_sol << '\n';
		}
	}

}