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

struct subseq {
	int l, r;
	bool inc, empty;

	subseq() : empty(true) {}

	subseq(int x) : l(x), r(x), inc(true), empty(false) {}

	subseq operator+ (const subseq& b) const {
		if (empty) return b;
		if (b.empty) return *this;
		subseq res;
		res.l = l;
		res.r = b.r;
		res.inc = inc && b.inc && r <= b.l;
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
		vector<pair<int, int>> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}

		sort(begin(a), end(a));

		segtree<subseq> st(n);
		for (int i=0; i<n; i++)
			st.update(i, a[i].second);

		int sol = 0;

		for (int l=0; l<n; l++) {
			int lo = l+1, hi = n, o = l;
			while (lo <= hi) {
				int mid = (lo + hi) / 2;
				if (st(l, mid).inc) {
					o = mid;
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}

			sol = max(sol, o - l);
		}

		cout << n - sol << "\n";
	}
}