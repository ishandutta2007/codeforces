#if 0
date +%Y.%m.%d

FWT
#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;
inline lolong input() { lolong x; scanf("%lld", &x); return x; }

const int maxn = 21, maxm = 100005;
lolong f[1 << maxn], g[1 << maxn], h[1 << maxn];
char s[maxn][maxm];

void FWT(lolong *a, int n, int typ) {
	for(int m = 1; m < n; m <<= 1)
		for(int i = 0; i < n; i += m << 1)
			for(int k = i; k < i + m; k ++) {
				lolong a0 = a[k], a1 = a[k + m];
				a[k] = a0 + a1;
				a[k + m] = a0 - a1;
			}

	if(typ == -1)
		for(int i = 0; i < n; i ++)
			a[i] /= n;
}

int main() {
	int n = input(), m = input();
	for(int i = 0; i < n; i ++)
		scanf("%s", s[i]);

	for(int j = 0; j < m; j ++) {
		int S = 0;
		for(int i = 0; i < n; i ++)
			if(s[i][j] == '1')
				S += 1 << i;
		g[S] ++;
	}

	for(int S = 0; S < (1 << n); S ++) {
		int tot = 0;
		for(int k = 0; k < n; k ++)
			if(S >> k & 1)
				tot ++;
		f[S] = std::min(tot, n - tot);
	}

	FWT(f, 1 << n, 1);
	FWT(g, 1 << n, 1);

	for(int S = 0; S < (1 << n); S ++)
		h[S] = f[S] * g[S];

	FWT(h, 1 << n, -1);

	lolong ans = 1000000000000000000;
	for(int S = 0; S < (1 << n); S ++)
		ans = std::min(ans, h[S]);

	printf("%lld\n", ans);
}