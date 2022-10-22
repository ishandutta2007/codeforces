#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mod = 998244353;

struct Z {
	int v;
	Z(): v() {}
	Z(int _v): v((_v % mod + mod) % mod) {}
	Z(i64 _v): v(int((_v % mod + mod) % mod)) {}
	static Z raw(int x) { Z v; v.v = x; return v; }
	inline Z operator + (const Z &o) const { return raw(v + o.v < mod ? v + o.v : v + o.v - mod); }
	inline Z operator - (const Z &o) const { return raw(v - o.v >= 0 ? v - o.v : v + mod - o.v); }
	inline Z operator * (const Z &o) const { return raw(int(i64(v) * o.v % mod)); }
	inline Z &operator += (const Z &o) { v += o.v - mod; v += v >> 31 & mod; return *this; }
	inline Z &operator -= (const Z &o) { v -= o.v; v += v >> 31 & mod; return *this; }
	inline Z &operator *= (const Z &o) { v = int(i64(v) * o.v % mod); return *this; }
	inline Z operator - () const { return Z(-v); }
	friend inline Z qpow(Z x, int n) { Z ans = 1; for (; n; n >>= 1, x *= x) if (n & 1) ans *= x; return ans; }
	friend inline Z inv(Z x) { return qpow(x, mod - 2); }
};

const int mxn = 1 << 18;

Z fac[mxn], ifac[mxn];

inline void dft(Z a[], int n) {
	static int r[mxn];
	static Z w[mxn];
	for (int i = 1; i < n - 1; ++ i)
		r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
	for (int h = 1; h < n; h <<= 1) {
		Z temp = qpow(Z(31), (mod - 1) / (h << 1));
		for (int i = 0; i < h; ++ i) w[h + i] = i ? w[h + i - 1] * temp : 1;
	}
	for (int i = 1; i < n - 1; ++ i)
		if (i < r[i]) std::swap(a[i], a[r[i]]);
	for (int h = 1; h < n; h <<= 1)
		for (int i = 0; i < n; i += h << 1)
			for (int j = 0; j < h; ++ j) {
				Z v = a[i + h + j] * w[h + j];
				a[i + h + j] = a[i + j] - v;
				a[i + j] += v;
			}
}

inline void idft(Z a[], int n) {
	dft(a, n);
	std::reverse(a + 1, a + n);
	Z in = inv(Z(n));
	rep(i, n) a[i] *= in;
}

struct poly : std::vector <Z> {
	poly() { clear(); }
	poly(size_t n) { clear(); resize(n); }
	poly(size_t n, Z x) { clear(); assign(n, x); }
	poly(std::vector <Z> v) { clear(); for (Z x : v) push_back(x); }
	poly(std::initializer_list <Z> v) { clear(); for (Z x : v) push_back(x); }
	inline poly mod(size_t n) const {
		poly a = *this;
		a.resize(n);
		return a;
	}
	inline Z operator () (Z x) const {
		Z ans = 0, e = 1;
		rep(i, size()) ans += at(i) * e, e *= x;
		return ans;
	}
	friend inline poly operator + (const poly &a, const poly &b) {
		poly c(std::max(a.size(), b.size()));
		rep(i, a.size()) c[i] += a[i];
		rep(i, b.size()) c[i] += b[i];
		return c;
	}
	friend inline poly operator - (const poly &a, const poly &b) {
		poly c(std::max(a.size(), b.size()));
		rep(i, a.size()) c[i] += a[i];
		rep(i, b.size()) c[i] -= b[i];
		return c;
	}
	friend inline poly operator * (const poly &a, const poly &b) {
		poly c(a.size() + b.size() - 1);
		if (64LL * c.size() >= 1LL * a.size() * b.size())
			rep(i, a.size()) rep(j, b.size()) c[i + j] += a[i] * b[j];
		else {
			static Z A[mxn], B[mxn];
			int sz = 1;
			for (; sz < (int) c.size(); sz <<= 1);
			rep(i, sz) A[i] = i < (int) a.size() ? a[i] : 0;
			rep(i, sz) B[i] = i < (int) b.size() ? b[i] : 0;
			dft(A, sz), dft(B, sz);
			rep(i, sz) A[i] *= B[i];
			idft(A, sz);
			rep(i, c.size()) c[i] = A[i];
		}
		return c;
	}
	friend inline poly inv(const poly &a) {
		int n = (int) a.size();
		if (n == 1) return {inv(a[0])};
		int n0 = (n + 1) / 2;
		poly a0 = a.mod(n0);
		poly b0 = inv(a0);
		poly b = (b0 + b0 - a * b0 * b0).mod(n);
		return b;
	}
	friend inline poly operator / (const poly &a, const poly &b) {
		assert(a.size() >= b.size());
		poly F = a, G = b;
		std::reverse(F.begin(), F.end());
		std::reverse(G.begin(), G.end());
		F = F.mod(a.size() - b.size() + 1);
		G = G.mod(a.size() - b.size() + 1);
		poly H = (F * inv(G)).mod(a.size() - b.size() + 1);
		std::reverse(H.begin(), H.end());
		return H;
	}
	friend inline poly operator % (const poly &a, const poly &b) {
		assert(a.size() >= b.size() && !b.empty());
		return (a - (a / b) * b).mod(b.size() - 1);
	}
};

int n, k;
Z p;
Z a[mxn], s[mxn];

poly temp[mxn];

inline void conq(int i, int l, int r) {
	if (l == r) return temp[i] = {-a[l], 1}, void();
	int m = (l + r) >> 1;
	conq(i << 1, l, m);
	conq(i << 1 | 1, m + 1, r);
	temp[i] = temp[i << 1] * temp[i << 1 | 1];
}

inline void eval(int i, int l, int r, poly P) {
	if (P.size() >= temp[i].size()) P = P % temp[i];
	if (l == r) return s[l] = P[0], void();
	int m = (l + r) >> 1;
	eval(i << 1, l, m, P);
	eval(i << 1 | 1, m + 1, r, P);
}

inline void prep() {
	rep(i, mxn) fac[i] = i ? Z(i) * fac[i - 1] : 1;
	ifac[mxn - 1] = inv(fac[mxn - 1]);
	for (int i = mxn - 1; i; -- i) ifac[i - 1] = Z(i) * ifac[i];
	poly A(1);
	A[0] = fac[k];
	poly B(k + 1);
	B[0] = 1;
	rep(i, k + 1) B[i] -= p * ifac[i];
	poly C = (A * inv(B)).mod(k + 1);
	poly V(k + 1);
	rep(i, k + 1) V[i] = ifac[i] * C[k - i];
	rep(i, n) a[i] += 1;
	conq(1, 0, n - 1);
	eval(1, 0, n - 1, V);
	rep(i, n) s[i] = C[k] - s[i] * qpow(p, a[i].v);
	rep(i, n) a[i] -= 1;
}

int main() {
	scanf("%d %d %d", &n, &k, &p.v);
	rep(i, n) scanf("%d", &a[i].v);
	prep();
	static Z f_p[mxn], f_s[mxn], g_p[mxn], g_s[mxn];
	for (int i = 0; i < n; ++ i) {
		f_p[i] = (i ? f_p[i - 1] : 0) * (a[i - 1] + 1) + 1;
		g_p[i] = (i ? g_p[i - 1] : 0) * (a[i - 1] + 1) + (i ? f_p[i - 1] * a[i - 1] : 0);
	}
	for (int i = n - 1; ~i; -- i) {
		f_s[i] = (i + 1 < n ? f_s[i + 1] : 0) * (a[i + 1] + 1) + 1;
		g_s[i] = (i + 1 < n ? g_s[i + 1] : 0) * (a[i + 1] + 1) + (i + 1 < n ? f_s[i + 1] * a[i + 1] : 0);
	}
	Z ans = 0;
	rep(i, n) {
		Z S = s[i];
		Z C = 0;
		C += f_p[i] * f_s[i];
		C += g_p[i] * f_s[i];
		C += f_p[i] * g_s[i];
		ans += S * C;
	}
	printf("%d\n", ans.v);
	return 0;
}