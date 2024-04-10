#if 0
2020.03.16


 f[i]  i 
 lim(f[i] * (-1)^(n - i)) 
 f[i]  i  (n - i)! 


 g[i]  i 
f  g 

 1e9+7  O(n^2) 
#endif
#include <cstdio>
#include <cmath>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
} read;

const int maxn = 5050, mod = 1000000007;
int a[maxn];
int b[maxn], bp;
ll f[maxn], g[maxn], h[maxn];
ll fac[maxn], ifac[maxn];

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

int main() {
	int n = read;
	int max = int(sqrt(1000000000));
	for(int i = 1; i <= n; i ++) {
		a[i] = read;
		for(int x = max; x; x --)
			if(!(a[i] % (x * x))) {
				a[i] /= x * x;
				break;
			}
	}

	std::sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++)
		if(a[i] != a[i - 1])
			b[++ bp] = 1;
		else
			++ b[bp];

	fac[0] = 1;
	for(int i = 1; i <= n; i ++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = power(fac[n], -1);
	for(int i = n; i; i --)
		ifac[i - 1] = ifac[i] * i % mod;

	int lim = 0;
	f[0] = 1;

	for(int i = 1; i <= bp; i ++) {
		ll coe = 1;
		for(int j = b[i]; j; j --) {
			g[b[i] - j] = coe * ifac[b[i] - j] % mod;
			(coe *= j * (j - 1)) %= mod;
		}
		for(int j = 0; j <= lim + b[i]; j ++)
			h[j] = 0;
		for(int j = 0; j <= lim; j ++)
			for(int k = 0; k < b[i]; k ++)
				(h[j + k] += f[j] * g[k]) %= mod;
		lim += b[i] - 1;
		for(int j = 0; j <= lim; j ++)
			f[j] = h[j];
	}

	for(int j = 0; j <= lim; j ++)
		(f[j] *= fac[n - j]) %= mod;

	ll ans = 0;
	for(int j = 0; j <= lim; j ++)
		ans += j & 1 ? - f[j] : f[j];
	ans %= mod;
	if(ans < 0) ans += mod;

	printf("%lld\n", ans);
}