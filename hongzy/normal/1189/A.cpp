#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 110;

int n, dp[N], la[N], cnt[2][N];
char s[N];
bool tag[N];

void dfs(int u) {
	if(u == 0) return ;
	dfs(la[u]);
	tag[u + 1] = 1; 
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i ++) {
		cnt[0][i] = cnt[0][i - 1];
		cnt[1][i] = cnt[1][i - 1];
		cnt[s[i] - '0'][i] ++;
	} 
	dp[0] = 0;
	for(int i = 1; i <= n; i ++) {
		dp[i] = 1e9;
		for(int j = 0; j < i; j ++) if(cnt[0][i] - cnt[0][j] != cnt[1][i] - cnt[1][j]) {
			dp[i] = min(dp[i], dp[j] + 1);
			if(dp[i] == dp[j] + 1) la[i] = j;
		}
	}
	printf("%d\n", dp[n]);
	dfs(n);
	for(int i = 1; i <= n; i ++) {
		if(tag[i]) putchar(' ');
		putchar(s[i]);
	}
	return 0;
}