#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

namespace fft {

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

			for (int i = 0; i < n; i += len) {
				int w = 1;
				for (int j = 0; j < len / 2; j++) {
					int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
					a[i+j] = u + v < mod ? u + v : u + v - mod;
					a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
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

int pm(int x) {
	if (x < fft::mod - x) {
		return x;
	} else {
		return x - fft::mod;
	}
}

const int FIELD = 131072;

vector<int> poly_mul(vector<int> a, vector<int> b) {
	int n = a.size() + b.size() - 1;
	int m = 1;
	while (m < n)
		m *= 2;
	a.resize(m);
	b.resize(m);

	if (a == b) {
		fft::fft(a, false);
		b = a;
	} else {
		fft::fft(a, false);
		fft::fft(b, false);
	}
	for (int i=0; i<m; i++)
		a[i] = a[i] * 1ll * b[i] % fft::mod;
	fft::fft(a, true);
	a.resize(n);
	return a;
}

int n;
ll m;

int f[2*FIELD], finv[2*FIELD];

int pw(int x, ll y) {
	if (y == 0)
		return 1;
	int z = pw(x, y >> 1);
	z = z * 1ll * z % fft::mod;
	if (y & 1)
		z = z * 1ll * x % fft::mod;
	return z;
}

vector<int> binom_transform(vector<int> a, bool inv) {
	// pomnozi sa faktorijelom
	for (int i=0; i<FIELD; i++)
		a[i] = a[i] * 1ll * f[i] % fft::mod;
	// pomnozi sa nizom reciprocnih faktorijela
	vector<int> b(finv, finv+FIELD);
	if (inv)
		for (int i=0; i<FIELD; i++)
			if (i % 2)
				b[i] = (fft::mod - b[i]) % fft::mod;
	reverse(b.begin(), b.end());
	b = poly_mul(a, b);
	// pomnozi sa finv i vrati
	vector<int> c(FIELD);
	for (int i=0; i<FIELD; i++)
		c[i] = b[FIELD-1+i] * 1ll * finv[i] % fft::mod;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<2*FIELD; i++) {
		f[i] = f[i-1] * 1ll * i % fft::mod;
		finv[i] = fft::inverse(f[i]);
	}

	cin >> n >> m;
	vector<int> a(FIELD, 0);
	for (int i=0; i<=n; i++)
		cin >> a[i];

	a = binom_transform(a, false);
	for (int i=0; i<FIELD; i++)
		a[i] = a[i] * 1ll * pw(fft::inverse(i+1), m) % fft::mod;
	a = binom_transform(a, true);
	for (int i=0; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}