#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mxn = 2e5 + 5;
int n, k, a[mxn];
i64 s[mxn];

inline void Main() {
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) s[i + 1] = s[i] + a[i];
	int m = std::min(k, n);
	i64 ans = 0;
	for (int i = 0; i < m; ++ i) ans += k - 1 - i;
	i64 base = 0;
	rep(i, n - m + 1) base = std::max(base, s[i + m] - s[i]);
	printf("%lld\n", ans + base);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T --) Main();
    return 0;
}