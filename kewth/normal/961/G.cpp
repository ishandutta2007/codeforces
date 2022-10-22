#if 0
date +%Y.%m.%d

 a[i]  ka[i]  k 
 k  i  k * sum(a) 

 a[i]  k  i 
 a[j]  k  p  j != i  p  k 

 p  a[j]  a[i] 
 a[i]  a[j]  p = S(n - 1, m) 
 a[i]  k  S(n, m) 
 k = (n - 1)S(n - 1, m) + S(n, m) 
#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 200005, mod = 1000000007;
ll fac[maxn], ifac[maxn];

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

inline ll C(int n, int m) {
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

inline ll S(int n, int m) {
	ll res = 0;
	for(int k = 0; k <= m; k ++)
		res += power(mod - 1, m - k) * C(m, k) % mod * power(k, n) % mod;
	res %= mod;
	return res * ifac[m] % mod;
}

int main() {
	int n = read, m = read;
	ll sum = 0;
	for(int i = 1; i <= n; i ++) sum += read;
	sum %= mod;

	fac[0] = 1;
	for(int i = 1; i <= m; i ++) fac[i] = fac[i - 1] * i % mod;
	ifac[m] = power(fac[m], -1);
	for(int i = m; i; i --) ifac[i - 1] = ifac[i] * i % mod;

	printf("%lld\n", ((n - 1) * S(n - 1, m) % mod + S(n, m)) * sum % mod);
}