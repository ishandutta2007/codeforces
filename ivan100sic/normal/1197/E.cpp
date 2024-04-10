#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 1'000'000'007;

void ad(int& x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

template<class T>
struct implicit_segtree {

	struct node {
		T v;
		int l, r;
		node() : v(), l(0), r(0) {}
	};

	vector<node> b;
	int root;

	implicit_segtree() { 
		b.resize(2);
		root = 1;
	}

	int update(int p, T v, int x, int xl, int xr) {
		if (x == 0) {
			x = b.size();
			b.emplace_back();
		}

		if (xl == xr) {
			b[x].v = b[x].v + v;
		} else {
			int xm = (xl+xr) >> 1;
			if (p <= xm)
				b[x].l = update(p, v, b[x].l, xl, xm);
			else
				b[x].r = update(p, v, b[x].r, xm+1, xr);
			b[x].v = b[b[x].l].v + b[b[x].r].v;
		}

		return x;
	}

	void update(int p, T v) {
		update(p, v, root, 0, 1123123123);
	}

	T query(int l, int r, int x, int xl, int xr) {
		if (!x || r < xl || xr < l)
			return T();
		if (l <= xl && xr <= r)
			return b[x].v;
		int xm = (xl+xr) >> 1;
		return query(l, r, b[x].l, xl, xm)
			+ query(l, r, b[x].r, xm+1, xr);
	}

	T query(int l, int r) {
		return query(l, r, root, 0, 1123123123);
	}
};

struct lutka {
	int a, b;
	bool operator< (const lutka& o) const {
		return a < o.a;
	}
};

struct stanje {
	int brmval, mval, maxb;

	stanje() : brmval(0), mval(1123123123), maxb(-1) {}

	stanje(int brmval, int mval, int maxb) : brmval(brmval),
		mval(mval), maxb(maxb) {}

	stanje operator+ (const stanje& b) const {
		stanje tmp;
		tmp.maxb = max(maxb, b.maxb);
		if (mval < b.mval) {
			tmp.mval = mval;
			tmp.brmval = brmval;
		} else if (mval > b.mval) {
			tmp.mval = b.mval;
			tmp.brmval = b.brmval;
		} else {
			tmp.mval = mval;
			tmp.brmval = brmval;
			ad(tmp.brmval, b.brmval);
		}
		return tmp;
	}
};

int n;
lutka a[200005];
int ans[200005];
int ya[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].a >> a[i].b;
	sort(a, a+n);

	implicit_segtree<stanje> drvo;

	for (int i=0; i<n; i++) {
		int B = drvo.query(0, a[i].b).maxb;
		int& cnt = ans[i];
		int& val = ya[i];
		if (B == -1) {
			cnt = 1;
			val = a[i].b - a[i].a;
		} else {
			auto q = drvo.query(B+1, a[i].b);
			if (q.maxb == -1) {
				cnt = 1;
				val = a[i].b - a[i].a;
				exit(1);
			} else {
				cnt = q.brmval;
				val = q.mval + a[i].b - a[i].a;
			}
		}
		drvo.update(a[i].a, stanje(cnt, val, a[i].b));
	}

	// for (int i=0; i<n; i++)
	// 	cerr << ans[i] << ' ' << ya[i]+a[i].a << ' ' << a[i].a << ' ' << a[i].b << '\n';

	{
		stanje sol;
		int B = drvo.query(0, 1123123123).maxb;
		for (int i=0; i<n; i++) {
			if (a[i].a > B) {
				// samo ovakve razmatram
				sol = sol + stanje(ans[i], ya[i]+a[i].a, 1);
			}
		}
		cout << sol.brmval << '\n';
	}

	

}