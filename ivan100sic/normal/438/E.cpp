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

int n, m;

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

vector<int> poly_inverse(vector<int> a, int N = FIELD) {
	a.resize(N);
	vector<int> rn = {fft::inverse(a[0])};
	for (int n=1; n<N; n*=2) {
		auto an = a;
		an.resize(2*n);
		auto tmp = poly_mul(an, poly_mul(rn, rn));
		rn = poly_add(rn, poly_sub(rn, tmp));
		rn.resize(2*n);
	}
	return rn;
}

vector<int> poly_sqrt(vector<int> a, int N = FIELD) {
	a.resize(N);
	vector<int> rn = {1}; // pretpostavljamo da je a[0] = 1
	for (int n=1; n<N; n*=2) {
		auto t = poly_add(rn, rn);
		t = poly_inverse(t, n);
		auto b = poly_sub(a, poly_mul(rn, rn));
		b.erase(b.begin(), b.begin() + n);
		b.resize(n);
		t = poly_mul(t, b);
		rn.resize(2*n);
		for (int i=0; i<n; i++)
			rn[i+n] = t[i];
	}
	return rn;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vector<int> c(FIELD, 0);
	cin >> n >> m;
	while (n--) {
		int x;
		cin >> x;
		c[x] = 1;
	}

	auto c2 = poly_add(c, c);
	auto c4 = poly_add(c2, c2);

	auto t = poly_sub({1}, c4);
	t = poly_add({1}, poly_sqrt(t));
	t = poly_inverse(t, FIELD);
	t = poly_add(t, t);

	for (int i=1; i<=m; i++)
		cout << t[i] << '\n';
}