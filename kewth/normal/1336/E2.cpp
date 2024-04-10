#if 0
2020.04.26

   K  K 2^K 
 K 
  
 x  X  0  x  1  FWT(X)  0  2 
FWT(X)  B  A  B = FWT(A)  B 
 0  2^K  2^K  2^(m-K)  m - K 

   m - K  K 
 2^(m-K)  B  B 
   c  F  popcount  c  1  A  F 
 0  c 
   FWT(F)  FWT(F)  i  popcount(i)  popcount = d
 2^d - 1  FWT(F)  w[d]  w 
B  c 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef unsigned long long ull;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int maxm = 53, mod = 998244353;
ll bas[maxm];
ll fac[maxm + 1], ifac[maxm + 1];

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

inline ll C (int n, int m) {
	if (m > n) return 0;
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void combinator_init (int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = power(fac[n], -1);
	for (int i = n; i; i --)
		ifac[i - 1] = ifac[i] * i % mod;
}

void insert (ll x, int m) {
	for (int k = m - 1; k >= 0; k --)
		if (x >> k & 1) {
			if (bas[k]) x ^= bas[k];
			else return bas[k] = x, void();
		}
}

inline int count (ll x) {
	return __builtin_popcountll(ull(x));
}

ll a[maxm], b[maxm];
ll ans[maxm + 1], pans[maxm + 1];
int p[maxm];
bool matrix[maxm][maxm];
ll w[maxm + 1][maxm + 1];

inline void swap (int m, int X, int Y) {
	for (int i = 0; i < m; i ++)
		std::swap(matrix[i][X], matrix[i][Y]);
	std::swap(p[X], p[Y]);
}

inline void operation (int m, int i, int j) {
	for (int k = 0; k < m; k ++)
		matrix[j][k] ^= matrix[i][k];
}

void dfs (int i, ll x, ll *A, ll *B) {
	if (i < 0) return ++ B[count(x)], void();
	dfs(i - 1, x, A, B);
	dfs(i - 1, x ^ A[i], A, B);
}

int main () {
	int n = read, m = read;
	for (int i = 1; i <= n; i ++) insert(read, m);
	combinator_init(m);

	int K = 0;
	for (int k = 0; k < m; k ++)
		if (bas[k])
			a[K ++] = bas[k];

	if (K <= m - K)
		dfs(K - 1, 0, a, ans);

	else {
		for (int i = 0; i < K; i ++)
			for (int k = 0; k < m; k ++)
				matrix[m - K + i][k] = a[i] >> k & 1;

		for (int k = 0; k < m; k ++)
			p[k] = k;
		for (int i = m - 1; i >= m - K; i --) {
			int key = m - 1;
			while (!matrix[i][key]) -- key;
			swap(m, key, i);
		}

		for (int i = m - K; i < m; i ++)
			for (int j = i + 1; j < m; j ++)
				if (matrix[j][i])
					operation(m, i, j);

		for (int i = m - K; i < m; i ++)
			for (int j = 0; j < m - K; j ++)
				matrix[j][i] = matrix[i][j];
		for (int i = 0; i < m - K; i ++)
			matrix[i][i] = 1;

		/* for (int i = 0; i < m; i ++) { */
		/* 	for (int j = 0; j < m; j ++) */
		/* 		debug("%d", matrix[i][j]); */
		/* 	debug("\n"); */
		/* } */
		/* debug("\n"); */

		for (int i = 0; i < m - K; i ++)
			for (int j = 0; j < m; j ++)
				b[i] ^= ll(matrix[i][j]) << p[j];

		dfs(m - K - 1, 0, b, pans);

		/* for (int i = 0; i <= m; i ++) */
		/* 	debug("%lld\n", pans[i]); */

		for (int i = 0; i <= m; i ++)
			for (int j = 0; j <= m; j ++) {
				// XXX:  O2  skip 
				/* for (int k = 0; k <= i and k <= j; k ++) { */
				for (int k = 0; k <= std::min(i, j); k ++) {
					ll now = C(j, k) * C(m - j, i - k) % mod;
					if (k & 1) w[i][j] += mod - now;
					else w[i][j] += now;
				}
				w[i][j] %= mod;
			}

		ll coe = power(2, K - m);
		for (int i = 0; i <= m; i ++) {
			for (int j = 0; j <= m; j ++)
				(ans[i] += pans[j] * w[i][j]) %= mod;
			(ans[i] *= coe) %= mod;
		}

		/* for (int i = 0; i <= m; i ++) { */
		/* 	for (int j = 0; j <= m; j ++) */
		/* 		debug(" %lld", w[i][j]); */
		/* 	debug("\n"); */
		/* } */
	}

	ll coe = power(2, n - K);
	for (int k = 0; k <= m; k ++)
		printf("%lld ", ans[k] * coe % mod);
	puts("");
}