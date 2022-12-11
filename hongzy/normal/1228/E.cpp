#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int mo = 1e9 + 7;
int qpow(int a, int b) {
	int ans = 1;
	for( ; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = 1ll * ans * a % mo;
	return ans;
}
int C[255][255];
int main() {
	for(int i = 0; i < 255; i ++) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j < i; j ++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mo;
		}
	}
	int n, k, ans = 0;
	scanf("%d%d", &n, &k);
	for(int i = 0; i <= n; i ++) {
		for(int j = 0; j <= n; j ++) {
			int re = (n - i) * (n - j);
			int now = 1ll * C[n][i] * C[n][j] % mo * qpow(k, re) % mo * qpow(k - 1, n * n - re) % mo;
			ans += ((i + j) & 1 ? -1 : 1) * now;	
			ans = (ans % mo + mo) % mo;
		}
	}
	printf("%d\n", ans);
	return 0;
}