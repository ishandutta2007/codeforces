#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

const int mxn = 5005;
const int mod = 998244353;

int qp(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = ll(x) * x % mod)
		if (n & 1) ans = ll(ans) * x % mod;
	return ans;
}

int inv(int x) { return qp(x, mod - 2); }

int n;
int fac[mxn], ifac[mxn];
int S[mxn][mxn];
int c[mxn][mxn];

int comb(int n, int m) {
	if (m < 0 || m > n) return 0;
	return ll(fac[n]) * ifac[m] % mod * ifac[n - m] % mod;
}

int main() {
	scanf("%d", &n);
	rep(i, mxn) fac[i] = i ? ll(i) * fac[i - 1] % mod : 1;
	ifac[mxn - 1] = inv(fac[mxn - 1]);
	for (int i = mxn - 1; i; -- i) ifac[i - 1] = ll(i) * ifac[i] % mod;
	rep(i, mxn) rep(j, i + 1) S[i][j] = j ? (S[i - 1][j - 1] + ll(j) * S[i - 1][j]) % mod : (i == 0);
	rep(j, n + 1) for (int i = n; ~i; -- i)
		c[i][j] = (c[i + 1][j] + ll(comb(n, i)) * fac[n - i] % mod * S[i][i - j] % mod * fac[i - j] % mod) % mod;
	rep(k, n) {
		int ans = 0;
		for (int j = k; j <= n; ++ j) {
			int cur = ll(comb(j, k)) * c[k + 1][j] % mod;
			if ((j - k) & 1) (ans += mod - cur) %= mod;
			else (ans += cur) %= mod;
		}
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}