#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 300005, mod = 1000000007;
ll i2[maxn];

struct Data {
	ll size, inc, dec, ans;
};
Data operator + (Data a, Data b) {
	Data d;
	d.size = a.size + b.size;
	d.inc = (a.inc + b.inc * i2[a.size]) % mod;
	d.dec = (b.dec + a.dec * i2[b.size]) % mod;
	d.ans = (a.ans + b.ans + a.dec * b.inc) % mod;
	return d;
}

int a[maxn], tmp[maxn << 1], tp;
int qp[maxn], qx[maxn];
Data seg[maxn << 3];
std::vector<Data> leaf[maxn << 1];

void modify (int now, int L, int R, int p, Data d, int t) {
	if (L == R) {
		if (t == +1) leaf[p].push_back(leaf[p].back() + d);
		if (t == -1) leaf[p].pop_back();
		seg[now] = leaf[p].back();
		return;
	}
	int M = (L + R) >> 1;
	if (p <= M) modify(now << 1, L, M, p, d, t);
	else modify(now << 1 | 1, M + 1, R, p, d, t);
	seg[now] = seg[now << 1] + seg[now << 1 | 1];
	/* if (now == 1) { */
	/* 	debug("%lld %lld %lld\n", seg[now].inc, seg[now].dec, seg[now].ans); */
	/* } */
}

inline Data make (int p) {
	return {1, tmp[a[p]] * i2[1] % mod, tmp[a[p]] * i2[1] % mod, 0};
}

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++)
		tmp[++ tp] = a[i] = read;

	int q = read;
	for (int i = 1; i <= q; i ++) {
		qp[i] = read;
		tmp[++ tp] = qx[i] = read;
	}

	std::sort(tmp + 1, tmp + tp + 1);
	tp = int(std::unique(tmp + 1, tmp + tp + 1) - tmp - 1);

	for (int i = 1; i <= n; i ++)
		a[i] = int(std::lower_bound(tmp + 1, tmp + tp + 1, a[i]) - tmp);
	for (int i = 1; i <= q; i ++)
		qx[i] = int(std::lower_bound(tmp + 1, tmp + tp + 1, qx[i]) - tmp);

	i2[0] = 1;
	for (int i = 1; i <= n; i ++)
		i2[i] = i2[i - 1] * (mod + 1) / 2 % mod;

	for (int i = 1; i <= tp; i ++)
		leaf[i].push_back({0, 0, 0, 0});
	for (int p = 1; p <= n; p ++)
		modify(1, 1, tp, a[p], make(p), 1);
	printf("%lld\n", seg[1].ans);

	for (int i = 1; i <= q; i ++) {
		int p = qp[i];
		modify(1, 1, tp, a[p], make(p), -1);
		a[p] = qx[i];
		modify(1, 1, tp, a[p], make(p), 1);
		printf("%lld\n", seg[1].ans);
	}
}