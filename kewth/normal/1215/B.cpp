#if 0
date +%Y.%m.%d


#endif
#include <cstdio>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long lolong;
inline int input() { int x; scanf("%d", &x); return x; }

const int maxn = 200005;
int a[maxn];

int main() {
	int n = input();
	for(int i = 1; i <= n; i ++)
		a[i] = input() < 0;
	for(int i = 1; i <= n; i ++)
		a[i] ^= a[i - 1];
	int cnt[2] = {1, 0};
	lolong ans[2] = {0, 0};
	for(int i = 1; i <= n; i ++) {
		/* debug("%d\n", a[i]); */
		ans[0] += cnt[a[i]];
		ans[1] += cnt[!a[i]];
		cnt[a[i]] ++;
	}
	printf("%lld %lld\n", ans[1], ans[0]);
}