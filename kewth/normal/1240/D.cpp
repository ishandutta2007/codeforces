#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#include <map>
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
int a[maxn];
int f[maxn], g[maxn];
std::map<int, int> las[maxn];

int main () {
	int T = read;
	while (T --) {
		int n = read;
		for (int i = 1; i <= n; i ++)
			read(a[i]);
		f[0] = -1;
		ll ans = 0;
		for (int i = 1; i <= n; i ++)
			las[i].clear();
		for (int i = 1; i <= n; i ++) {
			int j = las[i - 1].count(a[i]) ? las[i - 1][a[i]] : -1;
			/* debug("%d %d\n", i, j); */
			/* while (j != -1 and a[i] != a[j]) j = f[j]; */
			f[i] = j == -1 ? j : j - 1;
			g[i] = f[i] == -1 ? 0 : g[f[i]] + 1;
			if (f[i] != -1) las[i].swap(las[f[i]]);
			las[i][a[i]] = i;
			ans += g[i];
		}
		printf("%lld\n", ans);
	}
}