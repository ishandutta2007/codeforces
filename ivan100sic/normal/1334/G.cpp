// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T>
struct poly_real {
	typedef complex<T> C;

	static int bitrev(int x, int n) {
		int y = 0;
		while (n--)
			y = (y << 1) | (x & 1), x >>= 1;
		return y;
	}

	static int true_size(int n) {
		if (n == 1) return 1;
		return 1 << (32 - __builtin_clz(n - 1));
	}

	static C nth_root(int n) {
		static constexpr T pi = acos(T(-1));
		return exp(C(0, 2*pi/n));
	}

	static void fft(vector<C>& a, bool inv) {
		int n = a.size(), l = 31 - __builtin_clz(n);
		for (int i=0; i<n; i++) {
			int j = bitrev(i, l);
			if (j < i)
				swap(a[i], a[j]);
		}

		for (int h=1; h<n; h<<=1) {
			C w0 = nth_root(2*h);
			w0 = inv ? conj(w0) : w0;
			for (int i=0; i<n; i+=2*h) {
				C w = 1;
				for (int j=i; j<i+h; j++) {
					C u = a[j], v = a[j+h] * w;
					a[j] = u + v;
					a[j+h] = u - v;
					w *= w0;
				}
			}
		}

		if (inv) {
			C n1 = C(1) / C(n);
			for (C& x : a)
				x *= n1;
		}
	}

	vector<T> a;

	poly_real(int n = 0) : a(n) {}
	poly_real(T x) : a(1, x) {}
	poly_real(const vector<T>& a) : a(a) {}

	auto begin() const { return a.cbegin(); }
	auto begin() { return a.begin(); }
	auto size() const { return a.size(); }
	auto end() const { return a.cend(); }
	auto end() { return a.end(); }

	T& operator[] (size_t i) { return a[i]; }
	const T& operator[] (size_t i) const { return a[i]; }

	void trim() {
		while (a.size() && abs(a.back()) < 1e-12)
			a.pop_back();
	}

	poly_real& operator+= (const poly_real& b) {
		a.resize(max(a.size(), b.size()));
		for (int i=0; i<(int)b.size(); i++)
			a[i] += b[i];
		return *this;
	}

	poly_real& operator-= (const poly_real& b) {
		a.resize(max(a.size(), b.size()));
		for (int i=0; i<(int)b.size(); i++)
			a[i] -= b[i];
		return *this;
	}

	poly_real operator+ (const poly_real& b) const {
		auto t = *this; return t += b;
	}

	poly_real operator- (const poly_real& b) const {
		auto t = *this; return t -= b;
	}

	poly_real fft_multiply (const poly_real& b) const {
		int u = a.size() + b.size() - 1, n = true_size(u);
		vector<C> e(n), f(n);
		for (int i=0; i<(int)a.size(); i++)
			e[i] = a[i];
		for (int i=0; i<(int)b.size(); i++)
			f[i] = b[i];
		fft(e, false);
		fft(f, false);
		for (int i=0; i<n; i++)
			e[i] *= f[i];
		fft(e, true);
		poly_real c(u);
		for (int i=0; i<u; i++)
			c[i] = e[i].real();
		c.trim();
		return c;
	}

	poly_real brute_multiply (const poly_real& b) const {
		int u = a.size() + b.size() - 1;
		poly_real c(u);
		for (int i=0; i<(int)a.size(); i++)
			for (int j=0; j<(int)b.size(); j++)
				c[i+j] += a[i] * b[j];
		c.trim();
		return c;
	}

	poly_real operator* (const poly_real& b) const {
		if (!size() || !b.size())
			return {};
		int u = a.size() + b.size() - 1, n = true_size(u);
		if (12ll * (31 - __builtin_clz(n)) * n < (ll)a.size() * (ll)b.size())
			return fft_multiply(b);
		else
			return brute_multiply(b);
	}

	poly_real& operator*= (const poly_real& b) {
		return *this = *this * b;
	}

	// @n - power of two
	poly_real poly_inv(int n) const {
		poly_real a = *this;
		a.a.resize(n);
		poly_real rn(T(1) / a[0]);
		for (int l=1; l<n; l<<=1) {
			poly_real an(2*l);
			for (int i=0; i<2*l; i++)
				an[i] = a[i];
			auto tmp = rn * rn * an;
			(rn += rn) -= tmp;
			rn.a.resize(2*l);
		}
		return rn;
	}

	// @n - power of two
	poly_real poly_sqrt(int n) const {
		if (size() == 0 || this->a[0] < 0)
			return {};
		poly_real a = *this;
		T scale = T(1) / a[0];
		a.a.resize(n);
		for (int i=0; i<n; i++)
			a[i] *= scale;
		poly_real rn(T(1));
		for (int l=1; l<n; l<<=1) {
			auto t = rn + rn;
			t = t.poly_inv(l);
			auto b = a - rn * rn;
			b.a.resize(n);
			b.a.erase(b.a.begin(), b.a.begin() + l);
			b.a.resize(l);
			t *= b;
			rn.a.resize(2*l);
			for (int i=0; i<l; i++)
				rn[i+l] = t[i];
		}
		scale = T(1) / sqrt(scale);
		for (T& x : rn)
			x *= scale;
		return rn;
	}
};

template<class T>
struct poly_complex {
	typedef complex<T> C;

	static int bitrev(int x, int n) {
		int y = 0;
		while (n--)
			y = (y << 1) | (x & 1), x >>= 1;
		return y;
	}

	static int true_size(int n) {
		if (n == 1) return 1;
		return 1 << (32 - __builtin_clz(n - 1));
	}

	static void fft(vector<C>& a, bool inv) {
		int n = a.size(), l = 31 - __builtin_clz(n);
		for (int i=0; i<n; i++) {
			int j = bitrev(i, l);
			if (j < i)
				swap(a[i], a[j]);
		}

		static int ords = 0;
		static vector<vector<C>> wv;
		static constexpr T pi = acos(T(-1));

		while (l > ords) {
			int m = 2 << ords;
			vector<C> v(m);
			for (int i=0; i<m; i++)
				v[i] = exp(C(0, 2*pi*i / m));
			wv.emplace_back(move(v));
			ords++;
		}

		for (int h=1, e=0; h<n; h<<=1, e++) {
			for (int i=0; i<n; i+=2*h) {
				for (int j=i; j<i+h; j++) {
					C w = wv[e][j-i];
					w = inv ? conj(w) : w;
					C u = a[j], v = a[j+h] * w;
					a[j] = u + v;
					a[j+h] = u - v;
				}
			}
		}

		if (inv) {
			C n1 = C(1) / C(n);
			for (C& x : a)
				x *= n1;
		}
	}

	vector<C> a;

	poly_complex(int n = 0) : a(n) {}
	poly_complex(C x) : a(1, x) {}
	poly_complex(const vector<C>& a) : a(a) {}

	auto begin() const { return a.cbegin(); }
	auto begin() { return a.begin(); }
	auto size() const { return a.size(); }
	auto end() const { return a.cend(); }
	auto end() { return a.end(); }

	C& operator[] (size_t i) { return a[i]; }
	const C& operator[] (size_t i) const { return a[i]; }

	void trim() {
		while (a.size() && abs(a.back()) < 1e-12)
			a.pop_back();
	}

	poly_complex& operator+= (const poly_complex& b) {
		a.resize(max(a.size(), b.size()));
		for (int i=0; i<(int)b.size(); i++)
			a[i] += b[i];
		return *this;
	}

	poly_complex& operator-= (const poly_complex& b) {
		a.resize(max(a.size(), b.size()));
		for (int i=0; i<(int)b.size(); i++)
			a[i] -= b[i];
		return *this;
	}

	poly_complex operator+ (const poly_complex& b) const {
		auto t = *this; return t += b;
	}

	poly_complex operator- (const poly_complex& b) const {
		auto t = *this; return t -= b;
	}

	poly_complex fft_multiply (const poly_complex& b) const {
		int u = a.size() + b.size() - 1, n = true_size(u);
		vector<C> e(n), f(n);
		for (int i=0; i<(int)a.size(); i++)
			e[i] = a[i];
		for (int i=0; i<(int)b.size(); i++)
			f[i] = b[i];
		fft(e, false);
		fft(f, false);
		for (int i=0; i<n; i++)
			e[i] *= f[i];
		fft(e, true);
		poly_complex c;
		c.a = move(e);
		c.trim();
		return c;
	}

	poly_complex brute_multiply (const poly_complex& b) const {
		int u = a.size() + b.size() - 1;
		poly_complex c(u);
		for (int i=0; i<(int)a.size(); i++)
			for (int j=0; j<(int)b.size(); j++)
				c[i+j] += a[i] * b[j];
		c.trim();
		return c;
	}

	poly_complex operator* (const poly_complex& b) const {
		if (!size() || !b.size())
			return {};
		int u = a.size() + b.size() - 1, n = true_size(u);
		if (12ll * (31 - __builtin_clz(n)) * n < (ll)a.size() * (ll)b.size())
			return fft_multiply(b);
		else
			return brute_multiply(b);
	}

	poly_complex& operator*= (const poly_complex& b) {
		return *this = *this * b;
	}

	// @n - power of two
	poly_complex poly_inv(int n) const {
		poly_complex a = *this;
		a.a.resize(n);
		poly_complex rn(C(1) / a[0]);
		for (int l=1; l<n; l<<=1) {
			poly_complex an(2*l);
			for (int i=0; i<2*l; i++)
				an[i] = a[i];
			auto tmp = rn * rn * an;
			(rn += rn) -= tmp;
			rn.a.resize(2*l);
		}
		return rn;
	}

	// @n - power of two
	poly_complex poly_sqrt(int n) const {
		if (size() == 0)
			return {};
		poly_complex a = *this;
		C scale = C(1) / a[0];
		a.a.resize(n);
		for (int i=0; i<n; i++)
			a[i] *= scale;
		poly_complex rn(C(1));
		for (int l=1; l<n; l<<=1) {
			auto t = rn + rn;
			t = t.poly_inv(l);
			auto b = a - rn * rn;
			b.a.resize(n);
			b.a.erase(b.a.begin(), b.a.begin() + l);
			b.a.resize(l);
			t *= b;
			rn.a.resize(2*l);
			for (int i=0; i<l; i++)
				rn[i+l] = t[i];
		}
		scale = C(1) / sqrt(scale);
		for (C& x : rn)
			x *= scale;
		return rn;
	}
};

typedef float real_t;

int p[26];
string s, t;
int n, m;
real_t z[200005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	for (int i=0; i<26; i++)
		cin >> p[i], p[i]--;
	cin >> s >> t;
	n = s.size();
	m = t.size();

	for (int y=0; y<26; y+=2) {
		char c0 = 'a' + y, c1 = c0 + 1;
		poly_complex<real_t> a(n);
		for (int i=0; i<n; i++)
			a[n-1-i] = complex<real_t> {
				real_t(s[i] == c0 || p[s[i]-'a']+'a' == c0),
				real_t(s[i] == c1 || p[s[i]-'a']+'a' == c1)
			};

		poly_complex<real_t> b(m);
		for (int i=0; i<m; i++)
			b[i] = complex<real_t> {real_t(t[i] == c1), real_t(t[i] == c0)};
		auto g = a * b;
		for (int i=0; i<m; i++)
			z[i] += g[n-1+i].imag();
	}

	for (int i=0; i<=m-n; i++)
		cout << (z[i] > n - 0.5);
	cout << '\n';
}