#include <stdio.h>
#include <string.h>

char str[20];
int num[20], m, n, vis[(1<<18)][105];
__int64 dp[(1<<18)][105];

__int64 dfs(int s, int mo) {
	__int64 &ans = dp[s][mo];
	if (vis[s][mo]) return ans;
	vis[s][mo] = 1;
	int v[10];
	memset(v, 0, sizeof(v));
	if (s == (1<<n) - 1 && mo == 0)
		return ans = 1;
	for (int i = 0; i < n; i++) {
		if (s == 0 && num[i] == 0) continue;
		if (s&(1<<i)) continue;
		if (v[num[i]]) continue;
		v[num[i]] = 1;
		ans += dfs(s^(1<<i), (mo * 10 + num[i]) % m);
	}
	return ans;
}

int main() {
	scanf("%s%d", str, &m);
	n = strlen(str);
	for (int i = 0; str[i]; i++)
		num[i] = str[i] - '0';
	printf("%I64d\n", dfs(0, 0));
	return 0;
}