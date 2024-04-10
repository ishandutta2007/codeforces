#if 0
date

 k  k + 1  i  (i, f(i)) 


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	inline operator char () { char x[3]; return scanf("%s", x), *x; }
} read;

const int maxn = 1000005, mod = 1000000007;

ll power(ll x, int k) {
	if(k < 0) k += mod - 1;
	ll res = 1;
	while(k) {
		if(k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

ll f[maxn];
ll fac[maxn];

int main() {
	int n = read, m = read;

	for(int i = 1; i <= m + 1; i ++)
		f[i] = (f[i - 1] + power(i, m)) % mod;

	if(n <= m + 1)
		return printf("%lld\n", f[n]), 0;

	fac[0] = 1;
	for(int i = 1; i <= m + 1; i ++)
		fac[i] = fac[i - 1] * i % mod;

	ll ans = 0;
	for(int i = 0; i <= m + 1; i ++) {
		ll now = f[i];
		(now *= power(n - i, -1)) %= mod;
		(now *= power(fac[i], -1)) %= mod;
		(now *= power(fac[m + 1 - i], -1)) %= mod;
		if((m + 1 - i) & 1)
			now = mod - now;
		ans += now;
	}
	ans %= mod;
	for(int i = 0; i <= m + 1; i ++)
		(ans *= n - i) %= mod;

	printf("%lld\n", ans);
}