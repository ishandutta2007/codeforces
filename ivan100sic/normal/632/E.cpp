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

int pw(int x, int y, int p) {
	if (y == 0)
		return 1;
	int z = pw(x, y >> 1, p);
	z = z * 1ll * z % p;
	if (y & 1)
		z = z * 1ll * x % p;
	return z;
}

int n, k;
vector<int> b(1 << 20, 0);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	while (n--) {
		int x;
		cin >> x;
		b[x]++;
	}
	fft::fft(b, false);
	for (int i=0; i<(1<<20); i++)
		b[i] = pw(b[i], k, fft::mod);
	fft::fft(b, true);

	for (int i=0; i<(1<<20); i++)
		if (b[i])
			cout << i << ' ';
	cout << '\n';
}