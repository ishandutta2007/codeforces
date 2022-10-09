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

int p2(int x) {
	int y = 1;
	while (y < x)
		y <<= 1;
	return y;
}

void bi_sredi(vector<int>& a) {
	for (int i=0; i<(int)a.size()-1; i++) {
		if (a[i] >= 10) {
			a[i+1] += a[i] / 10;
			a[i] %= 10;
		}
	}
	while (a.back() >= 10) {
		int z = a.back() / 10;
		a.back() %= 10;
		a.push_back(z);
	}
	while (a.size() && a.back() == 0)
		a.pop_back();
}

void bi_sq(vector<int>& a) {
	int t = 2 * a.size() - 1;
	int g = p2(t);
	a.resize(g);
	fft::fft(a, false);
	for (int i=0; i<g; i++)
		a[i] = a[i] * 1ll * a[i] % fft::mod;
	fft::fft(a, true);
	a.resize(t);
	bi_sredi(a);
}

void bi_mul3(vector<int>& a) {
	for (int i=0; i<(int)a.size(); i++)
		a[i] *= 3;
	bi_sredi(a);
}

void bi_div2(vector<int>& a) {
	a[0]++;
	for (int i=(int)a.size()-1; i>=1; i--) {
		if (a[i] & 1) {
			a[i-1] += 10;
		}
		a[i] >>= 1;
	}
	a[0] >>= 1;
	bi_sredi(a);
}

vector<int> pw3(int n) {
	vector<int> z = {1};
	for (int i=28; i>=0; i--) {
		bi_sq(z);
		if (n & (1 << i)) {
			bi_mul3(z);
		}
	}
	return z;
}

bool geq(const vector<int>& a, const vector<int>& b) {
	// sredjeni!!
	if (a.size() != b.size())
		return a.size() > b.size();

	for (int i=a.size()-1; i>=0; i--) {
		if (a[i] != b[i])
			return a[i] > b[i];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	if (s.size() == 1 && s <= "5") {
		cout << s << '\n';
		return 0;
	}
	vector<int> n(s.size());
	for (int i=0; i<(int)s.size(); i++) {
		n[s.size() - 1 - i] = s[i] - '0';
	}

	auto n2 = n;
	bi_div2(n2);
	auto n3 = n2;
	bi_div2(n3);

	int sol = 1123123123;
	int y = floor((log(n3.back()) + (n3.size() - 1) * log(10)) / log(3) * 0.999999);
	auto v = pw3(y);

	while (!geq(v, n3)) {
		y++;
		bi_mul3(v);
	}
	sol = min(sol, 3*y + 4);

	while (!geq(v, n2)) {
		y++;
		bi_mul3(v);
	}
	sol = min(sol, 3*y + 2);

	while (!geq(v, n)) {
		y++;
		bi_mul3(v);
	}
	sol = min(sol, 3*y + 0);

	cout << sol << '\n';
}