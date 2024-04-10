#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1005;

struct Num {
	int v[10], la;
} num[N];

bool cmp(Num a, Num b) {
	return a.la < b.la;
}

int n, k, dp[N][N];

bool judge(int i, int j) {
	for (int x = 0; x < k; x++) {
		if (num[i].v[x] < num[j].v[x]) return false;
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; i++) {
		int tmp;
		for (int j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			num[tmp].v[i] = j;
		}
	}
	for (int i = 0; i <= n; i++) {
		int maxv = 0;
		for (int j = 0; j < k; j++) {
			maxv = max(maxv, num[i].v[j]);
		}
		num[i].la = maxv;
	}
	sort(num, num + n + 1, cmp);
	/*
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			printf("%d ", num[i].v[j]);
		}
		printf("\n");
	}*/
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (judge(i, j)) {
				dp[i][i] = max(dp[i][i], dp[i][j] + 1);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}