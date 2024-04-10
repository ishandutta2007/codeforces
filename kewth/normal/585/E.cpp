#if 0
date

solution
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 10000005, mod = 1000000007;
int f[maxn], g[maxn], h[maxn];
int pow2[maxn];
int prime[664580], pp;
bool nop[maxn];

int main() {
	int n = read;
	while(n --)
		++ h[read];

	n = 10000000;
	g[1] = 1;
	for(int i = 2; i <= n; i ++) {
		if(!nop[i]) {
			prime[++ pp] = i;
			g[i] = -1;
		}
		for(int k = 1; prime[k] <= n / i; k ++) {
			nop[i * prime[k]] = 1;
			if(!(i % prime[k])) break;
			g[i * prime[k]] = - g[i];
		}
	}

	for(int k = 1; k <= pp; k ++)
		for(int x = n / prime[k]; x; x --)
			h[x] += h[x * prime[k]];

	for(int x = 1; x <= n; x ++)
		g[x] *= h[x];
	for(int k = 1; k <= pp; k ++)
		for(int x = 1; x <= n / prime[k]; x ++)
			g[x * prime[k]] += g[x];

	pow2[0] = 1;
	for(int x = 1; x <= n; x ++)
		pow2[x] = (pow2[x - 1] << 1) % mod;

	for(int x = 1; x <= n; x ++)
		f[x] = pow2[h[x]] - 1;
	for(int k = 1; k <= pp; k ++)
		for(int x = 1; x <= n / prime[k]; x ++) {
			f[x] -= f[x * prime[k]];
			if(f[x] < 0) f[x] += mod;
		}

	ll ans = 0;
	for(int x = 2; x <= n; x ++)
		(ans += 1ll * f[x] * g[x]) %= mod;
	printf("%lld\n", ans);
}