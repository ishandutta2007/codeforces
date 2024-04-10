#include <algorithm>
#include <cassert>
#include <cstdio>
using namespace std;
const int N = 310;
const int mo = 1e9 + 7;
int n, b, a[N], m, sz[N], C[N][N], dp[N][N], fac[N];
void upd(int &x, const int &y) {
	(x += y) >= mo ? x -= mo : 0;
}
int main() {
	for(int i = 0; i < N; i ++) {
		fac[i] = i ? 1ll * fac[i - 1] * i % mo : 1;
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j ++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mo;
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		int t = 1;
		for(int j = 2; j * j <= a[i]; j ++) {
			if(a[i] % j == 0) {
				int c = 0;
				while(a[i] % j == 0) {
					a[i] /= j; c ++;
				}
				if(c & 1) t *= j;
			}
		}
		if(a[i] > 1) t *= a[i];
		a[i] = t; //printf("%d > ", t);
	}
	sort(a + 1, a + n + 1);
	int col = 0;
	for(int i = 1; i <= n; i ++) {
		if(col != a[i]) {
			b ++; col = a[i]; sz[b] = 1;
		} else sz[b] ++;
	}
	dp[1][sz[1] - 1] = fac[sz[1]];
	for(int i = 2; i <= b; i ++) {
		m += sz[i - 1];
		for(int j = 0; j < m; j ++) if(dp[i - 1][j]) {
			for(int k = 0; k <= min(j, sz[i]); k ++) {
				for(int u = 0; u + k <= sz[i] && u != sz[i]; u ++) {
					upd(dp[i][j - k + u], 1ll * dp[i - 1][j] * C[j][k] % mo * C[m + 1 - j][sz[i] - k - u] % mo * C[sz[i] - 1][sz[i] - 1 - u] % mo * fac[sz[i]] % mo);
				}
			}
		}
	}
	printf("%d\n", dp[b][0]);
	return 0;
}