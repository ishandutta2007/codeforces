#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 1e9 + 7;
int n, m;
int f[2005][2005];
int c[6005][6005];

int main() {
	scanf("%d %d", &n, &m);
	rep(i, 6005) rep(j, i + 1) c[i][j] = j ? (c[i - 1][j - 1] + c[i - 1][j]) % mod : 1;
	for (int l = 1; l <= n; ++ l) for (int y = 2; y <= m; ++ y) f[l][y] = (c[2 * l + y - 4][y - 2] + f[l - 1][y]) % mod;
	int ans = 0;
	for (int y = 2; y <= m; ++ y) {
		(ans += 1LL * (m - y + 1) % mod * f[n][y] % mod) %= mod;
		for (int t = 2; t <= n; ++ t) (ans += 1LL * (m - y + 1) % mod * f[t][y] % mod * f[n - t + 1][y] % mod) %= mod;
		for (int t = 2; t <= n; ++ t) (ans += mod - 1LL * (m - y + 1) % mod * f[t - 1][y] % mod * f[n - t + 1][y] % mod) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}