#if 0
date +%Y.%m.%d

 i^k  sum(j=0->k) S(k, j) C(i, j) j!
 O(n) 
 O(n)  C(n, i) C(i, j) 
 C(n, j) C(n - j, i - j) 
 C(n, j)  C(n - j, i - j) 
#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 5050, mod = 1000000007;
ll fac[maxn], ifac[maxn];
ll S[maxn][maxn];

inline ll power(ll x, int k) {
	if(k < 0) k += mod - 1;
	ll res = 1;
	while(k) {
		if(k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

ll C(int n, int m) {
	ll res = 1;
	for(int i = 0; i < m; i ++) (res *= n - i) %= mod;
	return res * ifac[m] % mod;
}

int main() {
	int n = read, k = read;

	S[0][0] = 1;
	for(int i = 1; i <= k; i ++)
		for(int j = 1; j <= i; j ++)
			S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1]) % mod;

	fac[0] = 1;
	for(int i = 1; i <= k; i ++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[k] = power(fac[k], -1);
	for(int i = k; i; i --)
		ifac[i - 1] = ifac[i] * i % mod;

	ll ans = 0;
	for(int i = 0; i <= k; i ++)
		(ans += S[k][i] * fac[i] % mod * C(n, i) % mod * power(2, n - i)) %= mod;
	printf("%lld\n", ans);
}