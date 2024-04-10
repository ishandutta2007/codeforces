#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second

const int MOD = 1e9+7;
const int N = 2e5+5;

int F, W, H, f[N], rf[N];

void pp(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int pow_mod(int x, int k) {
	int ans = 1;
	while (k) {
		if (k&1) ans = 1ll * ans * x % MOD;
		x = 1ll * x * x % MOD;
		k >>= 1;
	}
	return ans;
}

int C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return 1ll * f[n] * rf[m] % MOD * rf[n - m] % MOD;
}

int cal(int n, int m) {
	if (n == 0 && m == 0) return 1;
	return C(n - 1, m - 1);
}

int main() {
	f[0] = 1; for (int i = 1; i < N; i++) f[i] = 1ll * f[i - 1] * i % MOD;
	rf[N - 1] = pow_mod(f[N - 1], MOD - 2); for (int i = N - 2; i >= 0; i--) rf[i] = 1ll * rf[i + 1] * (i + 1) % MOD;
	scanf("%d%d%d", &F, &W, &H);
	if (W == 0) {
		printf("1\n");
		return 0;
	}
	int ans = 0, tot = 0;
	for (int i = 1; i <= W; i++) {
		ll yu = W - 1ll * i * (H + 1);
		if (yu >= 0) {
			int ww = C(yu + i - 1, i - 1);
			pp(ans, 1ll * cal(F, i - 1) * ww % MOD);
			pp(ans, 1ll * cal(F, i + 1) * ww % MOD);
			pp(ans, 2ll * cal(F, i) * ww % MOD);
		}
		pp(tot, 1ll * cal(F, i - 1) * cal(W, i) % MOD);
		pp(tot, 1ll * cal(F, i + 1) * cal(W, i) % MOD);
		pp(tot, 2ll * cal(F, i) * cal(W, i) % MOD);
	}
	ans = 1ll * ans * pow_mod(tot, MOD - 2) % MOD;
	printf("%d\n", ans);
	return 0;
}