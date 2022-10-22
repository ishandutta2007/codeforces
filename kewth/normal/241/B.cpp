#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 50005, maxk = 31, mod = 1000000007;
int ch[maxn * (maxk + 1)][2], size[maxn * (maxk + 1)], cp;
int cl[maxn * (maxk + 1)], cr[maxn * (maxk + 1)];
int num[maxn];

struct Sum {
	int t[maxk], n;
	void operator += (Sum an) {
		for (int k = 0; k < maxk; k ++)
			t[k] += an.t[k];
		n += an.n;
	}
	ll Xor (int x) {
		ll res = 0;
		for (int k = 0; k < maxk; k ++)
			res += (x >> k & 1 ? n - t[k] : t[k]) * (1ll << k);
		return res;
	}
	Sum (): n(0) { std::fill(t, t + maxk, 0); }
	Sum (int x): n(1) {
		for (int k = 0; k < maxk; k ++)
			t[k] = x >> k & 1;
	}
} pre[maxn];

void insert (int &now, int x, int i, int k) {
	if (!now) cl[now = ++ cp] = i;
	cr[now] = i;
	++ size[now];
	if (k >= 0)
		insert(ch[now][x >> k & 1], x, i, k - 1);
}

int rank (int now, int x, int y, int k) { // sum of [v ^ x >= y]
	if (k < 0 or !now) return size[now];
	int tx = x >> k & 1;
	int ty = y >> k & 1;
	if (!ty)
		return size[ch[now][!tx]] + rank(ch[now][tx], x, y, k - 1);
	return rank(ch[now][!tx], x, y, k - 1);
}

ll query (int now, int x, int r, int k) {
	if (k < 0) return pre[cr[now]].Xor(x) - pre[cr[now] - r].Xor(x);
	int t = x >> k & 1, a = ch[now][!t], b = ch[now][t];
	if (r <= size[a])
		return query(a, x, r, k - 1);
	return (a ? pre[cr[a]].Xor(x) - pre[cl[a] - 1].Xor(x) : 0) +
		query(b, x, r - size[a], k - 1);
}

int main () {
	int n = read, t = 0;
	ll m = read;
	// if (m == 0) return puts("0"), 0;
	m <<= 1;
	for (int i = 1; i <= n; i ++)
		read(num[i]);

	std::sort(num + 1, num + n + 1);
	for (int i = 1; i <= n; i ++)
		insert(t, num[i], i, maxk - 1);
	for (int i = 1; i <= n; i ++)
		pre[i] = num[i];
	for (int i = 1; i <= n; i ++)
		pre[i] += pre[i - 1];

	int l = 0, r = (1u << 31) - 1;
	while (l < r) {
		int mid = (1ll + l + r) >> 1;
		ll rk = 0;
		for (int i = 1; i <= n; i ++)
			rk += rank(t, num[i], mid, maxk - 1);
		if (rk >= m) l = mid;
		else r = mid - 1;
	}

	debug("M = %d\n", l);

	ll ans = 0;
	ll tot = 0;
	for (int i = 1; i <= n; i ++) {
		int rk = rank(t, num[i], l, maxk - 1);
		ans += query(t, num[i], rk, maxk - 1);
		tot += rk;
		/* debug("%d %lld\n", rk, ans); */
	}
	ans -= ll(tot - m) * l;

	printf("%llu\n", (ans >> 1) % mod);
}