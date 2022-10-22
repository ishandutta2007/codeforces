#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int main() {
	int n;
	scanf("%d", &n);
	std::vector <int> c(n);
	rep(i, n) scanf("%d", &c[i]);
	long long ans = 0;
	for (int s = 0; s < n; s += 2) {
		long long A = 0, B = 0;
		for (int t = s + 1; t < n; t += 2) {
			if (c[s] >= A && c[t] >= B) ans += std::min(c[s] - A, c[t] - B) + (A + B > 0 ? 1 : 0);
			if (c[t] >= B) A += c[t] - B, B = 0; else B -= c[t];
			if (t + 1 < n) B += c[t + 1];
		}
	}
	printf("%lld\n", ans);
	return 0;
}