#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator () (a...); }
} read;

const int maxn = 300005;
/* int a[maxn], b[maxn], c[maxn]; */
struct gem { int x, t; };
gem g[maxn];
int pre[maxn], suf[maxn];

inline ll get (ll x, ll y, ll z) {
	return (x - y) * (x - y) + (x - z) * (x - z) + (y - z) * (y - z);
}

ll force (int a, int b, int c, int n) {
	suf[n + 1] = n + 1;
	for (int i = 1; i <= n; i ++) pre[i] = g[i].t == a ? i : pre[i - 1];
	for (int i = n; i >= 0; i --) suf[i] = g[i].t == c ? i : suf[i + 1];
	ll ans = 6000000000000000000;
	for (int i = 1; i <= n; i ++)
		if (g[i].t == b and pre[i] >= 1 and suf[i] <= n)
			ans = std::min(ans, get(g[pre[i]].x, g[i].x, g[suf[i]].x));
	return ans;
}

int main () {
	int T = read;
	while (T --) {
		int A = read, B = read, C = read;
		/* for (int i = 1; i <= A; i ++) read(a[i]); */
		/* for (int i = 1; i <= B; i ++) read(b[i]); */
		/* for (int i = 1; i <= C; i ++) read(c[i]); */
		int n = 0;
		for (int i = 1; i <= A; i ++) g[++ n] = {read, 1};
		for (int i = 1; i <= B; i ++) g[++ n] = {read, 2};
		for (int i = 1; i <= C; i ++) g[++ n] = {read, 3};
		std::sort(g + 1, g + n + 1, [] (gem a, gem b) {
					return a.x < b.x;
				});
		printf("%lld\n", std::min({
					force(1, 2, 3, n),
					force(1, 3, 2, n),
					force(2, 1, 3, n),
					force(2, 3, 1, n),
					force(3, 1, 2, n),
					force(3, 2, 1, n)}));
	}
}