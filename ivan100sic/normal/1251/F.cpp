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

int f[300005], finv[300005];

int bk(int n, int k) {
	if (n < 0 || k < 0 || n-k < 0)
		return 0;
	return f[n] * 1ll * finv[n-k] % fft::mod * finv[k] % fft::mod;
}

int n, k;
int ac[300005];
int b[5];
int q[300005], qc;
// proveri velicinu field!

int ans[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<300005; i++) {
		f[i] = f[i-1] * 1ll * i % fft::mod;
		finv[i] = fft::inverse(f[i]);
	}

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		ac[x]++;
	}
	for (int i=0; i<k; i++)
		cin >> b[i];
	cin >> qc;
	for (int i=0; i<qc; i++)
		cin >> q[i];

	for (int i=0; i<k; i++) {
		int s = 0, d = 0;
		for (int j=1; j<b[i]; j++) {
			if (ac[j] == 1)
				s++;
			else if (ac[j] >= 2)
				d++;
		}
		vector<int> ss(s+1), dd(2*d+1);
		for (int i=0, j=1; i<=s; i++, j=j*2ll%fft::mod)
			ss[i] = bk(s, i) * 1ll * j % fft::mod;
		for (int i=0; i<=2*d; i++)
			dd[i] = bk(2*d, i);

		auto sd = poly_mul(ss, dd);

		for (int j=0; j<qc; j++) {
			int idx = q[j]/2 - b[i] - 1;
			if (idx < 0 || idx >= (int)sd.size())
				continue;
			ans[j] = (ans[j] + sd[idx]) % fft::mod;
		}
	}

	for (int j=0; j<qc; j++)
		cout << ans[j] << '\n';
}