#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 5e3 + 5, mod = 998244353;
int n, m, k, s[N][N];
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
		if(b & 1) ans = 1ll * ans * a % mod;
	return ans;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	int inv = qpow(m, mod - 2);
	s[0][0] = 1;
	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= i; j ++) {
			s[i][j] = (s[i - 1][j - 1] + 1ll * j * s[i - 1][j]) % mod;
		}
	}
	int ans = 0, res = 1, pd = 1;
	for(int i = 1; i <= k; i ++) {
		pd = 1ll * pd * (n - i + 1) % mod;
		res = 1ll * res * inv % mod;
		ans = (ans + 1ll * s[k][i] * res % mod * pd) % mod;
	}
	printf("%d\n", ans);
	return 0;
}