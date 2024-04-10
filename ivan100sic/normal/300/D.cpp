#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

namespace fft {

	const int mod = 7340033;
	const int root = 5;
	const int root_1 = 4404020;
	const int root_pw = 1 << 20;

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

int order(int n) {
	int z = 0;
	while (n % 2 == 1 && n > 1) {
		n >>= 1;
		z++;
	}
	return z;
}

vector<int> p[32];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	p[0] = p[1] = vector<int>(4096, 0);
	p[0][0] = 1;
	p[1][0] = p[1][1] = 1;

	for (int i=2; i<32; i++) {
		vector<int> q = p[i-1];
		fft::fft(q, false);
		for (int i=0; i<4096; i++) {
			q[i] = q[i] * 1ll * q[i] % fft::mod;
			q[i] = q[i] * 1ll * q[i] % fft::mod;
		}
		fft::fft(q, true);
		fill(q.begin() + 1005, q.end(), 0);
		rotate(q.begin(), q.begin() + 1004, q.begin() + 1005);
		q[0] = 1;
		swap(p[i], q);
	}

	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		cout << p[order(n)][k] << '\n';
	}
}