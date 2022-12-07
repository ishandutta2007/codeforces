#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 1000000007;
const int N = (1<<20);
int dp[80][N];
int n;
char str[80];

void pp(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int main() {
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 0; j < (1<<20); j++) {
			if (dp[i][j] == 0) continue;
			int sb = 0;
			for (int k = i + 1; k <= n; k++) {
				sb = sb * 2 + str[k] - '0';
				if (sb == 0) continue;
				if (sb > 20) break;
				pp(dp[k][j|(1<<(sb - 1))], dp[i][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		int sb = 0;
		for (int j = 0; j < 20; j++) {
			sb += (1<<j);
			pp(ans, dp[i][sb]);
		}
	}
	printf("%d\n", ans);
	return 0;
}