#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 500005;
struct Edge { int v, w; };
std::vector<Edge> G[maxn];
ll g[maxn], h[maxn];

/* int m; */
/* void dp (int u, int fa) { */
/* 	int sz = std::min(m, int(G[u].size()) - bool(fa)); */
/* 	ll *f = new ll [unsigned(sz + 1)]; */
/* 	std::fill(f, f + sz + 1, 0); */
/* 	sz = 0; */
/* 	for (Edge e : G[u]) */
/* 		if (e.v != fa) { */
/* 			dp(e.v, u); */
/* 			sz = std::min(m, sz + 1); */
/* 			for (int i = sz; i; i --) */
/* 				f[i] = std::max(f[i] + h[e.v], f[i - 1] + g[e.v] + e.w); */
/* 			f[0] += h[e.v]; */
/* 			/1* for (int i = 0; i <= sz; i ++) *1/ */
/* 			/1* 	debug(" %lld", f[i]); *1/ */
/* 			/1* debug(" in %d\n", u); *1/ */
/* 		} */
/* 	g[u] = h[u] = 0; */
/* 	for (int i = 0; i < sz; i ++) */
/* 		g[u] = std::max(g[u], f[i]); */
/* 	if (sz < m) g[u] = std::max(g[u], f[sz]); */
/* 	h[u] = std::max(g[u], f[sz]); */
/* 	delete [] f; */
/* } */

int m;
void dp (int u, int fa) {
	std::vector<ll> tmp;
	ll sum = 0;
	for (Edge e : G[u])
		if (e.v != fa) {
			dp(e.v, u);
			sum += h[e.v];
			tmp.push_back(g[e.v] + e.w - h[e.v]);
		}
	g[u] = h[u] = sum;
	std::sort(tmp.begin(), tmp.end(), std::greater<ll> ());
	int tot = 0;
	for (ll x : tmp)
		if (x > 0) {
			++ tot;
			if (tot <= m - 1) g[u] += x;
			if (tot <= m) h[u] += x;
		}
	/* debug("%d : %lld %lld\n", u, g[u], h[u]); */
}

int main () {
	int T = read;
	while (T --) {
		int n = read;
		read(m);
		for (int i = 1; i <= n; i ++) G[i].clear();
		for (int i = 1; i < n; i ++) {
			int u = read, v = read, w = read;
			G[u].push_back({v, w});
			G[v].push_back({u, w});
		}
		dp(1, 0);
		printf("%lld\n", h[1]);
	}
}