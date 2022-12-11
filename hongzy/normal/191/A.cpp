#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int n, dp[26][26]; //dp[i][j]
char s[20];

int main() {
	scanf("%d", &n);
	int cur = 1;
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s + 1);
		int w = strlen(s + 1), l = s[1] - 'a', r = s[w] - 'a';
		for(int x = 0; x < 26; x ++) if(dp[x][l]) {
			dp[x][r] = max(dp[x][r], dp[x][l] + w);
		}
		dp[l][r] = max(dp[l][r], w);
	}
	int ans = 0;
	for(int i = 0; i < 26; i ++) {
		ans = max(ans, dp[i][i]);
	}
	printf("%d\n", ans);
	return 0;
}