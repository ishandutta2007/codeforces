#include <cstdio>
#include <cstring>

const int N = 1005;

int n, k, d, sum = 0, ans[N][N], save[N];

bool dfs(int u) {
	int i;
	if (u == d) {
		for (i = 0; i < d; i++)
			ans[sum][i] = save[i];
		sum++;
		if (sum == n) {
			for (i = 0; i < d; i++) {
				for (int j = 0; j < n - 1; j++)
					printf("%d ", ans[j][i]);
				printf("%d\n", ans[n - 1][i]);	
			}
			return true;
		}
		return false;
	}
	for (i = 1; i <= k; i++) {
		save[u] = i;
		if (dfs(u + 1)) return true;
	}
	return false;
}

int main() {
	scanf("%d%d%d", &n, &k, &d);
	if (!dfs(0)) printf("-1\n");
	return 0;
}