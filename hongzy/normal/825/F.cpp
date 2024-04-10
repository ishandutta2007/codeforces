#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 8006;
char s[N];
int n, g[N], dp[N], f[N];
void solve(char *s, int n) {
	f[1] = 0;
	for(int i = 2; i <= n; i ++) {
		int j = f[i - 1];
		while(j && s[j + 1] != s[i]) j = f[j];
		f[i] = s[j + 1] == s[i] ? j + 1 : 0;
	}
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i ++) g[i] = g[i / 10] + 1;
	dp[0] = 0; fill(dp + 1, dp + n + 1, n + 1);
	for(int i = 0; i < n; i ++) {
		solve(s + i, n - i);
		for(int j = i + 1; j <= n; j ++)
			if((j - i) % (j - i - f[j - i]) == 0)
				dp[j] = min(dp[j], dp[i] + g[(j - i) / (j - i - f[j - i])] + j - i - f[j - i]);
			else dp[j] = min(dp[j], dp[i] + 1 + j - i);
	}
	printf("%d\n", dp[n]);
	return 0;
}