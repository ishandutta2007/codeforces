#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int a[55][20005];
int sum[55][20005];

struct SegT {
	static const int N = 2 << 14;
	int add[N << 1], mx[N << 1];
	
	SegT() {
		memset(add, 0, sizeof(add));
		memset(mx, 0, sizeof(mx));
	}
	
	void pushdown(int i) {
		if (add[i]) {
			mx[i] += add[i];
			if (i < N) add[i << 1] += add[i], add[i << 1 | 1] += add[i];
			add[i] = 0;
		}
	}
	
	void upd(int i, int a, int b, int l, int r, int v) {
		if (l <= a && b <= r) {add[i] += v; pushdown(i); return ;}
		pushdown(i); if (r <= a || b <= l) return ;
		int m = (a + b) >> 1;
		upd(i << 1, a, m, l, r, v); upd(i << 1 | 1, m, b, l, r, v);
		mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
	}
	
	void upd(int l, int r, int v) {
		upd(1, 0, N, l, r, v);
	}
} dp[55];

int main() {
	ios :: sync_with_stdio(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			cin >> a[i][j];
			sum[i][j + 1] = sum[i][j] + a[i][j];
		}
	}
	for (int i = 0; i + k <= m; ++ i)
		dp[0].upd(i, i + 1, sum[0][i + k] - sum[0][i]);
	for (int i = 1; i < n; ++ i) {
		for (int j = 0; j + k <= m; ++ j)
			dp[i - 1].upd(j, j + 1, sum[i][j + k] - sum[i][j] - sum[i][k] + sum[i][min(k, j)]);
		dp[i].upd(0, 1, dp[i - 1].mx[1] + sum[i][k] - sum[i][0]);
		for (int j = 1; j + k <= m; ++ j) {
			dp[i - 1].upd(max(0, j - k), j, a[i][j - 1]);
			dp[i - 1].upd(j, min(m - k + 1, j + k), -a[i][j + k - 1]);
			dp[i].upd(j, j + 1, dp[i - 1].mx[1] + sum[i][j + k] - sum[i][j]);
		}
	}
	cout << dp[n - 1].mx[1] << endl;
	return 0;
}