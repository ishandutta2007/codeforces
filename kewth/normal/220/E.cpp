#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005;
int a[maxn], tmp[maxn];
int lb[maxn], rb[maxn];
int n;

void modify (int *b, int p, int x) {
	for (int k = p; k <= n; k += k & -k)
		b[k] += x;
}

int query (int *b, int p) {
	int res = 0;
	for (int k = p; k; k -= k & -k)
		res += b[k];
	return res;
}

int contr (int p) {
	return query(lb, n - a[p]) + query(rb, a[p] - 1);
}

int main () {
	read(n);
	ll lim = read;
	for (int i = 1; i <= n; i ++) tmp[i] = a[i] = read;
	std::sort(tmp + 1, tmp + n + 1);
	for (int i = 1; i <= n; i ++)
		a[i] = int(std::lower_bound(tmp + 1, tmp + n + 1, a[i]) - tmp);

	ll now = 0;
	for (int i = n; i >= 2; i --) {
		now += contr(i);
		modify(rb, a[i], 1);
	}

	ll ans = 0;
	for (int l = 1, r = 2; l < n; l ++) {
		if (l == r) {
			now -= contr(r);
			modify(rb, a[r], -1);
			++ r;
		}
		now += contr(l);
		modify(lb, n - a[l] + 1, 1);
		while (r <= n and now > lim) {
			now -= contr(r);
			modify(rb, a[r], -1);
			++ r;
		}
		ans += n - r + 1;
		/* debug("%d %d %lld\n", l, r, now); */
	}

	printf("%lld\n", ans);
}