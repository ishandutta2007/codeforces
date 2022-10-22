#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
using i128 = __int128;

template <int mod, int g> struct ntt {
	static const int mxn = 65536;
	inline int qpow(int x, int n) {
		int ans = 1;
		for (; n; n >>= 1, x = 1LL * x * x % mod)
			if (n & 1) ans = 1LL * ans * x % mod;
		return ans;
	}
	int N, r[mxn], w[mxn];
	inline void init(int n) {
		N = n;
		for (int i = 1; i < n - 1; ++ i)
			r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
		for (int h = 1; h < n; h <<= 1) {
			int temp = qpow(g, (mod - 1) / (h << 1));
			rep(i, h) w[h + i] = i ? 1LL * temp * w[h + i - 1] % mod : 1;
		}
	}
	inline void dft(int a[], int n) {
		if (N != n) init(n);
		for (int i = 1; i < n - 1; ++ i)
			if (i < r[i]) std::swap(a[i], a[r[i]]);
		for (int h = 1; h < n; h <<= 1)
			for (int i = 0; i < n; i += h << 1)
				for (int j = 0; j < h; ++ j) {
					int v = 1LL * a[i + h + j] * w[h + j] % mod;
					a[i + h + j] = a[i + j] - v >= 0 ? a[i + j] - v : a[i + j] + mod - v;
					a[i + j] = a[i + j] + v < mod ? a[i + j] + v : a[i + j] + v - mod;
				}
	}
	inline void idft(int a[], int n) {
		dft(a, n);
		std::reverse(a + 1, a + n);
		int iv = qpow(n, mod - 2);
		rep(i, n) a[i] = 1LL * a[i] * iv % mod;
	}
	inline std::vector <int> mul(const int a[], int n, const int b[], int m) {
		std::vector <int> c(n + m - 1);
		int sz = 1;
		for (; sz < n + m - 1; sz <<= 1);
		static int A[mxn], B[mxn];
		rep(i, sz) A[i] = i < n ? a[i] % mod : 0;
		rep(i, sz) B[i] = i < m ? b[i] % mod : 0;
		dft(A, sz);
		dft(B, sz);
		rep(i, sz) A[i] = 1LL * A[i] * B[i] % mod;
		idft(A, sz);
		rep(i, c.size()) c[i] = A[i];
		return c;
	}
};

inline int inv(int x, int mod) {
	int ans = 1;
	for (int n = mod - 2; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}

const int mxn = 3e4 + 5;
const int mod = 1e9 + 7;

inline int qpow(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}

const int n1 = 943718401, g1 = 7;
const int n2 = 950009857, g2 = 7;
const int n3 = 957349889, g3 = 6;
ntt <n1, g1> ntt1;
ntt <n2, g2> ntt2;
ntt <n3, g3> ntt3;
const i128 N = i128(n1) * n2 * n3;
const int i1 = inv(1LL * n2 * n3 % n1, n1);
const int i2 = inv(1LL * n1 * n3 % n2, n2);
const int i3 = inv(1LL * n1 * n2 % n3, n3);

inline int crt(int a1, int a2, int a3) {
	i128 z = 0;
	z += i128(1LL * a1 * i1 % n1) * n2 * n3;
	z += i128(1LL * a2 * i2 % n2) * n1 * n3;
	z += i128(1LL * a3 * i3 % n3) * n1 * n2;
	assert(z % n1 == a1);
	assert(z % n2 == a2);
	assert(z % n3 == a3);
	return z % N % mod;
}

struct poly : std::vector <int> {
	poly() { clear(); }
	poly(size_t n) { assign(n, 0); }
	poly(std::vector <int> v) { clear(); for (int x : v) push_back(x); }
	poly(std::initializer_list <int> v) { clear(); for (int x : v) push_back(x); }
	inline poly modn(size_t n) const {
		poly p(*this);
		p.resize(n, 0);
		return p;
	}
	friend inline poly operator * (const poly &a, const poly &b) {
		poly c(a.size() + b.size() - 1);
		poly c1 = ntt1.mul(a.data(), a.size(), b.data(), b.size());
		poly c2 = ntt2.mul(a.data(), a.size(), b.data(), b.size());
		poly c3 = ntt3.mul(a.data(), a.size(), b.data(), b.size());
		rep(i, c.size()) c[i] = crt(c1[i], c2[i], c3[i]);
		return c;
	}
};

int fac[mxn], ifac[mxn];

inline int comb(int n, int m) {
	if (m < 0 || m > n) return 0;
	return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int k;

inline poly solve(i64 n) {
	if (n == 0) {
		poly p(k);
		p[0] = 1;
		return p;
	}
	if (n & 1) {
		poly p = solve(n - 1);
		int z = qpow(2, (n - 1) % (mod - 1));
		poly q(k);
		for (int i = 1; i < k; ++ i)
			q[i] = 1LL * qpow(z, i) * ifac[i] % mod;
		return (p * q).modn(k);
	}
	poly p = solve(n >> 1);
	int z = qpow(2, (n >> 1) % (mod - 1));
	poly q(k);
	rep(i, k) q[i] = 1LL * qpow(z, i) * p[i] % mod;
	return (p * q).modn(k);
}

i64 n;

int main() {
	rep(i, mxn) fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
	ifac[mxn - 1] = qpow(fac[mxn - 1], mod - 2);
	for (int i = mxn - 1; i; -- i) ifac[i - 1] = 1LL * i * ifac[i] % mod;
	scanf("%lld %d", &n, &k);
	if (n > k) {
		printf("%d\n", 0);
		return 0;
	}
	++ k;
	poly p = solve(n);
	int ans = 0;
	rep(i, k) ans = (ans + 1LL * fac[i] * p[i] % mod * comb(k - 1, i)) % mod;
	printf("%d\n", ans);
	return 0;
}