#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

ll dp[105][105][105];
int n, m, k;
int c[105];
int cst[105][105];

int main() {
	n = read(), m = read(), k = read();
	rep(i, n) c[i] = read();
	rep(i, n) rep(j, m) cst[i][j + 1] = read();
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][0] = 0;
	rep(i, n) rep(j, k + 1) {
		for (int l = 0; l <= m; ++ l) {
			if (c[i]) {
				dp[i + 1][j + (c[i] != l)][c[i]] = min(dp[i + 1][j + (c[i] != l)][c[i]], dp[i][j][l]);
			} else {
				for (int nl = 1; nl <= m; ++ nl) {
					dp[i + 1][j + (nl != l)][nl] = min(dp[i + 1][j + (nl != l)][nl], dp[i][j][l] + cst[i][nl]);
				}
			}
		}
	}
	ll ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= m; ++ i) ans = min(ans, dp[n][k][i]);
	if (ans == 0x3f3f3f3f3f3f3f3f) puts("-1");
	else printf("%lld\n", ans);
	return 0;
}