#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct SegmentTree {
	static const int mxn = 1 << 18;
	std::pair <double, int> mx[mxn << 1];

	void init(int n) {
		rep(i, n) mx[i + mxn] = std::make_pair(-1e18, i);
		for (int i = n; i < mxn; ++ i) mx[i + mxn] = std::make_pair(-1e18, n);
		for (int i = mxn - 1; i; -- i) {
			mx[i] = std::max(mx[i << 1], mx[i << 1 | 1]);
		}
	}

	void set(int x, double v) {
		mx[x += mxn].first = v;
		while (x >>= 1) {
			mx[x] = std::max(mx[x << 1], mx[x << 1 | 1]);
		}
	}

	std::pair <double, int> query() {
		return mx[1];
	}
} iseg, dseg;

const int mxn = 2e5 + 5;
int n, t, q;
double p[mxn];
int l[mxn];
int x[mxn];
double ans;

double f(int i, int x) {
	return p[i] * x / (l[i] + x);
}

double calci(int i) {
	if (x[i] == l[i]) return -1e18;
	return f(i, x[i] + 1) - f(i, x[i]);
}

double calcd(int i) {
	if (x[i] == 0) return -1e18;
	return f(i, x[i] - 1) - f(i, x[i]);
}

bool cani() {
	int p = iseg.query().second;
	if (p >= n) return 0;
	return x[p] != l[p];
}

bool cand() {
	int p = dseg.query().second;
	if (p >= n) return 0;
	return x[p] != 0;
}

void doi() {
	int p = iseg.query().second;
	-- t;
	ans += iseg.query().first;
	x[p] ++;
	iseg.set(p, calci(p));
	dseg.set(p, calcd(p));
}

void dod() {
	int p = dseg.query().second;
	++ t;
	ans += dseg.query().first;
	x[p] --;
	iseg.set(p, calci(p));
	dseg.set(p, calcd(p));
}

int main() {
	scanf("%d %d %d", &n, &t, &q);
	rep(i, n) scanf("%lf", &p[i]);
	rep(i, n) scanf("%d", &l[i]);
	rep(i, n) x[i] = 0;
	iseg.init(n);
	dseg.init(n);
	rep(i, n) iseg.set(i, calci(i));
	rep(i, n) dseg.set(i, calcd(i));
	while (q --) {
		int op, p;
		scanf("%d %d", &op, &p);
		-- p;
		ans -= f(p, x[p]);
		l[p] += (op == 1 ? +1 : -1);
		if (x[p] > l[p]) {
			-- x[p];
			++ t;
		}
		ans += f(p, x[p]);
		iseg.set(p, calci(p));
		dseg.set(p, calcd(p));
		rep(iter, 5) if (cand()) dod();
		while (cani() && t) doi();
		printf("%.9f\n", ans);
//		rep(i, n) eprintf("%d ", x[i]); eprintf("\n");
	}
	return 0;
}