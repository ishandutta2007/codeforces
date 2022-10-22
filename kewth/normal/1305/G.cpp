#if 0
2020.03.21

 0 0 
 0 




 Kruskal  z x + y = z (x & y = 0) 
 (x, y, z)  O(3^logn) 
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 1 << 18 | 1;
int tot[maxn];
int fa[maxn];

int find (int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main () {
	ll ans = 0;
	int n = read;
	while (n -- ) {
		int x = read;
		++ tot[x];
		ans -= x;
	}
	++ tot[0];

	for (int i = 0; i < maxn; i ++)
		fa[i] = i;
	for (int U = maxn - 1; U >= 0; U --)
		for (int S = U; S >= 0; S --) {
			S &= U;
			int T = U ^ S;
			if (tot[S] and tot[T] and find(S) != find(T)) {
				ans += 1ll * U * (tot[S] + tot[T] - 1);
				tot[S] = tot[T] = 1;
				fa[find(S)] = find(T);
			}
		}

	printf("%lld\n", ans);
}