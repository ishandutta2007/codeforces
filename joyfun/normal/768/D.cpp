#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second

const int N = 8005;
double dp[N][1005], p[N];
int k, q;

int main() {
	scanf("%d%d", &k, &q);
	dp[0][0] = 1.0;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] += dp[i - 1][j] * j / k;
			if (j) dp[i][j] += dp[i - 1][j - 1] * (k - j + 1) / k;
		}
	}
	for (int i = 0; i < N; i++) p[i] = dp[i][k];
	int x;
	while (q--) {
		scanf("%d", &x);
		printf("%d\n", lower_bound(p, p + N, x * 1.0 / 2000) - p);
	}
	return 0;
}