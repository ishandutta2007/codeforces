// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct segtree {
	int maxn;
	vector<T> a;
	T e;
	F f;

	segtree(int n, T e = T(), F f = F(), T v = T()) : e(e), f(f) {
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, v);
		for (int i=maxn-1; i; i--)
			a[i] = f(a[2*i], a[2*i+1]);
	}

	void add(int p, const T& v) {
		p += maxn;
		a[p] = f(a[p], v);
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	void update(int p, const T& v) {
		p += maxn;
		a[p] = v;
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	T get(int l, int r, int x, int xl, int xr) const {
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	T operator() (int l, int r) const {
		return get(l, r, 1, 0, maxn);
	}
};

struct seg {
	int l, r;

	template<class T>
	auto operator< (const T& b) const {
		return r < b.l;
	}
};

template<class T>
struct subseq {
	T l, r;
	bool inc, empty;

	subseq() : empty(true) {}

	subseq(T x) : l(x), r(x), inc(true), empty(false) {}

	subseq operator+ (const subseq& b) const {
		if (empty) return b;
		if (b.empty) return *this;
		subseq res;
		res.l = l;
		res.r = b.r;
		res.inc = inc && b.inc && r < b.l;
		res.empty = false;
		return res;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, vector<int>> e0;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			e0[x].push_back(i);
		}

		vector<vector<int>> e;
		for (auto [x, v] : e0)
			e.push_back(v);

		int k = e.size();
		segtree<subseq<seg>> st(k);
		for (int i=0; i<k; i++) {
			st.update(i, seg{e[i].front(), e[i].back()});
		}

		vector<int> z(k+1);
		for (int i=0; i<k; i++) {
			z[i+1] = z[i] + e[i].size();
		}

		int sol = 0;

		for (int l=0; l<k; l++) {
			int lo = l+2, hi = k, o = l+1;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (st(l, mid).inc) {
					o = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}

			int len = z[o] - z[l];

			if (l > 0) {
				len += lower_bound(e[l-1].begin(), e[l-1].end(), e[l].front()) - e[l-1].begin();
			}

			if (o < k) {
				len += e[o].end() - lower_bound(e[o].begin(), e[o].end(), e[o-1].back());
			}

			sol = max(sol, len);
		}

		for (int i=1; i<k; i++) {
			for (int j=1; j<(int)e[i].size(); j++) {
				auto it = lower_bound(e[i-1].begin(), e[i-1].end(), e[i][j]);
				sol = max(sol, int(e[i].size() - j + it - e[i-1].begin()));
			}
		}

		cout << n - sol << "\n";
	}
}