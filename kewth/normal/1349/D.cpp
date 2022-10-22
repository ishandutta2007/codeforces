#if 0
2020.05.13

   F[i]  i  sum(F[i]) 
   F[i]  i 

   G[i]  i 
   G[i]  a[i]  H[x]  a[i] = x  G[i]  H[x] 
 H[x] = A[x] H[x - 1] + B[x] H[x] + C[x] H[x + 1]  H 
 G[i]  F  j 
    G[i] = sum(F[j] + C(j, i) P[j])
  C(j, i)  j i 
 i = j  C(j, i) = 0  C(j, i) = H[0] 
   P[j]  j  sum(P[j]) = 1 
   i 
    sum(G[i]) = n sum(F[i]) + sum(C(j, i) P[j])
              = n sum(F[i]) + sum(P[j] sum(H[0] [i != j]))
              = n sum(F[i]) + H[0] sum(P[j] sum([i != j]))
              = n sum(F[i]) + H[0] sum(P[j]) (n - 1)
              = n sum(F[i]) + (n - 1) H[0]
   sum(F[i])  H 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 300005, mod = 998244353;
int a[maxn];
ll f[maxn], g[maxn];
ll pi[maxn], pd[maxn], ps[maxn];

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

int main () {
	int n = read, m = 0;
	for (int i = 1; i <= n; i ++)
		m += a[i] = read;

	ll Invm = power(m, -1), Invn_ = power(n - 1, -1);
	for (int x = 0; x <= m; x ++) {
		pi[x] = (m - x) * Invm % mod * Invn_ % mod;
		ps[x] = (m - x) * Invm % mod * (mod + 1 - Invn_) % mod;
		pd[x] = x * Invm % mod;
	}

	for (int x = 0; x < m; x ++) {
		f[x] = (pi[x] + pd[x] + ps[x] + (x ? f[x - 1] : 0) * pd[x]) % mod;
		g[x] = pi[x];
		ll X = ((x ? g[x - 1] : 0) * pd[x] + ps[x]) % mod;
		ll Inv = power(mod + 1 - X, -1);
		(f[x] *= Inv) %= mod;
		(g[x] *= Inv) %= mod;
	}

	for (int x = m; x; x --)
		(f[x - 1] += g[x - 1] * f[x]) %= mod;

	ll ans = 0;
	for (int i = 1; i <= n; i ++)
		ans += f[a[i]];
	ans -= (n - 1) * f[0];
	ans %= mod;
	ans += mod;
	(ans *= power(n, -1)) %= mod;
	printf("%lld\n", ans);

	/* for (int x = 0; x <= m; x ++) */
	/* 	debug("%d: %lld %lld %lld\n", x, pi[x], pd[x], f[x]); */

	/* for (int x = 1; x < m; x ++) */
	/* 	if (f[x] != (1 + pi[x] * f[x + 1] + ps[x] * f[x] + pd[x] * f[x - 1]) % mod) */
	/* 		return 1; */
	/* for (int x = 0; x <= m; x ++) */
	/* 	if ((pd[x] + ps[x] + pi[x]) % mod != 1) */
	/* 		return 1; */
}