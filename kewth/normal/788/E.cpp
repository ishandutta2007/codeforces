/*
 * Author: Kewth

 * Date:
  echo -n '  ' && date +%Y.%m.%d # Type "!!sh" in Vim.

 * Solution:
  To be updated after "Accept".

 * Digression:

 * CopyRight:
   __  __                  __   __
  |  |/  |.-----.--.--.--.|  |_|  |--.
  |     < |  -__|  |  |  ||   _|     |
  |__|\__||_____|________||____|__|__|

 */

#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<int, int> par;

static struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005, mod = 1000000007;

struct Data {
	int tot, sl, sr;
	int sl2, sr2;
	int s3;
	Data () {
		tot = sl = sr = sl2 = sr2 = s3 = 0;
	}
	/* Data (int tot, int sl, int sr): tot(tot), sl(sl), sr(sr) { */
	/* 	sl2 = sr2 = s3 = 0; */
	/* } */
} D[maxn];
Data operator + (Data a, Data b) {
	Data c;
	c.tot = a.tot + b.tot;
	c.sl = (a.sl + b.sl) % mod;
	c.sr = (a.sr + b.sr) % mod;
	c.sl2 = (a.sl2 + b.sl2 + 1ll * a.sl * b.tot) % mod;
	c.sr2 = (a.sr2 + b.sr2 + 1ll * a.tot * b.sr) % mod;
	c.s3 = (a.s3 + b.s3 + 1ll * a.sl2 * b.sr + 1ll * a.sl * b.sr2) % mod;
	return c;
}

struct Segment {
	Data *seg;
	void modify (int now, int L, int R, int p, Data d) {
		if (L == R) return seg[now] = d, void();
		int M = (L + R) >> 1;
		if (p <= M) modify(now << 1, L, M, p, d);
		else modify(now << 1 | 1, M + 1, R, p, d);
		seg[now] = seg[now << 1] + seg[now << 1 | 1];
	}
	/* Data query (int now, int L, int R, int l, int r) { */
	/* 	if (r < L or l > R) return D[0]; */
	/* 	if (l <= L and R <= r) return seg[now]; */
	/* 	int M = (L + R) >> 1; */
	/* 	return query(now << 1, L, M, l, r) + */
	/* 		query(now << 1 | 1, M + 1, R, l, r); */
	/* } */
} S[maxn];

int bit[maxn];
void add (int p, int n) {
	for (int k = p; k <= n; k += k & -k)
		++ bit[k];
}
int query (int l, int r) {
	int res = 0;
	for (int k = r; k; k -= k & -k)
		res += bit[k];
	for (int k = l - 1; k; k -= k & -k)
		res -= bit[k];
	return res;
}

int a[maxn];
int pi[maxn], pl[maxn], pr[maxn], pk[maxn];
par p[maxn];
ll Ans;

void assign (int I, Data d) {
	int i = pi[I], l = pl[I], r = pr[I], k = pk[I];
	Ans += mod - S[k].seg[1].s3;
	S[k].modify(1, 0, r - l, i - l, d);
	Ans += S[k].seg[1].s3;
	debug("%lld\n", Ans % mod);
}

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) read(a[i]), p[i] = par(a[i], i);
	std::sort(p + 1, p + n + 1);

	for (int l = 1, r, k = 1; l <= n; l = r + 1, k ++) {
		r = l;
		while (r + 1 <= n and p[r + 1].first == p[r].first)
			++ r;
		S[k].seg = new Data[unsigned((r - l + 1) << 2)];
		for (int i = l; i <= r; i ++) {
			pi[p[i].second] = i;
			pl[p[i].second] = l;
			pr[p[i].second] = r;
			pk[p[i].second] = k;
		}
		for (int i = l; i <= r; i ++)
			add(p[i].second, n);
		for (int i = l; i <= r; i ++) {
			D[p[i].second].tot = 1;
			D[p[i].second].sl = query(1, p[i].second - 1);
			D[p[i].second].sr = query(p[i].second + 1, n);
			/* debug("%d %d\n", D[p[i].second].sl, D[p[i].second].sr); */
		}
	}

	for (int i = 1; i <= n; i ++)
		assign(i, D[i]);

	int q = read;
	while (q --) {
		int o = read, i = read;
		if (o == 1)
			assign(i, D[0]);
		if (o == 2)
			assign(i, D[i]);
		printf("%lld\n", Ans % mod);
	}

}