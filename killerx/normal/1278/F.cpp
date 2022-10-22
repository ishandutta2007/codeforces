#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

const int mxn = 5e3 + 5;
const int mod = 998244353;

int n, m, k;
int S[mxn][mxn];

int qp(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = ll(x) * x % mod)
		if (n & 1) ans = ll(ans) * x % mod;
	return ans;
}

int inv(int x) {
	return qp(x, mod - 2);
}

int down(int x, int n) {
	int ans = 1;
	for (int i = 0; i < n; ++ i)
		ans = ll(ans) * (x - i) % mod;
	return ans;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	S[0][0] = 1;
	rep(i, k + 1) if (i) rep(j, i + 1) {
		if (j) S[i][j] = (S[i - 1][j - 1] + ll(j) * S[i - 1][j] % mod) % mod;
		else S[i][j] = 0;
	}
	int p = inv(m);
	int ans = 0;
	for (int k0 = 0; k0 <= k; ++ k0) {
		int cur = 1;
		cur = ll(cur) * down(n, k0) % mod;
		cur = ll(cur) * S[k][k0] % mod;
		cur = ll(cur) * qp(p, k0) % mod;
		(ans += cur) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}