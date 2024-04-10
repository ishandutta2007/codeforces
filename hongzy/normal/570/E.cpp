#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 510;
const int mo = 1e9 + 7;

int n, m, dp[2][N][N];
char s[N][N];

void upd(int &x, const int &y) {
	(x += y) >= mo ? x -= mo : 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	if(s[1][1] != s[n][m]) return puts("0"), 0;
	dp[0][1][n] = 1; int r = 0;
	int d = (n + m - 2) / 2, ans = 0;
	for(int i = 0; i < d; i ++, r ^= 1) {
		for(int x1 = 1; x1 <= n; x1 ++) for(int x2 = 1; x2 <= n; x2 ++) dp[r ^ 1][x1][x2] = 0;
		for(int x1 = 1; x1 <= n; x1 ++) for(int x2 = 1; x2 <= n; x2 ++) if(dp[r][x1][x2]) {
			int y1 = i - x1 + 2, y2 = m - i + n - x2;
			if(y1 != m && y2 != 1 && s[x1][y1 + 1] == s[x2][y2 - 1]) upd(dp[r ^ 1][x1][x2], dp[r][x1][x2]);
			if(x1 != n && y2 != 1 && s[x1 + 1][y1] == s[x2][y2 - 1]) upd(dp[r ^ 1][x1 + 1][x2], dp[r][x1][x2]);
			if(y1 != m && x2 != 1 && s[x1][y1 + 1] == s[x2 - 1][y2]) upd(dp[r ^ 1][x1][x2 - 1], dp[r][x1][x2]);
			if(x1 != n && x2 != 1 && s[x1 + 1][y1] == s[x2 - 1][y2]) upd(dp[r ^ 1][x1 + 1][x2 - 1], dp[r][x1][x2]);
		}
	}
	if((n + m) & 1) {
		for(int i = 1; i < n; i ++) upd(ans, dp[r][i][i + 1]);
		for(int i = 1; i <= n; i ++) upd(ans, dp[r][i][i]);
	} else {
		for(int i = 1; i <= n; i ++) upd(ans, dp[r][i][i]);
	}
	printf("%d\n", ans);
	return 0;
}