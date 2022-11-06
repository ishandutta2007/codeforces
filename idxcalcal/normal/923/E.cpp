#include <bits/stdc++.h>
#define gc getchar
using namespace std;
typedef long long ll;
inline int read() {
	static int ans, f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
inline ll readl() {
	static ll ans;
	static int f;
	static char ch;
	for (f = 1, ch = gc(); !isdigit(ch); f ^= ch == '-', ch = gc());
	for (ans = 0; isdigit(ch); ans = (((ans << 2) + ans) << 1) + (ch ^ 48), ch = gc());
	return f ? ans : -ans;
}
namespace modular {
    const int mod = 998244353;
    inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
    inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
    inline int mul(int a, int b) { return (ll) a * b % mod; }
    inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
    inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
    inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
    inline int ksm(int a, int p) {
        static int res;
        for (res = 1; p; p >>= 1, Mul(a, a)) {
            if (p & 1) Mul(res, a);
        }
        return res;
    }
    inline int Inv(int a) { return ksm(a, mod - 2); }
}    using namespace modular;
int invv[23], lim, tim;
#define pb push_back
#define rez resize
typedef vector <int> poly;
const int N = 1e5 + 5;
poly w[23], rev[23];
inline void init_w() {
    int lm = 1 << 20;
    w[20].rez(lm);
    w[20][0] = 1, w[20][1] = ksm(3, (mod - 1) >> 21);
    for (int i = 1; i < lm; ++i) w[20][i] = mul(w[20][i - 1], w[20][1]);
    for (int i = 19; ~i; --i) {
        w[i].rez(lm >>= 1);
        for (int j = 0; j < lm; ++j) w[i][j] = w[i + 1][j << 1];
    }
}
inline void init_r(int up) {
    for (lim = 1, tim = 0; lim < up; lim <<= 1, ++tim);
    if (rev[tim].size()) return;
    rev[tim].rez(lim), invv[tim] = Inv(lim);
    for (int i = 1; i < lim; ++i) rev[tim][i] = (rev[tim][i >> 1] >> 1) | ((i & 1) << (tim - 1));
}
inline void ntt(poly &a, int typ) {
    for (int i = 0; i < lim; ++i) if (i < rev[tim][i]) swap(a[i], a[rev[tim][i]]);
    for (int i = 1, t = 0; i < lim; i <<= 1, ++t) for (int j = 0; j < lim; j += i << 1) {
        for (int a0, a1, k = 0; k < i; ++k) {
            a0 = a[j + k], a1 = mul(a[j + k + i], w[t][k]);
            a[j + k] = add(a0, a1);
            a[j + k + i] = dec(a0, a1);
        }
    }
    if (~typ) return;
    reverse(++a.begin(), a.end());
    for (int i = 0; i < lim; ++i) Mul(a[i], invv[tim]);
}
inline poly operator * (poly a, poly b) {
    int n = a.size(), m = b.size(), t = n + m - 1;
    if (!n || !m) return poly(0);
    if (n <= 30 || m <= 30) {
        poly c(t);
        for (int i = 0; i < n; ++i) if (a[i])
        for (int j = 0; j < m; ++j) if (b[j])
        Add(c[i + j], mul(a[i], b[j]));
        return c;
    }
    init_r(t);
    a.rez(lim), ntt(a, 1);
    b.rez(lim), ntt(b, 1);
    for (int i = 0; i < lim; ++i) Mul(a[i], b[i]);
    return ntt(a, -1), a.rez(t), a;
}
inline poly poly_inv(poly a, int k) {
	int n = a.size();
	poly b(k), c;
	b[0] = Inv(a[0]);
	for (int i = 1, l = 2; i < k; i <<= 1, l <<= 1) {
		c.rez(l);
		for (int j = 0; j < l; ++j) c[j] = j < n ? a[j] : 0;
		c = c * b, c.rez(l);
		for (int j = 0; j < l; ++j) c[j] = dec(j ? 0 : 2, c[j]);
		b = b * c, b.rez(l);
	}
	return b.rez(k), b;
}
inline poly operator - (poly a, poly b) {
	int n = b.size();
	if ((int) a.size() < n) a.rez(n);
	for (int i = 0; i < n; ++i) Dec(a[i], b[i]);
	return a;
}
inline poly operator + (poly a, poly b) {
	int n = b.size();
	if ((int) a.size() < n) a.rez(n);
	for (int i = 0; i < n; ++i) Add(a[i], b[i]);
	return a;
}
int fac[N], ifac[N], n;
poly tp, p, E;
inline int C(int n, int m) { return n < m || m < 0 ? 0 : mul(fac[n], mul(ifac[m], ifac[n - m])); }
inline void init_fac() {
	fac[0] = fac[1] = ifac[0] = ifac[1] = 1;
	for (int i = 2; i <= 100001; ++i) fac[i] = mul(fac[i - 1], i);
	ifac[100001] = Inv(fac[100001]);
	for (int i = 100000; i > 1; --i) ifac[i] = mul(ifac[i + 1], i + 1);
}
//x --> x + bas
inline poly trans(poly a, int bas, int k) {
	if (k <= 50) {
		poly b(k);
		for (int i = 0; i < k; ++i) if (a[i])
		for (int j = 0, pw = 1; j <= i; ++j, Mul(pw, bas)) Add(b[i - j], mul(mul(pw, a[i]), C(i, j)));
		return b;
	}
	a.rez(k), tp.rez(k);
	for (int i = 0, pw = 1; i < k; ++i, Mul(pw, bas)) {
		Mul(a[i], fac[i]);
		tp[i] = mul(pw, ifac[i]);
	}
	reverse(a.begin(), a.end());
	a = a * tp, a.rez(k);
	reverse(a.begin(), a.end());
	for (int i = 0; i < k; ++i) Mul(a[i], ifac[i]);
	return a;
}
ll m;
int F[5005][5005];
int main() {
	#ifdef ldxcaicai
	freopen("lx.in", "r", stdin);
	#endif
	init_w(), init_fac();
	n = read();
	m = readl() - 1;
	p.rez(n + 1), E.rez(n + 1);
	poly f(n + 1);
	for (int i = 0; i <= n; ++i) p[i] = read();
	if (m == -1) {
		for (int i = 0; i <= n; ++i) cout << p[i] << ' ';
		return 0;
	}
	for (int i = n - 1; ~i; --i) Add(p[i], mul(p[i + 1], dec(1, mul(ifac[i + 2], fac[i + 1]))));
	for (int i = 0; i <= n; ++i) Mul(p[i], mul(ifac[i + 1], fac[i]));
	p = trans(p, 1, n + 1);
	for (int i = 0; i <= n; ++i) {
		Mul(p[i], Inv(ksm(i + 1, m % (mod - 1))));
	}
	p = trans(p, mod - 1, n + 1);
	for (int i = 0; i <= n; ++i) cout << p[i] << ' ';
	return 0;
}