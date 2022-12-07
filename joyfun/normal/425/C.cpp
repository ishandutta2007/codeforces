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

const int N = 100005;
const int inf = 0x3f3f3f3f;
int n, m, s, e, a[N], b[N];
int dp[2][305], now = 0, pre = 1;
vi g[N];

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &e);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		g[b[i]].pb(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		swap(now, pre);
		for (int j = 0; j <= s / e && j <= i + 1; j++) dp[now][j] = inf;
		for (int j = 0; j <= s / e && j <= i; j++) {
			int k = dp[pre][j];
			dp[now][j] = min(dp[now][j], dp[pre][j]);
			int v = upper_bound(g[a[i + 1]].begin(), g[a[i + 1]].end(), k) - g[a[i + 1]].begin();
			if (v < sz(g[a[i + 1]])) dp[now][j + 1] = min(dp[now][j + 1], g[a[i + 1]][v]);
		}
		for (int j = 0; j <= s / e && j <= i + 1; j++)
			if (dp[now][j] != inf && i + 1 + dp[now][j] + j * e <= s) ans = max(ans, j);
	}
	printf("%d\n", ans);
	return 0;
}