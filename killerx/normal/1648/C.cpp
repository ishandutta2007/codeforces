#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 18, mod = 998244353;

inline int qpow(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}

int fac[mxn], ifac[mxn];

int n, m;
int S[mxn], T[mxn];

int cnt[mxn];

struct segment_tree {
	int s[mxn << 1];

	inline void init() {
		memset(s, 0, sizeof(s));
	}

	inline void update(int x, int v) {
		s[x += mxn] = v;
		for (; x >>= 1; s[x] = (s[x << 1] + s[x << 1 | 1]) % mod);
	}

	inline int query(int l, int r) {
		int ans = 0;
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ans = (ans + s[l ++]) % mod;
			if (r & 1) ans = (ans + s[-- r]) % mod;
		}
		return ans;
	}
} seg;

int main() {
	rep(i, mxn) fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
	ifac[mxn - 1] = qpow(fac[mxn - 1], mod - 2);
	for (int i = mxn - 1; i; -- i) ifac[i - 1] = 1LL * i * ifac[i] % mod;
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%d", &S[i]);
	rep(i, m) scanf("%d", &T[i]);
	rep(i, n) ++ cnt[S[i]];
	int last = std::min(n, m);
	for (int i = 0; i < std::min(n, m); ++ i) {
		if (!cnt[T[i]]) {
			last = i;
			break;
		}
		-- cnt[T[i]];
	}
	int len = last;
	int ans = 0;
	seg.init();
	int temp = 1;
	rep(i, mxn) temp = 1LL * temp * ifac[cnt[i]] % mod;
	rep(i, mxn) if (cnt[i]) seg.update(i, 1LL * fac[cnt[i]] * ifac[cnt[i] - 1] % mod);
	for (int i = last; ~i; -- i) {
		while (len > i) {
			-- len;
			temp = 1LL * temp * fac[cnt[T[len]]] % mod;
			cnt[T[len]] += 1;
			temp = 1LL * temp * ifac[cnt[T[len]]] % mod;
			seg.update(T[len], 1LL * fac[cnt[T[len]]] * ifac[cnt[T[len]] - 1] % mod);
		}
		if (i == n) ans = (ans + (n < m)) % mod;
		else ans = (ans + 1LL * fac[n - len - 1] * temp % mod * seg.query(0, T[i])) % mod;
	}
	printf("%d\n", ans);
	return 0;
}