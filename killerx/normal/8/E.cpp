#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n; ll K;
int cur[55];
ll dp[55][2][2][4];

ll DP() {
	memset(dp, 0, sizeof(dp)); dp[0][0][0][0] = 1;
	for (int i = 0; i * 2 < n; ++ i) for (int f0 = 0; f0 < 2; ++ f0) for (int f1 = 0; f1 < 2; ++ f1) for (int exs = 0; exs < 4; ++ exs) {
		for (int c0 = 0; c0 < 2; ++ c0) for (int c1 = 0; c1 < 2; ++ c1) {
			if (~cur[i] && c0 != cur[i]) continue;
			if (~cur[n - 1 - i] && c1 != cur[n - 1 - i]) continue;
			if (n % 2 == 1 && i == n / 2 && c0 != c1) continue;
			if (!f0 && c0 > c1) continue;
			if (!f1 && c0 > (!c1)) continue;
			dp[i + 1][f0 | (c0 < c1)][f1 | (c0 < (!c1))][exs | (1 << c0) | (1 << c1)] += dp[i][f0][f1][exs];
		}
	}
	ll ans = 0;
	for (int f0 = 0; f0 < 2; ++ f0) for (int f1 = 0; f1 < 2; ++ f1) ans += dp[(n + 1) / 2][f0][f1][3];
	return ans;
}

int main() {
	scanf("%d%lld", &n, &K);
	memset(cur, -1, sizeof(cur));
	if (DP() < K) {
		puts("-1"); return 0;
	}
	for (int i = 0; i < n; ++ i) {
		for (int f = 0; f < 2; ++ f) {
			cur[i] = f;
			ll x = DP();
			if (x < K) K -= x;
			else break;
		}
		putchar(cur[i] + '0');
	}
	puts("");
	return 0;
}