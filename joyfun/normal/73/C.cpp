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

const int inf = 0x3f3f3f3f;
const int N = 105;
char s[N], x, y;
int k, c, g[27][27];
int dp[N][N][27];

int main() {
	scanf("%s%d", s + 1, &k);
	int n; scanf("%d\n", &n);
	while (n--) {
		scanf("%c %c %d\n", &x, &y, &c);
		int u = x - 'a', v = y - 'a';
		g[u][v] = c;
	}
	n = strlen(s + 1);
	for (int i = 0; i < 26; i++)
		dp[0][0][i] = -inf;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k && j <= i; j++) {
			for (int x = 0; x < 26; x++) {
				dp[i][j][x] = -inf;
				for (int y = 0; y <= 26; y++) {
					if (i > 1 && y == 26) continue;
					int c = s[i] - 'a';
					if (j - (x != c) >= 0 && j - (x != c) < i) {
						dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j - (x != c)][y] + g[y][x]);
					}
				}
			}
		}
	}
	int ans = -inf;
	for (int i = 0; i <= k; i++)
		for (int j = 0; j < 26; j++)
			ans = max(ans, dp[n][i][j]);
	printf("%d\n", ans);
	return 0;
}