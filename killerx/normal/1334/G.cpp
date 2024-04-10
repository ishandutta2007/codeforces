#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int mod = 998244353, g = 3;

inline void uadd(int &x, int y) { x += y - mod; x += x >> 31 & mod; }
inline void usub(int &x, int y) { x -= y; x += x >> 31 & mod; }
inline void umul(int &x, int y) { x = static_cast <i64> (x) * y % mod; }

inline int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
inline int sub(int x, int y) { return x - y >= 0 ? x - y : x - y + mod; }
inline int mul(int x, int y) { return static_cast <i64> (x) * y % mod; }

inline int qpow(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, umul(x, x)) if (n & 1) umul(ans, x);
	return ans;
}

namespace FFT {
	const int mxn = 1 << 19;

	void fft(int a[], int n, bool flag = false) {
		static int r[mxn];
		for (int i = 1; i < n - 1; ++ i) r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
		for (int i = 1; i < n - 1; ++ i) if (i < r[i]) std::swap(a[i], a[r[i]]);
		static int w[mxn];
		for (int h = 1; h < n; h <<= 1) {
			const int temp = qpow(g, (mod - 1) / (h << 1));
			for (int i = 0; i < h; ++ i) w[h + i] = i ? mul(w[h + i - 1], temp) : 1;
			for (int i = 0; i < n; i += h << 1) {
				int *A0 = a + i, *A1 = a + i + h;
				int *W = w + h;
				for (int j = 0; j < h; ++ j) {
					const int v = mul(*A1, *W);
					*A1 = sub(*A0, v), uadd(*A0, v);
					++ A0, ++ A1, ++ W;
				}
			}
		}
		if (flag) {
			std::reverse(a + 1, a + n);
			int in = qpow(n, mod - 2);
			rep(i, n) umul(a[i], in);
		}
	}
}

inline void poly_mul(int a[], int n, int b[], int m, int c[]) {
	static int A[FFT::mxn], B[FFT::mxn];
	int sz = 1;
	for (; sz < n + m - 1; sz <<= 1);
	rep(i, sz) A[i] = i < n ? a[i] : 0;
	rep(i, sz) B[i] = i < m ? b[i] : 0;
	FFT::fft(A, sz);
	FFT::fft(B, sz);
	rep(i, sz) umul(A[i], B[i]);
	FFT::fft(A, sz, true);
	rep(i, n + m - 1) c[i] = A[i];
}

const int mxn = 2e5 + 5, sigma = 26;
int map[sigma];
int p[sigma];
int n, m;
char temp[mxn];
int s[mxn], sp[mxn], t[mxn];

int main() {
	std::mt19937 rng;
	rep(i, sigma) map[i] = rng() % mod;

	#ifdef DEBUG
	freopen("in", "r", stdin);
	#endif
	
	rep(i, sigma) scanf("%d", &p[i]), -- p[i];
	scanf("%s", temp), m = strlen(temp);
	rep(i, m) s[i] = map[temp[i] - 'a'], sp[i] = map[p[temp[i] - 'a']];
	scanf("%s", temp), n = strlen(temp);
	rep(i, n) t[i] = map[temp[i] - 'a'];

	static int sum[mxn];
	rep(i, n - m + 1) sum[i] = 0;
	static int A[mxn], B[mxn], C[mxn * 2];

/*
	rep(i, n) A[i] = mul(t[i], t[i]);
	rep(i, m) B[m - 1 - i] = 1;
	poly_mul(A, n, B, m, C);
	rep(i, n - m + 1) uadd(sum[i], C[i + m - 1]);
*/
	static int sumt[mxn];
	rep(i, n) sumt[i + 1] = add(sumt[i], mul(t[i], t[i]));
	rep(i, n - m + 1) uadd(sum[i], sub(sumt[i + m], sumt[i]));

	rep(i, n) A[i] = mul(mod - 1, t[i]);
	rep(i, m) B[m - 1 - i] = add(s[i], sp[i]);
	poly_mul(A, n, B, m, C);
	rep(i, n - m + 1) uadd(sum[i], C[i + m - 1]);

/*
	rep(i, n) A[i] = 1;
	rep(i, m) B[m - 1 - i] = mul(s[i], sp[i]);
	poly_mul(A, n, B, m, C);
	rep(i, n - m + 1) uadd(sum[i], C[i + m - 1]);
*/
	static int sums[mxn];
	rep(i, m) sums[i + 1] = add(sums[i], mul(s[i], sp[i]));
	rep(i, n - m + 1) uadd(sum[i], sums[m]);

	rep(i, n - m + 1) printf("%d", sum[i] == 0);
	printf("\n");
	return 0;
}