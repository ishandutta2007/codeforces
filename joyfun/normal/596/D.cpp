#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2005;
const int INF = 0x3f3f3f3f;

int n, h, x[N];
double p;
int vis[N][N][2][2];
double dp[N][N][2][2];
int L[N], R[N];

double dfs(int l, int r, int f1, int f2) {
	if (vis[l][r][f1][f2]) return dp[l][r][f1][f2];
	vis[l][r][f1][f2] = 1;
	if (l > r) return 0.0;
	dp[l][r][f1][f2] = 0;
	dp[l][r][f1][f2] += (dfs(l + 1, r, 0, f2) + min(x[l] - (x[l - 1] + f1 * h), h)) * p / 2;
	dp[l][r][f1][f2] += (dfs(l, r - 1, f1, 1) + min(x[r + 1] - (!f2) * h - x[r], h)) * (1 - p) / 2;
	int i = min(R[l], r);
	if (i == r) dp[l][r][f1][f2] += (dfs(i + 1, r, 1, f2) + min(x[i] + h, x[r + 1] - (!f2) * h) - x[l]) * (1 - p) / 2;
	else dp[l][r][f1][f2] += (dfs(i + 1, r, 1, f2) + x[i] + h - x[l]) * (1 - p) / 2;
	i = max(L[r], l);
	if (i == l) dp[l][r][f1][f2] += (dfs(l, i - 1, f1, 0) + x[r] - max(x[i] - h, x[l - 1] + f1 * h)) * p / 2;
	else dp[l][r][f1][f2] += (dfs(l, i - 1, f1, 0) + x[r] - (x[i] - h)) * p / 2;
	//printf("%d %d %d %d %f\n", l, r, f1, f2, dp[l][r][f1][f2]);
	return dp[l][r][f1][f2];
}

int main() {
	scanf("%d%d%lf", &n, &h, &p);
	for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
	sort(x + 1, x + 1 + n);
	x[0] = -INF; x[n + 1] = INF;
	R[n] = n;
	for (int i = n - 1; i >= 1; i--) {
		R[i] = R[i + 1];
		if (x[i + 1] - x[i] >= h) R[i] = i;
	}
	L[1] = 1;
	for (int i = 2; i <= n; i++) {
		L[i] = L[i - 1];
		if (x[i] - x[i - 1] >= h) L[i] = i;
	}
	printf("%.12f\n", dfs(1, n, 0, 1));
	return 0;
}