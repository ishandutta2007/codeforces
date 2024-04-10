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

const int maxn = 1000005;
ll a[maxn], b[maxn];

ll ans = 1000000000000000000;
void force (int n, ll x) {
	/* debug("x = %lld\n", x); */
	for (int i = 1; i <= n; i ++) b[i] = a[i] % x;
	ll res = 0, tmp = 0, sum = 0;
	for (int i = 1; i <= n; i ++) sum += b[i];
	for (int l = 1, r; sum; l = r) {
		ll now = b[l];
		r = l;
		while (now < x) now += b[++ r];
		/* if (r > n) return; */
		tmp = now - x;
		/* debug("%d %d %lld\n", l, r, tmp); */
		b[r] -= tmp;
		sum -= x;
		int p = l;
		ll pre = b[l];
		while (pre < x - pre) pre += b[++ p];
		for (int i = l; i <= r; i ++)
			res += b[i] * std::abs(i - p);
		b[r] = tmp;
	}
	ans = std::min(ans, res);
}

int main () {
	int n = read;
	ll sum = 0;
	for (int i = 1; i <= n; i ++)
		sum += a[i] = read;

	if (sum == 1) return puts("-1"), 0;

	ll X = sum;
	for (ll d = 2; d * d <= X; d ++)
		if (X % d == 0) {
			force(n, d);
			while (X % d == 0) X /= d;
		}
	if (X > 1)
		force(n, X);

	printf("%lld\n", ans);
}