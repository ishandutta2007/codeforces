#if 0
2020.02.02



 O(klogk) 




 i^k 
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

const int maxn = 10000005, mod = 998244353;
int inv[maxn];
int minp[maxn];
int f[maxn];
int powk[maxn];

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
	int n = read, m = read, k = read;
	ll p = power(m, -1), q = mod + 1 - p;

	inv[1] = 1;
	for(int i = 2; i <= k; i ++)
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;

	ll g = 1, ppow = 1;
	f[0] = 1;
	for(int i = 1; i <= k; i ++) {
		(g *= 1ll * inv[i] * (mod + n - k + i - 1) % mod) %= mod;
		(ppow *= mod - p) %= mod; 
		f[i] = (q * f[i - 1] + g * ppow) % mod;
	}

	powk[1] = 1;
	minp[1] = 1;
	for(int i = 2; i <= k; i ++)
		if(!minp[i]) {
			minp[i] = i;
			if(i <= k / i)
				for(int j = i * i; j <= k; j += i)
					if(!minp[j])
						minp[j] = i;
			powk[i] = power(i, k);
		} else
			powk[i] = 1ll * powk[i / minp[i]] * powk[minp[i]] % mod;

	ll ans = 0;
	ll c = 1;
	ppow = 1;
	for(int i = 1; i <= k; i ++) {
		(c *= 1ll * inv[i] * (n - i + 1) % mod) %= mod;
		(ppow *= p) %= mod;
		// debug("%lld %lld %lld %d\n",
				// c, powk[i], ppow, f[k - i]);
		(ans += c * powk[i] % mod * ppow % mod * f[k - i]) %= mod;
	}

	printf("%lld\n", ans);
}