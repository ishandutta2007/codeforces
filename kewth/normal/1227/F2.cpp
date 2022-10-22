#if 0
date +%Y.%m.%d

 h[n + 1] = h[1] 
 i  h[i]  h[i + 1] 
 dt 
 i  h[i] = h[i + 1]  dt  k 
 k > 2
1) dt - 1 :  1 
2) dt  :  (k - 2) 
3) dt + 1 :  1 
 m  m 

 f[i]  dt = i  sum(f[i] [i > 0]) 
 1) 3)  f[i] = f[i - 1] 
 f[0]  sum(f)  sum(f[i] [i > 0]) = (sum(f) - f[0]) / 2 
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

const int maxn = 200005, mod = 998244353;
int a[maxn];
ll fac[maxn], ifac[maxn];
ll powk[maxn];

inline ll power (ll x, int k) {
	if (k < 0) k += mod - 1;
	ll res = 1;
	while (k) {
		if (k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

void combinator_init (int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = power(fac[n], -1);
	for (int i = n; i; i --)
		ifac[i - 1] = ifac[i] * i % mod;
}

int main () {
	int n = read, k = read;
	if (k == 1) return puts("0"), 0;
	for (int i = 1; i <= n; i ++)
		read(a[i]);
	a[n + 1] = a[1];

	combinator_init(n);

	int m = 0;
	for (int i = 1; i <= n; i ++)
		m += a[i] != a[i + 1];
	/* debug("%d\n", m); */

	powk[0] = 1;
	for (int i = 1; i <= m; i ++)
		powk[i] = powk[i - 1] * (k - 2) % mod;

	ll ans = 0;
	for (int x = 0; x * 2 <= m; x ++)
		(ans += fac[m] * ifac[x] % mod * ifac[x] % mod *
		 ifac[m - x - x] % mod * powk[m - x - x]) %= mod;

	ans = (power(k, m) + mod - ans) * (mod + 1) / 2 % mod;
	/* debug("%lld\n", ans); */
	(ans *= power(k, n - m)) %= mod;
	printf("%lld\n", ans);
}