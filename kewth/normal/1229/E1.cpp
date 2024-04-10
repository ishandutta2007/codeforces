#if 0
2020.05.08

   k  k 
 DP  k 

   2^n 

   2^C(7, 3)  map 
 30263 
#endif
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef size_t si;
typedef std::pair<ll, ll> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 7, mod = 1000000007;
ll pro[maxn][maxn];
std::map<ll, ll> f[maxn + 1];
std::vector<int> vs[maxn + 1];
si vid[1 << maxn];

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

int count (int S) { return __builtin_popcount(unsigned(S)); }

int main () {
	int n = read;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			pro[i][j] = read * power(100, -1) % mod;

	for (int S = 0; S < (1 << n); S ++) {
		vid[S] = vs[count(S)].size();
		vs[count(S)].push_back(S);
	}

	f[0][1] = 1;
	for (int k = 0; k < n; k ++) {
		for (int S = 0; S < (1 << n); S ++) {
			ll p = 1;
			for (int i = 0; i < n; i ++)
				(p *= (S >> i & 1) ? pro[i][k] : (mod + 1 - pro[i][k])) %= mod;
			for (par pr : f[k]) {
				ll A = pr.first, x = pr.second, B = 0;
				for (si i = 0; i < 60; i ++)
					if (A >> i & 1) {
						int T = vs[k][i];
						for (int j = 0; j < n; j ++)
							if (S >> j & 1 and !(T >> j & 1))
								B |= 1ll << vid[T ^ (1 << j)];
					}
				(f[k + 1][B] += x * p) %= mod;
			}
		}
		debug("%lu\n", f[k].size());
	}

	printf("%lld\n", f[n][1]);
}