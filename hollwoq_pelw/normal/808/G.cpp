#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n, m, p[N], dp[N], pre[N];
char s[N], t[N];

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	cin >> (s + 1) >> (t + 1);
	n = strlen(s + 1);
	m = strlen(t + 1);

	for (int i = 2; i <= m; i++) {
		int j = p[i - 1];
		while (j && t[j + 1] != t[i])
			j = p[j];
		p[i] = j + (t[j + 1] == t[i]);
	}


	for (int i = m; i <= n; i++) {
		bool eq = 1;
		for (int j = 1; j <= m && eq; j++)
			if (s[i - m + j] != t[j] && s[i - m + j] != '?') eq = 0;

		if (eq) {
			dp[i] = max(dp[i], pre[i - m] + 1);
			for (int j = p[m]; j; j = p[j])
				dp[i] = max(dp[i], dp[i - m + j] + 1);
		}
		pre[i] = max(pre[i - 1], dp[i]);
	}

	cout << pre[n];
}