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

vector<int> poly_add(vector<int> a, vector<int> b) {
	int n = max(a.size(), b.size());
	a.resize(n);
	b.resize(n);
	for (int i=0; i<n; i++) {
		a[i] += b[i];
		if (a[i] >= fft::mod)
			a[i] -= fft::mod;
	}
	return a;
}

vector<int> poly_sub(vector<int> a, vector<int> b) {
	int n = max(a.size(), b.size());
	a.resize(n);
	b.resize(n);
	for (int i=0; i<n; i++) {
		a[i] -= b[i];
		if (a[i] < 0)
			a[i] += fft::mod;
	}
	return a;
}

int c[3000000], n;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

vector<int> solve(int l, int r) {
	if (r-l == 1)
		return vector<int>(c[l]+1, 1);

	int m = (l+r) >> 1;
	auto u = solve(l, m);
	auto v = solve(m, r);

	return poly_mul(u, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		c[x]++;
	}

	sort(c, c+3000000, greater<int>());
	n = 0;
	while (c[n])
		n++;
	shuffle(c, c+n, eng);
	auto r = solve(0, n);
	cout << r[accumulate(c, c+n, 0) / 2] << '\n';
}