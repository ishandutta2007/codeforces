#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int n, a[5005];

inline void Main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	std::vector <int> cnt[5005];
	rep(i, n) cnt[i].assign(n, 0);
	rep(i, n) for (int j = i + 1; j < n; ++ j)
		if (a[i] < a[j]) cnt[i][j] += 1;
	rep(i, n - 1) rep(j, n) cnt[i + 1][j] += cnt[i][j];
	rep(i, n) rep(j, n - 1) cnt[i][j + 1] += cnt[i][j];
	long long ans = 0;
	rep(i, n) if (i) for (int j = i + 2; j < n; ++ j)
		if (a[i] > a[j]) ans += cnt[i - 1][j - 1] - cnt[i - 1][i];
	printf("%lld\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}