#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e6 + 5;
const ll INF = 1e18;

int n, r1, r2, r3, d, a[mxn];

#define no(x) (1LL * a[x] * r1 + r3)
#define lft(x) (min(1LL * (a[x] + 1) * r1, 1LL * r2) + r1 + ((x) == n - 1 ? 2 * d : 0))

struct SEG {
	static const int mxn = 1 << 20;
	ll mn[mxn << 1], mn0[mxn << 1], tag[mxn << 1];

	SEG() {
		memset(mn, 0x3f, sizeof(mn));
		memset(mn0, 0x3f, sizeof(mn0));
		memset(tag, 0, sizeof(tag));
	}

	void push(int x, ll v) {
		tag[x] += v;
		mn[x] += v;
		mn0[x] += v;
	}

	void pushdown(int x) {
		if (tag[x]) {
			push(x << 1, tag[x]);
			push(x << 1 | 1, tag[x]);
			tag[x] = 0;
		}
	}

	void pushup(int x) {
		mn[x] = min(mn[x << 1], mn[x << 1 | 1]);
		mn0[x] = min(mn0[x << 1], mn0[x << 1 | 1]);
	}

	void upd(int x, int a, int b, int l, int r, ll v) {
		if (l <= a && b <= r) return push(x, v);
		pushdown(x);
		int m = (a + b) >> 1;
		if (l < m) upd(x << 1, a, m, l, r, v);
		if (r > m) upd(x << 1 | 1, m, b, l, r, v);
		pushup(x);
	}

	void upd(int l, int r, ll v) { return upd(1, 0, mxn, l, r, v); }

	void set(int x, int a, int b, int p, ll v) {
		if (a + 1 == b) { mn[x] = v; mn0[x] = v - 2LL * p * d; return ; }
		pushdown(x);
		int m = (a + b) >> 1;
		if (p < m) set(x << 1, a, m, p, v);
		else set(x << 1 | 1, m, b, p, v);
		pushup(x);
	}

	void set(int p, ll v) { return set(1, 0, mxn, p, v); }

	ll get(int x, int a, int b, int p) {
		if (a + 1 == b) return mn[x];
		pushdown(x);
		int m = (a + b) >> 1;
		if (p < m) return get(x << 1, a, m, p);
		else return get(x << 1 | 1, m, b, p);
	}

	ll get(int p) { return get(1, 0, mxn, p); }

	ll qry(int x, int a, int b, int l, int r) {
		if (l <= a && b <= r) return mn[x];
		pushdown(x);
		int m = (a + b) >> 1;
		ll ans = INF;
		if (l < m) ans = min(ans, qry(x << 1, a, m, l, r));
		if (r > m) ans = min(ans, qry(x << 1 | 1, m, b, l, r));
		return ans;
	}

	ll qry(int l, int r) { return qry(1, 0, mxn, l, r); }

	ll qry0(int x, int a, int b, int l, int r) {
		if (l <= a && b <= r) return mn0[x];
		pushdown(x);
		int m = (a + b) >> 1;
		ll ans = INF;
		if (l < m) ans = min(ans, qry0(x << 1, a, m, l, r));
		if (r > m) ans = min(ans, qry0(x << 1 | 1, m, b, l, r));
		return ans;
	}

	ll qry0(int l, int r) { return qry0(1, 0, mxn, l, r); }
};

SEG dp;

int main() {
	scanf("%d %d %d %d %d", &n, &r1, &r2, &r3, &d);
	rep(i, n) scanf("%d", &a[i]);
	dp.set(0, lft(0)); dp.set(n, no(0));
	for (int i = 1; i < n; ++ i) {
		ll mnli = dp.qry0(0, i) + d + 2LL * i * d;
		ll dpn = dp.get(n) + d;
		dp.set(n, min(mnli + min(lft(i), no(i)), dpn + no(i)));
		dp.set(i, dpn + lft(i));
		if (i == n - 1) dp.set(n - 1, min(dp.get(n - 1), dp.get(n - 2) + d + lft(i)));
		dp.upd(0, i, d + min(lft(i), no(i)));
	}
	ll ans = dp.get(n);
	rep(i, n) ans = min(ans, dp.get(i) + 1LL * (n - 1 - i) * d);
	printf("%lld\n", ans);
	return 0;
}