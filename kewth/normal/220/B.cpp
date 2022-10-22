#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
} read;

const int maxn = 100005, maxb = 500;
int a[maxn];
int t[maxb][maxn];
int tot[maxn];
int val[maxb];

int main () {
	int n = read, q = read;
	for (int i = 1; i <= n; i ++)
		if ((a[i] = read) <= n)
			++ tot[a[i]];

	int p = 0;
	for (int x = 1; x <= n; x ++)
		if (tot[x] >= x) {
			val[++ p] = x;
			for (int i = 1; i <= n; i ++)
				t[p][i] = t[p][i - 1] + (a[i] == x);
		}

	while (q --) {
		int l = read, r = read, ans = 0;
		for (int i = 1; i <= p; i ++)
			if (t[i][r] - t[i][l - 1] == val[i])
				++ ans;
		printf("%d\n", ans);
	}
}