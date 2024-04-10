#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 20, mod = 998244353;

inline int qpow(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}

inline void uadd(int &x, int y) { x += y - mod; x += x >> 31 & mod; }

int fac[mxn], ifac[mxn];

struct INIT {
	INIT() {
		rep(i, mxn) fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
		ifac[mxn - 1] = qpow(fac[mxn - 1], mod - 2);
		for (int i = mxn - 1; i; -- i) ifac[i - 1] = 1LL * i * ifac[i] % mod;
	};
} __INIT;

inline int comb(int n, int m) {
	return 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int n, K;
int a[mxn], b[5];
int q;

int r[mxn], w[mxn];

void fft(int a[], int n, bool flag = false) {
	for (int h = 1; h < n; h <<= 1) {
		int temp = qpow(3, (mod - 1) / (h << 1));
		for (int i = 0; i < h; ++ i)
			w[h + i] = i ? 1LL * temp * w[h + i - 1] % mod : 1;
	}
	for (int i = 1; i < n - 1; ++ i) {
		r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
		if (i < r[i]) std::swap(a[i], a[r[i]]);
	}
	for (int h = 1; h < n; h <<= 1)
		for (int i = 0; i < n; i += h << 1) {
			int *A0 = a + i, *A1 = a + i + h, *W = w + h;
			for (int j = 0; j < h; ++ j) {
				int v = 1LL * *A1 * *W % mod;
				*A1 = *A0 - v >= 0 ? *A0 - v : *A0 + mod - v;
				*A0 = *A0 + v < mod ? *A0 + v : *A0 + v - mod;
				++ A0, ++ A1, ++ W;
			}
		}
	if (flag) {
		std::reverse(a + 1, a + n);
		int in = qpow(n, mod - 2);
		rep(i, n) a[i] = 1LL * a[i] * in % mod;
	}
}

struct poly : std::vector <int> {
	poly(int n, int x = 0) { assign(n, x); }
	poly(std::initializer_list <int> l) { clear(); for (int x : l) push_back(x); }

	friend inline poly operator * (const poly &a, const poly &b) {
		poly c(a.size() + b.size() - 1);
		if (1LL * a.size() * b.size() <= 32LL * c.size()) {
			rep(i, a.size()) rep(j, b.size())
				c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % mod;
		} else {
			int sz = 1;
			while (sz < (int) c.size()) sz <<= 1;
			static int A[mxn], B[mxn];
			rep(i, sz) A[i] = i < (int) a.size() ? a[i] : 0;
			rep(i, sz) B[i] = i < (int) b.size() ? b[i] : 0;
			fft(A, sz); fft(B, sz);
			rep(i, sz) A[i] = 1LL * A[i] * B[i] % mod;
			fft(A, sz, true);
			rep(i, c.size()) c[i] = A[i];
		}
		return c;
	}
};

namespace FIO {
    const int mxsz = 1 << 23;
    char ibuf[mxsz], *iend = ibuf + mxsz, *ipos = iend;
    char obuf[mxsz], *oend = obuf + mxsz, *opos = obuf;
    char get_char() {
        if (ipos == iend) iend = (ipos = ibuf) + fread(ibuf, 1, mxsz, stdin);
        return ipos == iend ? EOF : *ipos ++;
    }
    void put_char(char c) {
        if (opos == oend) fwrite(opos = obuf, 1, mxsz, stdout);
        *opos ++ = c;
    }
    void flush() {
        fwrite(obuf, 1, opos - obuf, stdout);
    }
    struct FLUSH { ~FLUSH() { flush(); } } __FLUSH;
}

using FIO::get_char;
using FIO::put_char;

inline void read(int &x) {
    x = 0; char c = get_char();
    while (c <= 32) c = get_char();
    while (c > 32) x = x * 10 + c - 48, c = get_char();
}

inline void writeln(int x) {
    static char stk[25];
    char *top = stk;
    if (!x) put_char(48);
    while (x) *top ++ = x % 10 + 48, x /= 10;
    while (top -- != stk) put_char(*top);
    put_char('\n');
}

int main() {
	read(n); read(K);
	rep(i, n) read(a[i]);
	rep(i, K) read(b[i]);
	static int ans[mxn];
	memset(ans, 0, sizeof(ans));
	rep(i, K) {
		std::map <int, int> qwq;
		rep(j, n) if (a[j] < b[i]) qwq[a[j]] += 1;
		// eprintf("%d\n", b[i]);
		int cnt1 = 0, cnt2 = 0;
		for (auto pr : qwq) {
			int c = pr.second;
			if (c == 1) cnt1 ++; else cnt2 ++;
		}
		poly p1(cnt1 + 1); // (1 + 2x) ^ cnt1
		poly p2(cnt2 * 2 + 1); // (1 + 2x + 1) ^ cnt2
		rep(i, p1.size()) p1[i] = 1LL * comb(cnt1, i) * qpow(2, i) % mod;
		rep(i, p2.size()) p2[i] = comb(cnt2 * 2, i);
		poly p = p1 * p2;
		rep(j, p.size()) if (p[j]) uadd(ans[j + 1 + b[i]], p[j]);
	}
	int q; read(q);
	while (q --) {
		int s; read(s); s >>= 1;
		writeln(ans[s]);
	}
	return 0;
}