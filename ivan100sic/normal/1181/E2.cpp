#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct rect {
	int l, r, a, b, id;
};

struct cmp_xf {
	bool operator() (const rect& a, const rect& b) const {
		if (a.l != b.l)
			return a.l < b.l;
		return a.id < b.id;
	}
};

struct cmp_xb {
	bool operator() (const rect& a, const rect& b) const {
		if (a.r != b.r)
			return a.r > b.r;
		return a.id < b.id;
	}
};

struct cmp_yf {
	bool operator() (const rect& a, const rect& b) const {
		if (a.a != b.a)
			return a.a < b.a;
		return a.id < b.id;
	}
};

struct cmp_yb {
	bool operator() (const rect& a, const rect& b) const {
		if (a.b != b.b)
			return a.b > b.b;
		return a.id < b.id;
	}
};

int get_a(const rect& b) { return b.a; }
int get_b(const rect& b) { return b.b; }
int get_l(const rect& b) { return b.l; }
int get_r(const rect& b) { return b.r; }

int max_int(int x, int y) { return max(x, y); }
int min_int(int x, int y) { return min(x, y); }

typedef set<rect, cmp_xf> setxf;
typedef set<rect, cmp_xb> setxb;
typedef set<rect, cmp_yf> setyf;
typedef set<rect, cmp_yb> setyb;

bool solve(setxf xf, setxb xb, setyf yf, setyb yb) {
	int n;

	while ((n = xf.size()) > 3) {
		auto it_xf = xf.begin();
		auto it_xb = xb.begin();
		auto it_yf = yf.begin();
		auto it_yb = yb.begin();

		int w_xf = it_xf->r;
		int w_xb = it_xb->l;
		int w_yf = it_yf->b;
		int w_yb = it_yb->a;

		auto probaj = [&](auto& s, auto& it, auto& w, auto getter, auto otherg, auto op) {
			if (op(getter(*next(it)), w) == getter(*next(it))) {
				// seci
				basic_string<rect> tmp(s.begin(), next(it));
				for (const auto& t : tmp) {
					xf.erase(t);
					xb.erase(t);
					yf.erase(t);
					yb.erase(t);
				}

				setxf tmp_xf(tmp.begin(), tmp.end());
				setxb tmp_xb(tmp.begin(), tmp.end());
				setyf tmp_yf(tmp.begin(), tmp.end());
				setyb tmp_yb(tmp.begin(), tmp.end());

				return (int)solve(tmp_xf, tmp_xb, tmp_yf, tmp_yb);

			} else {
				++it;
				w = op(w, otherg(*it));
				return 2;
			}
		};

		bool broken = 0;
		for (int steps=0; steps<n/2; steps++) {
			int t;

			t = probaj(xf, it_xf, w_xf, get_l, get_r, max_int);
			if (t == 0)
				return 0;
			else if (t == 1) {
				broken = true;
				break;
			}

			t = probaj(xb, it_xb, w_xb, get_r, get_l, min_int);
			if (t == 0)
				return 0;
			else if (t == 1) {
				broken = true;
				break;
			}

			t = probaj(yf, it_yf, w_yf, get_a, get_b, max_int);
			if (t == 0)
				return 0;
			else if (t == 1) {
				broken = true;
				break;
			}

			t = probaj(yb, it_yb, w_yb, get_b, get_a, min_int);
			if (t == 0)
				return 0;
			else if (t == 1) {
				broken = true;
				break;
			}
		}

		if (!broken)
			return false;
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	basic_string<rect> u;
	for (int i=0; i<n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		u += {a, c, b, d, i};
	}
	cout << (solve(
		setxf(u.begin(), u.end()),
		setxb(u.begin(), u.end()),
		setyf(u.begin(), u.end()),
		setyb(u.begin(), u.end())
	) ? "YES\n" : "NO\n");
}