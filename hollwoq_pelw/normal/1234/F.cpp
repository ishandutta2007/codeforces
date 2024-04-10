#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

const int N = 1 << 20;

int msk[N], dp[N];
char s[N];

void solve_case() {
	cin >> s;
	msk[0] = 1;
	for (int i = 0; i < strlen(s); i++) {
		int mask = 0;
		for (int j = i; j < strlen(s); j++) {
			if (mask >> (s[j] - 'a') & 1)
				break ;
			mask ^= 1 << (s[j] - 'a');
			msk[mask] = 1;
			dp[mask] = __builtin_popcount(mask);
		}
	}

	for (int i = 0; i < 20; i++)
		for (int mask = 0; mask < N; mask++)
			if (mask >> i & 1)
				dp[mask] = max(dp[mask], dp[mask ^ 1 << i]);

	int res = 0;
	for (int mask = 0; mask < N; mask++) if (msk[mask]) {
		res = max(res, dp[mask] + dp[mask ^ (N - 1)]);
	}
	cout << res << '\n';
}