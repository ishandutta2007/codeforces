#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

namespace fft1 {

	const int mod = 998244353;
	const int root = 15311432;
	const int root_1 = 469870224;
	const int root_pw = 1 << 23;

	template<class T>
	T eea(T a, T b, T& x, T& y) {
		if (!b) {
			x = 1;
			y = 0;
			return a;
		}
	
		T x1, y1;
		T g = eea(b, a % b, x1, y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return g;
	}

	int inverse(int n) {
		int x, y;
		eea(n, mod, x, y);
		x %= mod;
		if (x < 0)
			x += mod;
		return x;
	}

	void fft(vector<int>& a, bool invert) {
		int n = a.size();

		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
			for (; j & bit; bit >>= 1)
				j ^= bit;
			j ^= bit;

			if (i < j)
				swap(a[i], a[j]);
		}

		for (int len = 2; len <= n; len <<= 1) {
			int wlen = invert ? root_1 : root;
			for (int i = len; i < root_pw; i <<= 1)
				wlen = 1LL * wlen * wlen % mod;

			int lenh = len >> 1;

			for (int i = 0; i < n; i += len) {
				int w = 1;
				for (int j = 0; j < lenh; j++) {
					int u = a[i+j], v = (int)(1LL * a[i+j+lenh] * w % mod);
					a[i+j] = u + v < mod ? u + v : u + v - mod;
					a[i+j+lenh] = u - v >= 0 ? u - v : u - v + mod;
					w = 1LL * w * wlen % mod;
				}
			}
		}

		if (invert) {
			int n_1 = inverse(n);
			for (int& x : a)
				x = 1LL * x * n_1 % mod;
		}
	}
}

namespace fft2 {

	const int mod = 167772161;
	const int root = 243;
	const int root_1 = 114609789;
	const int root_pw = 1 << 25;

	template<class T>
	T eea(T a, T b, T& x, T& y) {
		if (!b) {
			x = 1;
			y = 0;
			return a;
		}
	
		T x1, y1;
		T g = eea(b, a % b, x1, y1);
		x = y1;
		y = x1 - (a / b) * y1;
		return g;
	}

	int inverse(int n) {
		int x, y;
		eea(n, mod, x, y);
		x %= mod;
		if (x < 0)
			x += mod;
		return x;
	}

	void fft(vector<int>& a, bool invert) {
		int n = a.size();

		for (int i = 1, j = 0; i < n; i++) {
			int bit = n >> 1;
			for (; j & bit; bit >>= 1)
				j ^= bit;
			j ^= bit;

			if (i < j)
				swap(a[i], a[j]);
		}

		for (int len = 2; len <= n; len <<= 1) {
			int wlen = invert ? root_1 : root;
			for (int i = len; i < root_pw; i <<= 1)
				wlen = 1LL * wlen * wlen % mod;

			int lenh = len >> 1;

			for (int i = 0; i < n; i += len) {
				int w = 1;
				for (int j = 0; j < lenh; j++) {
					int u = a[i+j], v = (int)(1LL * a[i+j+lenh] * w % mod);
					a[i+j] = u + v < mod ? u + v : u + v - mod;
					a[i+j+lenh] = u - v >= 0 ? u - v : u - v + mod;
					w = 1LL * w * wlen % mod;
				}
			}
		}

		if (invert) {
			int n_1 = inverse(n);
			for (int& x : a)
				x = 1LL * x * n_1 % mod;
		}
	}
}

template<class T>
T eea(T a, T b, T& x, T& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T g = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

const ll bigmod_m = fft1::mod * 1ll * fft2::mod;

static inline ll bigmod(int x, ll y) {
	ll z = 0;
	for (int i=30; i>=0; i--) {
		z += z;
		if (z >= bigmod_m)
			z -= bigmod_m;
		if (x & (1 << i)) {
			z += y;
			if (z >= bigmod_m)
				z -= bigmod_m;
		}
	}
	return z;
}

// mod1 * mod2 < 2**61
template<ll mod1, ll mod2>
struct crt {

	ll i1, i2, mm;

	crt() {
		eea(mod1, mod2, i1, i2);
		mm = mod1 * mod2;
		i1 = (i1 % mm + mm) % mm;
		i2 = (i2 % mm + mm) % mm;
	}

	ll operator() (ll x, ll y) const {
		x = bigmod(x, 120110207009027498ll);
		y = bigmod(y, 47367405299829336ll);
		if (x + y >= mm)
			return x + y - mm;
		else
			return x + y;
	}
};

int n, m, k;
int c[200005];
int d[200005];
basic_string<pair<int, int>> e;

int p2(int x) {
	int y=1;
	while (y < x)
		y <<= 1;
	return y;
}

vector<int> mnozi(int l, int r) {
	if (l == r) {
		return vector<int> (c[l]+1, 1);
	}
	int m = (l + r) >> 1;
	auto u1 = mnozi(l, m);
	auto v1 = mnozi(m+1, r);
	auto u2 = u1;
	auto v2 = v1;

	int tgt = u1.size() + v1.size() - 1;
	int g = p2(tgt);

	u1.resize(g);
	v1.resize(g);
	u2.resize(g);
	v2.resize(g);
	fft1::fft(u1, false);
	fft2::fft(u2, false);
	fft1::fft(v1, false);
	fft2::fft(v2, false);
	for (int i=0; i<g; i++) {
		u1[i] = u1[i] * 1ll * v1[i] % fft1::mod;
		u2[i] = u2[i] * 1ll * v2[i] % fft2::mod;
	}
	fft1::fft(u1, true);
	fft2::fft(u2, true);
	u1.resize(tgt);
	u2.resize(tgt);

	crt<fft1::mod, fft2::mod> c;
	
	for (int i=0; i<tgt; i++) {
		u1[i] = c(u1[i], u2[i]) % 1009;
	}

	return u1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	vector<int> p = mnozi(1, m);

	cout << p[k] << '\n';
}