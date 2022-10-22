#if 0
2020.03.20

 u  e  e  u 

DP  f[u], bf[u], af[u], nf[u]  u 
f: u 
bf: u 
af: u 
nf: u 

#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 200005, mod = 998244353;
ll f[maxn], bf[maxn], af[maxn], nf[maxn], g[maxn];
struct Edge { int v, w; };
std::vector<Edge> G[maxn];

void dp (int u, int fw) {
	f[u] = nf[u] = 1;
	for (Edge e : G[u]) {
		if (e.w < fw) {
			dp(e.v, e.w);
			(f[u] *= f[e.v] + bf[e.v]) %= mod;
			bf[u] = (bf[u] * g[e.v] + nf[u] * (nf[e.v] + af[e.v])) % mod;
			af[u] = 0;
			(nf[u] *= f[e.v] + bf[e.v]) %= mod;
		}
		if (e.w > fw) {
			dp(e.v, e.w);
			(f[u] *= g[e.v]) %= mod;
			(bf[u] *= g[e.v]) %= mod;
			af[u] = (af[u] * g[e.v] + nf[u] * (nf[e.v] + af[e.v])) % mod;
			(nf[u] *= f[e.v] + bf[e.v]) %= mod;
		}
	}
	g[u] = (bf[u] + af[u] + nf[u]) % mod;
	/* debug("%d: %lld %lld %lld %lld\n", u, f[u], bf[u], af[u], nf[u]); */
}

int main () {
	int n = read;
	for (int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	dp(1, 0);
	printf("%lld\n", g[1]);
}