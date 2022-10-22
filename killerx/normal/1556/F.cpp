#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 1e9 + 7;
const int mxn = 14;

inline int qpow(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}

int n;
int a[mxn];
int win[mxn][mxn];
int f[1 << mxn];
int g[1 << mxn];
std::unordered_map <int, int> h[1 << mxn];

int F(int);
int G(int);
int H(int, int);

int F(int mask) {
	int &ans = f[mask];
	if (~ans) return ans;
	if (!mask) return 1;
	ans = 0;
	for (int S = mask; S; S = (S - 1) & mask)
		ans = (ans + 1LL * F(mask ^ S) * G(S) % mod * H(S, mask ^ S)) % mod;
	return ans;
}

int G(int mask) {
	int &ans = g[mask];
	if (~ans) return ans;
	ans = 1;
	for (int S = mask; S; S = (S - 1) & mask) if (S != mask)
		ans = (ans + mod - 1LL * G(S) * H(S, mask ^ S) % mod) % mod;
	return ans;
}

int H(int S, int T) {
	if (h[S].find(T) != h[S].end()) return h[S][T];
	int &ans = h[S][T];
	ans = 1;
	rep(i, n) if (S >> i & 1) {
		rep(j, n) if (T >> j & 1) {
			ans = 1LL * ans * win[i][j] % mod;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) rep(j, n) if (i != j) win[i][j] = 1LL * a[i] * qpow(a[i] + a[j], mod - 2) % mod;
	memset(f, -1, sizeof(f)); memset(g, -1, sizeof(g));
	int ans = 0;
	rep(S, 1 << n) if (S) {
		int mask = (1 << n) - 1;
		ans = (ans + 1LL * __builtin_popcount(S) * F(mask ^ S) % mod * G(S) % mod * H(S, mask ^ S)) % mod;
	}
	printf("%d\n", ans);
	return 0;
}