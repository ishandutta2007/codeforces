#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 2005;

char s[N], p[N];
int n, m;
int dp[N][N];
int cnt[N], r[N];

int main() {
	scanf("%s%s", s + 1, p + 1);
	n = strlen(s + 1), m = strlen(p + 1);
	for (int i = 1; i <= n; i++) {
		int u = i, v = 1;
		while (v <= m) {
			while (u <= n && s[u] != p[v]) {
				cnt[i]++;
				u++;
			}
			if (u == n + 1) {
				cnt[i] = -1;
				break;
			}
			u++;
			v++;
		}
		r[i] = u - 1;
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[i][j] == -1) continue;
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
			if (cnt[i + 1] == -1) continue;
			dp[r[i + 1]][j + cnt[i + 1]] = max(dp[r[i + 1]][j + cnt[i + 1]], dp[i][j] + 1);
		}
		//for (int j = 0; j <= i; j++) printf("%d %d %d\n", i, j, dp[i][j]);
	}
	for (int i = n - 1; i >= 0; i--) dp[n][i] = max(dp[n][i], dp[n][i + 1] - 1);
	for (int i = 0; i <= n; i++) printf("%d ", dp[n][i]); printf("\n");
	return 0;
}