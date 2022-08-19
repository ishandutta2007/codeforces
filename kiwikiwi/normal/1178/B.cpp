#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
#define maxN 1234567

char s[maxN];
i64 dp[maxN][5];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 3; j++)
			dp[i][j] = dp[i - 1][j];
		if (i >= 2 && s[i] == 'v' && s[i - 1] == 'v')
			dp[i][1] += dp[i - 2][0];
		if (s[i] == 'o')
			dp[i][2] += dp[i - 1][1];
		if (i >= 2 && s[i] == 'v' && s[i - 1] == 'v')
			dp[i][3] += dp[i - 2][2];
	}
	printf("%lld\n",dp[n][3]);
}