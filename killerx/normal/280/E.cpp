#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 6005;

typedef double db;
typedef long double ld;

int n;
db q, a, b;
db X[mxn], Y[mxn];

struct Function {
	int a; db b; ld c;

	Function(): a(), b(), c() {}

	Function(ld x0): a(1), b(-2 * x0), c(x0 * x0) {}

	Function(int _a, db _b, ld _c): a(_a), b(_b), c(_c) {}

	Function operator + (const Function &oth) const {
		return Function(a + oth.a, b + oth.b, c + oth.c);
	}

	Function operator - (const Function &oth) const {
		return Function(a - oth.a, b - oth.b, c - oth.c);
	}

	ld operator () (db x) const {
		return (ld) a * x * x + (ld) b * x + c;
	}

	db low() const {
		return a == 0 ? 0 : -b / (2 * a);
	}

	void debug() const {
		eprintf("(%d x^2 + %.10lf x + %.10Lf)\n", a, b, c);
	}
};

Function T(Function f, db dx) {
	return Function(f.a, f.b - 2 * f.a * dx, (ld) f.a * dx * dx - (ld) f.b * dx + f.c);
}

struct Item {
	db l, r;
	Function f;
	bool mov;

	Item(db _l, db _r, Function _f, bool _mov): l(_l), r(_r), f(_f), mov(_mov) {}
};

std::vector <Item> dp[2];

db L[mxn], R[mxn];

int main() {
	scanf("%d %lf %lf %lf", &n, &q, &a, &b);
	rep(i, n) scanf("%lf", &X[i]);
	/*
	n = 6000;
	q = 1000000000;
	a = 100000;
	b = 100005;
	rep(i, n) X[i] = (a + 2) * i + 500;
	*/
	rep(i, n) X[i] -= a * i;
	int P = 0, Q = 1;
	dp[0] = {Item(1, q - (n - 1) * a, Function(0, 0, 0), false)};
	rep(i, n + 1) {
		std::pair <ld, db> mn(1e22, 0);
		rep(j, dp[P].size()) {
			db x = dp[P][j].f.low();
			if (x < dp[P][j].l) x = dp[P][j].l;
			else if (x > dp[P][j].r) x = dp[P][j].r;
			if (x > q - (n - 1) * a) x = q - (n - 1) * a;
			mn = std::min(mn, std::make_pair(dp[P][j].f(x), x));
		}
		db x = mn.second;
		ld v = mn.first;
		if (i == n) {
			ld ans = v;
			for (int j = n; j; -- j) {
				Y[j - 1] = x + (j - 1) * a;
				if (x > R[j]) x -= b - a;
				else if (x > L[j]) x = L[j];
			}
			rep(j, n) printf("%.10lf ", Y[j]);
			printf("\n");
			printf("%.10Lf\n", ans);
			return 0;
		}
		bool flag = false;
		std::vector <Item> nw;
		nw.reserve(i + 5);
		rep(j, dp[P].size()) {
			if (dp[P][j].l <= x && dp[P][j].r > x) {
				flag = true;
				if (dp[P][j].l < x) {
					nw.push_back(Item(dp[P][j].l, x, dp[P][j].f, false));
				}
				if (b - a > 0) {
					nw.push_back(Item(x, x + b - a, Function(0, 0, v), true));
				}
				if (x < dp[P][j].r) {
					Function nf = T(dp[P][j].f, b - a);
					nw.push_back(Item(x + b - a, dp[P][j].r + b - a, nf, true));
				}
			} else {
				if (flag) {
					Function nf = T(dp[P][j].f, b - a);
					nw.push_back(Item(dp[P][j].l + b - a, dp[P][j].r + b - a, nf, true));
				} else {
					nw.push_back(Item(dp[P][j].l, dp[P][j].r, dp[P][j].f, false));
				}
			}
		}
		Function ss(X[i]);
		rep(j, nw.size()) nw[j].f = nw[j].f + ss;
		/*
		for (int j = (int) nw.size() - 1; ~j; -- j) {
			if (nw[j].r > q - (n - 1) * a) {
				if (nw[j].l > q - (n - 1) * a) {
					nw.erase(nw.begin() + j);
				} else {
					nw[j].r = q - (n - 1) * a;
				}
			}
		}
		*/
		dp[Q] = nw;
		bool hav = false;
		rep(j, nw.size()) if (nw[j].f.a == 1) L[i + 1] = nw[j].l, R[i + 1] = nw[j].r, hav = true;
		if (!hav) L[i + 1] = R[i + 1] = q - (n - 1) * a;
		// for (auto x : nw) eprintf("[%.10lf, %.10lf]\n", x.l, x.r), x.f.debug();
		// eprintf("\n");
		std::swap(P, Q);
		dp[Q].clear();
	}
	return 0;
}