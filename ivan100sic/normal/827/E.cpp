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

int p2(int x) {
	int y = 1;
	while (y < x)
		y <<= 1;
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;
		vector<int> d(n+1, 0);
		for (char x : string("VK")) {
			char y = x ^ 'V' ^ 'K';

			int g = p2(2*n);

			vector<int> a(g, 0), b(g, 0);
			for (int i=0; i<n; i++) {
				if (s[i] == x)
					a[i] = 1;
				if (s[n-1-i] == y)
					b[i] = 1;
			}

			fft::fft(a, false);
			fft::fft(b, false);
			for (int i=0; i<g; i++) {
				a[i] = a[i] * 1ll * b[i] % fft::mod;
			}
			fft::fft(a, true);
			for (int i=0; i<n; i++) {
				d[i] += a[i+n-1];
			}
		}
		basic_string<int> sol;
		for (int i=1; i<=n; i++) {
			int z = 0;
			for (int j=i; j<n; j+=i)
				z |= d[j];
			if (z == 0)
				sol += i;
		}
		cout << sol.size() << '\n';
		for (int x : sol)
			cout << x << ' ';
		cout << '\n';
	}	
}