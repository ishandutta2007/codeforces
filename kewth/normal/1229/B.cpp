#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef std::pair<ll, int> par;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 100005, mod = 1000000007;
ll val[maxn];
std::vector<int> G[maxn];

ll ans;
void dfs (int u, int fa, std::vector<par> ve) {
	ve.push_back(par(val[u], 1));
	std::vector<par> nv;
	for (par p : ve) {
		ll x = std::__gcd(p.first, val[u]);
		if (!nv.empty() and nv.back().first == x)
			nv.back().second += p.second;
		else
			nv.push_back(par(x, p.second));
		(ans += x * p.second) %= mod;
	}

	for (int v : G[u])
		if (v != fa) {
			dfs(v, u, nv);
		}
}

int main () {
	int n = read;
	for (int i = 1; i <= n; i ++) read(val[i]);
	for (int i = 1; i < n; i ++) {
		int u = read, v = read;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0, {});
	printf("%lld\n", ans);
}