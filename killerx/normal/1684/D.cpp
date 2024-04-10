#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n, k;
int a[mxn];
int va[mxn];

inline void Main() {
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%d", &a[i]), va[i] = -a[i] + (n - i - 1);
	std::sort(va, va + n);
	long long ans = 1LL << 60, cur = 0;
	rep(i, n) cur += a[i];
	for (int i = 0; i <= k; ++ i) {
		ans = std::min(ans, cur);
		cur += va[i] - i;
	}
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}