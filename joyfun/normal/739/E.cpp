#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
int n, a, b;
double p[N], u[N], pu[N];
double dp[N][N];

int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%lf", &u[i]);
	for (int i = 1; i <= n; i++) pu[i] = 1.0 - (1 - p[i]) * (1 - u[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = min(a, i - 1); j >= max(0, a - n + i - 1); j--) {
			for (int k = min(b, i - 1); k >= max(0, b - n + i - 1) ; k--) {
				dp[j + 1][k] = max(dp[j + 1][k], dp[j][k] + p[i]);
				dp[j][k + 1] = max(dp[j][k + 1], dp[j][k] + u[i]);
				dp[j + 1][k + 1] = max(dp[j + 1][k + 1], dp[j][k] + pu[i]);
			}
		}
	}
	printf("%.12f\n", dp[a][b]);
	return 0;
}