#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
} read;

const int maxn = 100005, maxm = 7;
const ll inf = 1000000000000000000;
ll f[maxn][1 << maxm];
int count[1 << maxm];
struct peo {
	int a, b[7];
} p[maxn];

int main () {
	int n = read, m = read, k = read;
	for (int i = 1; i <= n; i ++) read(p[i].a);
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < m; j ++)
			read(p[i].b[j]);

	std::sort(p + 1, p + n + 1, [] (peo a, peo b) {
				return a.a > b.a;
			});

	for (int S = 1; S < (1 << m); S ++)
		count[S] = count[S & (S - 1)] + 1;

	for (int S = 1; S < (1 << m); S ++)
		f[0][S] = - inf;
	for (int i = 1; i <= n; i ++) {
		for (int S = 0; S < (1 << m); S ++)
			if (count[S] <= i) {
				f[i][S] = f[i - 1][S];
				if (i - count[S] <= k) f[i][S] += p[i].a;
				for (int j = 0; j < m; j ++)
					if (S >> j & 1)
						f[i][S] = std::max(f[i][S], f[i - 1][S ^ (1 << j)] + p[i].b[j]);
			} else
				f[i][S] = - inf;
	}

	ll ans = 0;
	for (int S = 0; S < (1 << m); S ++)
		ans = std::max(ans, f[n][S]);
	printf("%lld\n", ans);
}