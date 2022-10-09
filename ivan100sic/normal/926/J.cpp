// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T, class U, class F, class G, class H>
struct segtreelazy {
	struct node { T v; U u; };
	int maxn;
	vector<node> a;
	T e; U eu;
	F f; G g; H h;

	segtreelazy(int n, F f, G g, H h, T e = T(), U eu = U(), T v = T()) :
		e(e), eu(eu), f(f), g(g), h(h)
	{
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, node{v, eu});
		for (int i=maxn-1; i; i--)
			a[i].v = f(a[2*i].v, a[2*i+1].v);
	}

	void push(int x) {
		a[x].v = h(a[x].v, a[x].u);
		if (x < maxn) {
			a[2*x  ].u = g(a[2*x  ].u, a[x].u);
			a[2*x+1].u = g(a[2*x+1].u, a[x].u);
		}
		a[x].u = eu;
	}

	void update(int l, int r, const U& u, int x, int xl, int xr) {
		if (r <= xl || xr <= l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			a[x].u = g(a[x].u, u);
			push(x);
			return;
		}
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, u, 2*x  , xl, xm);
		update(l, r, u, 2*x+1, xm, xr);
		a[x].v = f(a[2*x].v, a[2*x+1].v);
	}

	T get(int l, int r, int x, int xl, int xr) {
		push(x);
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x].v;
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	void update(int l, int r, const U& u) {
		update(l, r, u, 1, 0, maxn);
	}

	T get(int l, int r) {
		return get(l, r, 1, 0, maxn);
	}
};

struct seg {
	bool pref = false, suff = false;
	int cnt = 0;
};

seg dodaj(seg a, seg b) {
	seg c;
	c.pref = a.pref;
	c.suff = b.suff;
	c.cnt = a.cnt + b.cnt - (a.suff && b.pref);
	return c;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;
	segtreelazy drvo(2*n, dodaj, bit_or<bool>(), [&](seg a, bool u) {
		if (u) {
			a.cnt = 1;
			a.pref = a.suff = true;
		}
		return a;

	}, seg{}, false);

	vector<pair<int, int>> q(n);
	vector<int> b;
	for (int i=0; i<n; i++) {
		cin >> q[i].first >> q[i].second;
		b.push_back(q[i].first);
		b.push_back(q[i].second);
	}

	sort(begin(b), end(b));
	b.erase(unique(begin(b), end(b)), end(b));

	for (int i=0; i<n; i++) {
		int l = lower_bound(begin(b), end(b), q[i].first ) - begin(b);
		int r = lower_bound(begin(b), end(b), q[i].second) - begin(b);
		drvo.update(l, r, true);
		cout << drvo.get(0, 123123123).cnt << " \n"[i == n-1];
	}


}