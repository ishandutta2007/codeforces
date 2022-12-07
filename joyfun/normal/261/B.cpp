#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 55;
int n, a[N], p, b[N], bn;
ll dp[N][N][N];
double f[N];

double get(int bid) {
	bn = 0;
	for (int i = 1; i <= n; i++) if (i != bid) b[++bn] = a[i];
	memset(dp, 0, sizeof(dp));
	dp[0][0][0] = 1;
	for (int i = 1; i <= bn; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= p; k++) {
				dp[i][j][k] = dp[i - 1][j][k];
				if (j - 1 >= 0 && k - b[i] >= 0) 
					dp[i][j][k] += dp[i - 1][j - 1][k - b[i]];
			}
		}
	}
	double ans = 0;
	for (int i = 0; i <= bn; i++)
		for (int j = p; j >= p - a[bid] + 1; j--) 
			ans += exp(log(1ll * dp[bn][i][j] * i) + f[i] + f[bn - i] - f[n]);
	return ans;
}

int main() {
	for (int i = 1; i < N; i++) f[i] = f[i - 1] + log(i * 1.0);
	scanf("%d", &n);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	scanf("%d", &p);
	if (sum <= p) {
		printf("%d\n", n);
		return 0;
	}
	double ans = 0;
	for (int i = 1; i <= n; i++) ans += get(i);
	printf("%.12f\n", ans);
	return 0;
}