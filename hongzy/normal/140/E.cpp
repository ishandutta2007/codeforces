#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6 + 10;
const int M = 5005;
int n, m, p, a[N], fac[N], d[M][M];
int Cm[M], dp[2][M], sum[2];
int main() {
	scanf("%d%d%d", &n, &m, &p);
	for(int i = 1; i <= n; i ++) scanf("%d", a + i);
	for(int i = 0; i <= m; i ++) {
		fac[i] = i ? 1ll * fac[i - 1] * i % p : 1;
	}
	Cm[0] = 1;
	for(int i = 1; i < M && i <= m; i ++) {
		Cm[i] = 1;
		for(int j = m; j >= m - i + 1; j --)
			Cm[i] = 1ll * Cm[i] * j % p;
	}
	d[0][0] = 1;
	for(int i = 1; i < M; i ++) {
		for(int j = 1; j <= i; j ++) {
			d[i][j] = (1ll * d[i - 1][j] * (j - 1) + d[i - 1][j - 1]) % p;
		}
	}
	dp[0][0] = sum[0] = 1; int c = 1;
	for(int i = 1; i <= n; i ++, c ^= 1) {
		sum[c] = 0;
		for(int j = 1; j <= a[i] && j <= m; j ++) {
			int x = j <= a[i - 1] ? dp[c ^ 1][j] : 0;
			dp[c][j] = (sum[c ^ 1] - x + p) * 1ll * Cm[j] % p;
			if(x) (dp[c][j] += 1ll * x * (Cm[j] - fac[j] + p) % p) %= p;
			dp[c][j] = 1ll * dp[c][j] % p * d[a[i]][j] % p;
			(sum[c] += dp[c][j]) %= p;
		}
	}
	printf("%d\n", sum[c ^ 1]);
	return 0;
}