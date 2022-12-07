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

const int N = 305;
const ll inf = (1ll<<60);
int n, m, k;
ll g[N][N], dp[N][N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) g[i][j] = inf;
	int l, r, c;
	while (m--) {
		scanf("%d%d%d", &l, &r, &c);
		g[l][r] = min(g[l][r], 1ll * c);
	}
	for (int i = 1; i <= n; i++)
		for (int j = n - 1; j >= i; j--) g[i][j] = min(g[i][j], g[i][j + 1]);
	for (int i = 0; i <= n; i++) 
		for (int j = 0; j <= n; j++)
			dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[i][j] == inf) continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			for (int x = i + 1; x <= n; x++) {
				dp[x][j + x - i] = min(dp[x][j + x - i], dp[i][j] + g[i + 1][x]);
			}
		}
	}
	ll ans = inf;
	for (int i = 1; i <= n; i++)
		for (int j = k; j <= n; j++) 
			ans = min(ans, dp[i][j]);
	if (ans == inf) ans = -1;
	printf("%lld\n", ans);
	return 0;
}