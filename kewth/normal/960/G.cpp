#if 0
date

 n 
 a  n 


 n - 1  a - 1 + b - 1 
 a - 1 + b - 1  a - 1  n  b - 1  n 


#endif
#include <cstdio>
#include <algorithm>
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;

struct {
	inline operator int () { int x; return scanf("%d", &x), x; }
	inline operator ll () { ll x; return scanf("%lld", &x), x; }
	template<class T> inline void operator () (T &x) { x = *this; }
	template<class T, class ...A> inline void operator () (T &x, A &...a)
	{ x = *this; this -> operator ()(a...); }
} read;

const int maxn = 1 << 18, mod = 998244353;
typedef ll poly[maxn];
typedef ll *pit;
ll G[maxn + 1];
int ra[maxn];

inline ll power(ll x, int k) {
	if(k < 0) k += mod - 1;
	ll res = 1;
	while(k) {
		if(k & 1) (res *= x) %= mod;
		(x *= x) %= mod;
		k >>= 1;
	}
	return res;
}

inline void __a(ll &x) { if(x >= mod) x -= mod; }
inline void __d(ll &x) { if(x < 0) x += mod; }

inline void DFT(pit a, int n) {
	int nk = __builtin_ctz(maxn) - __builtin_ctz(unsigned(n));
	for(int i = 0; i < n; i ++)
		if(i < (ra[i] >> nk))
			std::swap(a[i], a[ra[i] >> nk]);

	for(int m = 1; m < n; m <<= 1)
		for(int i = 0; i < n; i += m << 1)
			for(int k = i; k < i + m; k ++) {
				ll a0 = a[k], a1 = a[k + m] * G[m + k - i] % mod;
				__a(a[k] = a0 + a1);
				__d(a[k + m] = a0 - a1);
			}
}

inline void IDFT(pit a, int n) {
	std::reverse(a + 1, a + n);
	DFT(a, n);
	int invn = mod - (mod - 1) / n;
	for(int i = 0; i < n; i ++)
		(a[i] *= invn) %= mod;
}

ll fac[maxn], ifac[maxn];
void init() {
	ll g = power(3, (mod - 1) / maxn);

	G[maxn >> 1] = 1;
	for(int i = (maxn >> 1) + 1; i <= maxn; i ++)
		G[i] = G[i - 1] * g % mod;
	for(int i = (maxn >> 1) - 1; i; i --)
		G[i] = G[i << 1];

	fac[0] = 1;
	for(int i = 1; i < maxn; i ++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[maxn - 1] = power(fac[maxn - 1], -1);
	for(int i = maxn - 1; i; i --)
		ifac[i - 1] = ifac[i] * i % mod;

	for(int i = 1; i < maxn; i ++)
		ra[i] = ra[i >> 1] >> 1 | (maxn >> 1) * (i & 1);
}

poly s, a, b;
void solve(int n) {
	if(n == 1) return s[1] = 1, void();

	if(n & 1) {
		solve(n - 1);
		for(int i = n; i; i --)
			s[i] = (s[i] * (n - 1) + s[i - 1]) % mod;
		return;
	}

	solve(n >> 1);
	int len = 1, m = n >> 1;
	while(len < n + 1) len <<= 1;

	std::copy(s, s + m + 1, b);
	std::fill(b + m + 1, b + len, 0);
	for(int i = 0; i <= m; i ++)
		(b[i] *= fac[i]) %= mod;
	std::reverse(b, b + m + 1);

	std::fill(a + m + 1, a + len, 0);
	ll po = 1;
	for(int i = 0; i <= m; i ++) {
		a[i] = po * ifac[i] % mod;
		(po *= m) %= mod;
	}

	DFT(b, len);
	DFT(a, len);
	for(int i = 0; i < len; i ++)
		(b[i] *= a[i]) %= mod;
	IDFT(b, len);

	std::fill(b + m + 1, b + len, 0);
	std::reverse(b, b + m + 1);
	for(int i = 0; i <= m; i ++)
		(b[i] *= ifac[i]) %= mod;

	DFT(b, len);
	DFT(s, len);
	for(int i = 0; i < len; i ++)
		(s[i] *= b[i]) %= mod;
	IDFT(s, len);
}

inline ll C(int n, int m) { return fac[n] * ifac[m] % mod * ifac[n - m] % mod; }

int main() {
	init();
	int n = read, A = read, B = read;

	if(!A or !B or A + B - 1 > n) return puts("0"), 0;
	if(n == 1) return puts("1"), 0;

	solve(n - 1);

	printf("%lld\n", C(A + B - 2, A - 1) * s[A + B - 2] % mod);
}