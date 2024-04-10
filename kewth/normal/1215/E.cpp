#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;
inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 400005, maxa = 20;
int cnt[maxa];
lolong g[maxa][maxa];
lolong f[1 << maxa];

int main() {
	int n = input();
	for(int i = 1; i <= n; i ++) {
		int a = input() - 1;
		for(int x = 0; x < maxa; x ++)
			g[x][a] += cnt[x];
		cnt[a] ++;
	}

	f[0] = 0;
	for(int S = 1; S < (1 << maxa); S ++) {
		f[S] = 1000000000000000000;
		for(int k = 0; k < maxa; k ++)
			if(S >> k & 1) {
				lolong now = f[S ^ (1 << k)];
				for(int x = 0; x < maxa; x ++)
					if(S >> x & 1 and x != k)
						now += g[k][x];
				f[S] = std::min(f[S], now);
			}
	}

	printf("%lld\n", f[(1 << maxa) - 1]);
}