#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int N = 1000005;

int dp[N][20], pri[N], pn, vis[N];

void pp(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	for (int i = 2; i < N; i++) {
		if (vis[i]) continue;
		pri[pn++] = i;
		if (1LL * i * i >= 1LL * N) continue;
		for (int j = i * i; j < N; j += i)
			vis[j] = 1;
	}
	for (int i = 1; i < 20; i++) dp[0][i] = 2;
	for (int i = 1; i < N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 20; j++)
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
	}
	int q;
	scanf("%d", &q);
	int r, n;
	while (q--) {
		scanf("%d%d", &r, &n);
		int ans = 1;
		for (int i = 0; i < pn && pri[i] * pri[i] <= n; i++) {
			if (n % pri[i] == 0) {
				int cnt = 0;
				while (n % pri[i] == 0) {
					cnt++;
					n /= pri[i];
				}
				ans = 1LL * ans * dp[r][cnt] % MOD;
			}
		}
		if (n != 1) ans = 1LL * ans * dp[r][1] % MOD;
		printf("%d\n", ans);
	}
	return 0;
}