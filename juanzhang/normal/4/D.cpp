#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
const int maxn = 5010;
ppi a[maxn];
int n, w, h, dp[maxn], pre[maxn];

int dfs(int x) {
	if (~dp[x]) {
		return dp[x];
	}
	dp[x] = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i].fir.fir > a[x].fir.fir && a[i].fir.sec > a[x].fir.sec && dp[x] < dfs(i)) {
			dp[x] = dp[i], pre[x] = i;
		}
	}
	return ++dp[x];
}

void write(int x) {
	if (x) {
		printf("%d ", x);
	}
	if (pre[x]) {
		write(pre[x]);
	}
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d %d", &n, &w, &h);
	a[0] = make_pair(make_pair(w, h), 0);
	for (int i = 1; i <= n; i++) {
		a[i].sec = i;
		scanf("%d %d", &a[i].fir.fir, &a[i].fir.sec);
	}
	dfs(0);
	printf("%d\n", --dp[0]);
	if (dp[0]) {
		write(0);
	}
	return 0;
}