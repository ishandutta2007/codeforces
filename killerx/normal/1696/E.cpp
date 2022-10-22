#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e6 + 5;
const int mod = 1e9 + 7;

inline int qpow(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}

int fac[mxn], ifac[mxn];

inline int comb(int n, int m) {
	if (m < 0 || m > n) return 0;
	return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int n, a[mxn];

int main() {
	rep(i, mxn) fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
	ifac[mxn - 1] = qpow(fac[mxn - 1], mod - 2);
	for (int i = mxn - 1; i; -- i) ifac[i - 1] = 1LL * i * ifac[i] % mod;
	scanf("%d", &n);
	++ n;
	rep(i, n) scanf("%d", &a[i]);
	int ans = 0;
	rep(i, n) ans = (ans + comb(i + a[i], i + 1)) % mod;
	printf("%d\n", ans);
	return 0;
}