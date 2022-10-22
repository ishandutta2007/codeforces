#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	long long n; scanf("%lld", &n);
	std::vector <long long> a(n), b(n);
	rep(i, n) scanf("%lld", &a[i]);
	rep(i, n) scanf("%lld", &b[i]);
	long long base = 0;
	rep(i, n) base += (n - 1) * (a[i] * a[i] + b[i] * b[i]);
	const long long inf = 0x3f3f3f3f3f3f3f3f;
	long long S = 0;
	std::vector <long long> dp(n * 200 + 5, inf);
	dp[0] = 0;
	rep(i, n) {
		std::vector <long long> ndp(n * 200 + 5, inf);
		for (long long sa = 0; sa <= S; ++ sa) {
			long long sb = S - sa;
			ndp[sa + a[i]] = std::min(ndp[sa + a[i]], dp[sa] + a[i] * sa + b[i] * sb);
			ndp[sa + b[i]] = std::min(ndp[sa + b[i]], dp[sa] + b[i] * sa + a[i] * sb);
		}
		ndp.swap(dp);
		S += a[i] + b[i];
	}
	long long ans = inf;
	for (long long sa = 0; sa <= S; ++ sa) {
		ans = std::min(ans, base + 2 * dp[sa]);
	}
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}