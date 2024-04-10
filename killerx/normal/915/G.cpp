#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 1e9 + 7;

inline int qpow(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}

const int mxn = 2e6 + 5;

int n, k;
int pw[mxn];
int mu[mxn];
int b[mxn];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; ++ i) pw[i] = qpow(i, n);
	mu[1] = 1;
	for (int i = 1; i <= k; ++ i) if (mu[i]) {
		for (int j = i + i; j <= k; j += i) {
			(mu[j] += mod - mu[i]) %= mod;
		}
	}
	int ans = 0;
	for (int i = 1; i <= k; ++ i) {
		for (int j = i; j <= k; j += i) {
			(b[j] += 1LL * mu[i] * (pw[j / i] + mod - pw[j / i - 1]) % mod) %= mod;
		}
	}
	for (int i = 1; i <= k; ++ i) {
		(b[i] += b[i - 1]) %= mod;
		(ans += b[i] ^ i) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}