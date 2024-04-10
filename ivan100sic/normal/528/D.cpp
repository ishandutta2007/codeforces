#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

namespace fft {

	const int mod = 167772161;
	const int root = 243;
	const int root_1 = 114609789;
	const int root_pw = 1 << 25;

	/*
	Alternative values:

	const int mod = 23068673;
	const int root = 177147;
	const int root_1 = 17187657;
	const int root_pw = 1 << 21;

	or

	const int mod = 998244353;
	const int root = 15311432;
	const int root_1 = 469870224;
	const int root_pw = 1 << 23;
	*/

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

int p2(int n) {
	int z = 1;
	while (z < n)
		z <<= 1;
	return z;
}

int n, m, k;
string a, b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k >> a >> b;
	c = b;
	int g = max(p2(n), p2(m));
	reverse(c.begin(), c.end());
	vector<int> mis(n-m+1, 0);
	for (char x : string("ACGT")) {
		vector<int> u(n, 0), v(m, 0);
		for (int i=0; i<n; i++) {
			if (a[i] == x) {
				u[max(i-k, 0)] += 1;
				if (i+k+1 < n)
					u[i+k+1] -= 1;
			}
		}
		for (int i=0; i<n; i++) {
			if (i)
				u[i] += u[i-1];
		}
		for (int i=0; i<n; i++) {
			u[i] = !!u[i];
		}
		for (int j=0; j<m; j++) {
			if (c[j] == x) {
				v[j] = 1;
			}
		}
		u.resize(g, 0);
		v.resize(g, 0);
		fft::fft(u, false);
		fft::fft(v, false);
		for (int i=0; i<g; i++)
			u[i] = u[i] * 1ll * v[i] % fft::mod;
		fft::fft(u, true);
		for (int i=0; i<n-m+1; i++)
			mis[i] += u[i+m-1];
	}
	int z = 0;
	for (int x : mis) {
		if (x == m)
			z++;
	}
	cout << z << '\n';
}