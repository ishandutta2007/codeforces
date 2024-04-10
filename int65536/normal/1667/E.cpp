#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define MOD (998244353)

int inv(int v) {
	return v <= 1 ? v : MOD - (long long)inv(MOD % v) * (MOD / v) % MOD;
}

struct mint {
	int v;
	mint(long long v = 0) : v((v % MOD + MOD) % MOD) {}

	mint& operator+=(mint a) {
		v = (v + a.v) % MOD;
		return *this;
	}

	mint& operator-=(mint a) {
		v = (v - a.v + MOD) % MOD;
		return *this;
	}

	mint& operator*=(mint a) {
		v = ((long long)v * a.v) % MOD;
		return *this;
	}

	mint& operator/=(mint a) {
		v = ((long long)v * inv(a.v)) % MOD;
		return *this;
	}

	friend mint operator+(mint a, mint b) {
		return mint(a.v + b.v);
	}

	friend mint operator-(mint a, mint b) {
		return mint(a.v - b.v);
	}

	friend mint operator*(mint a, mint b) {
		return mint((long long)a.v * b.v);
	}

	friend mint operator/(mint a, mint b) {
		return mint((long long)a.v * inv(b.v));
	}
};

mint pow(mint base, long long exponent) {
	if (exponent <= 0) {
		return 1;
	}
	mint ret = 1;
	while (exponent) {
		if (exponent & 1) {
			ret *= base;
		}
		exponent >>= 1;
		base = base * base;
	}
	return ret;
}

const int maxn = 1e6;

mint permutation[maxn];
mint permutation_inv[maxn];

void init_perm()
{
	permutation[0] = 1;
	permutation_inv[0] = 1;
	for (int n = 1; n < maxn; ++n) {
		permutation[n] = permutation[n - 1] * n;
		permutation_inv[n] = permutation_inv[n - 1] / n;
	}
}

namespace DFT {

#define ll unsigned long long
#define rep(i,x,y)  for(register int i=x;i<y;++i)
#define For(i,x,y)  for(register int i=x;i<=y;++i) 
#define FOr(i,x,y)  for(register int i=x;i>=y;--i) 
#define pi acos(-1)
#define mk make_pair<ll,ll>
#define pa pair<ll,ll>
#define lf else if
#define max(x,y)    ((x)<(y)?(y):(x))
#define min(x,y)    ((x)<(y)?(x):(y))
#define sqr(x)		(x)*(x)
#define abs(x)		(x)>0?(x):-(x)
#define Mul(x,y)    x=x*(y)%mod
#define Add(x,y)    x=(x+(y))%mod
#define Max(x,y)	x=x<(y)?(y):x
#define Min(x,y)	x=x>(y)?(y):x
#define E(x) 		return writeln(x),0
#define p(x)		printf("~%d~\n",x)
#define pp(x,y)		printf("~~%d %d~~\n",x,y)
#define ppp(x,y,z)	printf("~~~%d %d %d~~~\n",x,y,z)
#define f_in(x)		freopen(x".in","r",stdin)
#define f_out(x) 	freopen(x".out","w",stdout)
#define open(x)		f_in(x),f_out(x)
#define fi first
#define se second
#define rep(i,x,y)  for(register int i=x;i<y;++i)

	const int N = (1 << 20) | 111, G = 3, mod = 998244353;
	ll a[N], b[N], wn[N], WN[N], rev[N];
	int n, m, c[N];

	struct fft {
		ll n, L;
		ll ppow(ll x, ll k) { ll ans = 1; for (; k; k >>= 1, Mul(x, x))if (k & 1)Mul(ans, x); return ans; }
		void init(ll len) {
			L = 0; n = 1; while (n <= len)n <<= 1, L++;
			ll w = ppow(G, (mod - 1) / n);
			rep(i, 0, n)	wn[i] = i ? wn[i - 1] * w % mod : 1, rev[i] = rev[i >> 1] >> 1 | ((i & 1) << L - 1);
		}
		void dft(ll* a) {
			rep(i, 0, n)if (rev[i] < i)swap(a[i], a[rev[i]]); ll tmp = 0;
			for (register int d = 1, len = L - 1; d < n; d <<= 1, --len) {
				For(i, 0, d)	WN[i] = wn[i << len]; ll x, y;	int t;
				if (d <= 4)
					for (register int i = 0; i < n; i += d << 1) {
						for (register int k = 0, x = i, y = i + d; k < d; ++k, ++x) {
							t = WN[k] * a[x + d] % mod;
							a[x + d] = a[x] - t + mod, a[x] = a[x] + t;
						}
					}
				else {
					for (register int i = 0; i < n; i += d << 1) {
						for (register int k = 0, x = i; k < d;) {
							t = WN[k] * a[x + d] % mod;
							a[x + d] = a[x] - t + mod, a[x] = a[x] + t;
							t = WN[k + 1] * a[x + d + 1] % mod;
							a[x + d + 1] = a[x + 1] - t + mod, a[x + 1] = a[x + 1] + t;
							t = WN[k + 2] * a[x + d + 2] % mod;
							a[x + d + 2] = a[x + 2] - t + mod, a[x + 2] = a[x + 2] + t;
							t = WN[k + 3] * a[x + d + 3] % mod;
							a[x + d + 3] = a[x + 3] - t + mod, a[x + 3] = a[x + 3] + t;
							k += 4; x += 4;
						}
					}
				}
			}rep(i, 0, n)a[i] = a[i] % mod;
			reverse(a + 1, a + n); ll inv = ppow(n, mod - 2);
			rep(i, 0, n)Mul(a[i], inv);
		}
		void Dft(ll* a, ll* b) {
			rep(i, 0, n)if (rev[i] < i)swap(a[i], a[rev[i]]), swap(b[i], b[rev[i]]); ll tmp = 0;
			for (register int d = 1, len = L - 1; d < n; d <<= 1, --len) {
				For(i, 0, d)	WN[i] = wn[i << len]; ll x, y;	int t;
				if (d <= 2)
					for (register int i = 0; i < n; i += d << 1) {
						for (register int k = 0, x = i, y = i + d; k < d; ++k, ++x) {
							t = WN[k] * a[x + d] % mod;
							a[x + d] = a[x] - t + mod, a[x] = a[x] + t;
							t = WN[k] * b[x + d] % mod;
							b[x + d] = b[x] - t + mod, b[x] = b[x] + t;
						}
					}
				else {
					for (register int i = 0; i < n; i += d << 1) {
						for (register int k = 0, x = i; k < d;) {
							t = WN[k] * a[x + d] % mod;
							a[x + d] = a[x] - t + mod, a[x] = a[x] + t;
							t = WN[k] * b[x + d] % mod;
							b[x + d] = b[x] - t + mod, b[x] = b[x] + t;
							t = WN[k + 1] * a[x + d + 1] % mod;
							a[x + d + 1] = a[x + 1] - t + mod, a[x + 1] = a[x + 1] + t;
							t = WN[k + 1] * b[x + d + 1] % mod;
							b[x + d + 1] = b[x + 1] - t + mod, b[x + 1] = b[x + 1] + t;
							t = WN[k + 2] * a[x + d + 2] % mod;
							a[x + d + 2] = a[x + 2] - t + mod, a[x + 2] = a[x + 2] + t;
							t = WN[k + 2] * b[x + d + 2] % mod;
							b[x + d + 2] = b[x + 2] - t + mod, b[x + 2] = b[x + 2] + t;
							t = WN[k + 3] * a[x + d + 3] % mod;
							a[x + d + 3] = a[x + 3] - t + mod, a[x + 3] = a[x + 3] + t;
							t = WN[k + 3] * b[x + d + 3] % mod;
							b[x + d + 3] = b[x + 3] - t + mod, b[x + 3] = b[x + 3] + t;
							k += 4, x += 4;
						}
					}
				}
			}rep(i, 0, n)a[i] = a[i] % mod, b[i] = b[i] % mod;
		}
	}lbc;

	vector<ll> convolution(const vector<ll>& x, const vector<ll>& y) {
		n = x.size();
		m = y.size();
		lbc.init(n + m);
		for (int i = 0; i < lbc.n; i++) a[i] = 0;
		for (int i = 0; i < lbc.n; i++) b[i] = 0;
		for (int i = 0; i < n; i++) a[i] = x[i];
		for (int i = 0; i < m; i++) b[i] = y[i];
		lbc.Dft(a, b);
		for (int i = 0; i < lbc.n; i++) Mul(a[i], b[i]);
		lbc.dft(a);
		vector<ll> ret(n + m - 1);
		for (int i = 0; i < ret.size(); i++) ret[i] = (a[i] + mod) % mod;
		return ret;
	}

}

vector<mint> convolution(const vector<mint>& a, const vector<mint>& b) {
	vector<ll> x;
	vector<ll> y;
	for (int i = 0; i < a.size(); ++i) {
		x.push_back(a[i].v);
	}
	for (int i = 0; i < b.size(); ++i) {
		y.push_back(b[i].v);
	}
	vector<ll> z = DFT::convolution(x, y);
	vector<mint> c(z.size());
	for (int i = 0; i < z.size(); ++i) {
		c[i] = z[i];
	}
	return c;
}

vector<mint> solve(int n) {
	vector<mint> ret(n);
	
	vector<mint> c1;
	{
		vector<mint> a((n - 1) / 2);
		for (int k = 1; k <= (n - 1) / 2; ++k) {
			a[k - 1] = permutation[n - k - 1];
		}
		reverse(a.begin(), a.end());
		vector<mint> b(n + 1);
		for (int k = 0; k <= n; ++k) {
			b[k] = permutation_inv[n - k];
		}
		c1 = convolution(a, b);	
	}
	vector<mint> c2;
	{
		vector<mint> a;
		for (int k = (n + 1) / 2; k < n; ++k) {
			a.push_back(permutation[n - k - 1] / mint(k));
		}
		vector<mint> b(n + 1);
		for (int k = 0; k <= n; ++k) {
			b[k] = permutation_inv[n - k];
		}
		reverse(b.begin(), b.end());
		c2 = convolution(a, b);
	}

	for (int i = 1; i <= (n + 1) / 2; ++i) {
		mint r = permutation[n - 1];
		if (i > 1) {
			r -= c1[(n - 1) / 2 + i - 1] * permutation[n - i] * mint(i - 1);
		}
		if (i < (n + 1) / 2) {
			r -= c2[(n + 1) / 2 - 1 - i] * permutation[n - i];
		}
		ret[i - 1] = r;
	}
	return ret;
}

int main()
{
#ifdef _MSC_VER
	freopen("e.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	init_perm();
	int n;
	cin >> n;
	vector<mint> ret = solve(n);
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", ret[i].v);
	}
	printf("\n");
	return 0;
}