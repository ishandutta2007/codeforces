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

typedef poly_real<long double> poly;

int n, x, y, q;
int a[200005];
bool ima[1000005];
basic_string<int> divv[1000005];
int ans[1000005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> x >> y;

	poly p(200055), r(200055);

	for (int i=0; i<=n; i++) {
		cin >> a[i];
		p[a[i]] += 1;
		r[200022 - a[i]] += 1;
	}

	p *= r;

	for (int i=0; i<=200000; i++) {
		int j = i + 200022;
		if (j < (int)p.size() && p[j] > 0.5) {
			ima[i] = 1;
		}
	}

	for (int i=2; i<=1000000; i+=2) {
		for (int j=i; j<=1000000; j+=i) {
			divv[j] += i;
		}
		ans[i] = -2;
	}

	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		if (ans[x] != -2) {
			cout << ans[x] << ' ';
			continue;
		}

		ans[x] = -1;
		for (int d : divv[x]) {
			int l = (d-2*y) / 2;
			if (l > 0 && ima[l]) {
				ans[x] = d;
			}
		}

		cout << ans[x] << ' ';
	}
	cout << '\n';
}