#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

inline void Main() {
	int n; scanf("%d", &n);
	std::vector <int> a(n);
	rep(i, n) scanf("%d", &a[i]);
	std::vector <std::vector <int> > cost(n);
	rep(i, n) cost[i].resize(n);
	for (int l = 0; l < n; ++ l) for (int r = l; r < n; ++ r) {
		std::set <int> st;
		for (int i = l; i <= r; ++ i) st.insert(a[i]);
		int x = 0;
		while (st.find(x) != st.end()) ++ x;
		cost[l][r] = 1 + x;
	}
	int ans = 0;
	for (int l = 0; l < n; ++ l) {
		std::vector <int> dp(n + 1);
		dp[l] = 0;
		for (int i = l; i < n; ++ i) {
			for (int j = i; j < n; ++ j) {
				dp[j + 1] = std::max(dp[j + 1], dp[i] + cost[i][j]);
			}
		}
		for (int i = l + 1; i <= n; ++ i) ans += dp[i];
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}