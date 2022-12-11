#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 62, M = 4e4 + 10;
int n, m, k, a[N][M], s[N][M], dp[N][M];
int calc(int x, int y) {
	return s[x][y + k - 1] - s[x][y - 1] + s[x + 1][y + k - 1] - s[x + 1][y - 1];
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) scanf("%d", &a[i][j]);
		for(int j = 1; j <= m + k; j ++) s[i][j] = s[i][j - 1] + a[i][j];
	}
	for(int i = 1; i <= m; i ++) dp[1][i] = calc(1, i);
	static int q[M], l, r;
	for(int i = 2; i <= n; i ++) {
		l = r = 0; int Max = -2e9;
		for(int j = 1; j <= m; j ++) {
			if(j - k >= 1) Max = max(Max, dp[i - 1][j - k]);
			while(l < r && dp[i - 1][q[r - 1]] - s[i][q[r - 1] + k - 1] <= dp[i - 1][j] - s[i][j + k - 1]) r --;
			q[r ++] = j;
			while(l < r && q[l] + k - 1 < j) l ++;
			dp[i][j] = calc(i, j) + max(Max, dp[i - 1][q[l]] - s[i][q[l] + k - 1] + s[i][j - 1]);
		}
		l = r = 0; Max = -2e9;
		for(int j = m; j >= 1; j --) {
			if(j + k <= m) Max = max(Max, dp[i - 1][j + k]);
			while(l < r && dp[i - 1][q[r - 1]] + s[i][q[r - 1] - 1] <= dp[i - 1][j] + s[i][j - 1]) r --;
			q[r ++] = j;
			while(l < r && q[l] >= j + k) l ++;
			dp[i][j] = max(dp[i][j], calc(i, j) + max(Max, dp[i - 1][q[l]] + s[i][q[l] - 1] - s[i][j + k - 1]));
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i ++) ans = max(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}