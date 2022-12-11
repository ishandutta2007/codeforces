#include <algorithm>
#include <cstdio>
using namespace std;
const int mo = 1e9 + 7;
const int inv2 = (mo + 1) >> 1;
const int N = 5005;
int n, k, S2[N][N];
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mo)
		if(b & 1) ans = 1ll * ans * a % mo;
	return ans;
}
int main() {
	S2[0][0] = 1; n = N - 5;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= i; j ++) {
			S2[i][j] = (S2[i - 1][j - 1] + 1ll * j * S2[i - 1][j]) % mo;
		}
	}
	scanf("%d%d", &n, &k);
	int ans = 0, bin = qpow(2, n), tmp = 1;
	for(int i = 1; i <= k && i <= n; i ++) {
		bin = 1ll * bin * inv2 % mo;
		tmp = 1ll * tmp * (n - i + 1) % mo;
		int r = 1ll * S2[k][i] * tmp % mo * bin % mo;
		(ans += r) >= mo ? ans -= mo : 0;
	}
	printf("%d\n", ans);
	return 0;
}