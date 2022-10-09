// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

template<int mod>
struct poly_mint {
	typedef modint<mod> mint;

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

	static mint primitive_root() {
		static mint cached = 0;
		if (cached == 0) {
			for (int x=1;; x++) {
				int ok = 1;
				for (int y=2; y*y<mod-1; y++) {
					if ((mod-1) % y == 0 && (mint(x) ^ ((mod-1) / y)) == 1)
						ok = 0;
				}
				if (ok) {
					cached = x;
					break;
				}
			}
		}
		return cached;
	}

	static void fft(vector<mint>& a, bool inv) {
		int n = a.size(), l = 31 - __builtin_clz(n);
		for (int i=0; i<n; i++) {
			int j = bitrev(i, l);
			if (j < i)
				swap(a[i], a[j]);
		}

		static int ords = 0;
		static vector<vector<mint>> wv;
		static vector<vector<mint>> winv;

		while (l > ords) {
			int m = 1 << ords;
			vector<mint> v(m);
			mint b = primitive_root() ^ ((mod-1) / (2 * m));
			v[0] = 1;
			for (int i=1; i<m; i++)
				v[i] = v[i-1] * b;
			wv.emplace_back(move(v));

			b = b.inv();
			v.resize(m);
			v[0] = 1;
			for (int i=1; i<m; i++)
				v[i] = v[i-1] * b;
			winv.emplace_back(move(v));
			ords++;
		}

		for (int h=1, e=0; h<n; h<<=1, e++) {
			for (int i=0; i<n; i+=2*h) {
				for (int j=i; j<i+h; j++) {
					mint w = (inv ? winv : wv)[e][j-i];
					mint u = a[j], v = a[j+h] * w;
					a[j] = u + v;
					a[j+h] = u - v;
				}
			}
		}

		if (inv) {
			mint n1 = mint(n).inv();;
			for (mint& x : a)
				x *= n1;
		}
	}

	vector<mint> a;

	poly_mint(int n = 0) : a(n) {}
	poly_mint(mint x) : a(1, x) {}
	poly_mint(const vector<mint>& a) : a(a) {}

	auto begin() const { return a.cbegin(); }
	auto begin() { return a.begin(); }
	auto size() const { return a.size(); }
	auto end() const { return a.cend(); }
	auto end() { return a.end(); }

	mint& operator[] (size_t i) { return a[i]; }
	const mint& operator[] (size_t i) const { return a[i]; }

	void trim() {
		while (a.size() && a.back() == 0)
			a.pop_back();
	}

	poly_mint& operator+= (const poly_mint& b) {
		a.resize(max(a.size(), b.size()));
		for (int i=0; i<(int)b.size(); i++)
			a[i] += b[i];
		return *this;
	}

	poly_mint& operator-= (const poly_mint& b) {
		a.resize(max(a.size(), b.size()));
		for (int i=0; i<(int)b.size(); i++)
			a[i] -= b[i];
		return *this;
	}

	poly_mint operator+ (const poly_mint& b) const {
		auto t = *this; return t += b;
	}

	poly_mint operator- (const poly_mint& b) const {
		auto t = *this; return t -= b;
	}

	poly_mint fft_multiply (const poly_mint& b) const {
		int u = a.size() + b.size() - 1, n = true_size(u);
		vector<mint> e(n), f(n);
		for (int i=0; i<(int)a.size(); i++)
			e[i] = a[i];
		for (int i=0; i<(int)b.size(); i++)
			f[i] = b[i];
		fft(e, false);
		fft(f, false);
		for (int i=0; i<n; i++)
			e[i] *= f[i];
		fft(e, true);
		poly_mint c;
		c.a = move(e);
		c.trim();
		return c;
	}

	poly_mint brute_multiply (const poly_mint& b) const {
		int u = a.size() + b.size() - 1;
		poly_mint c(u);
		for (int i=0; i<(int)a.size(); i++)
			for (int j=0; j<(int)b.size(); j++)
				c[i+j] += a[i] * b[j];
		c.trim();
		return c;
	}

	poly_mint operator* (const poly_mint& b) const {
		if (!size() || !b.size())
			return {};
		int u = a.size() + b.size() - 1, n = true_size(u);
		if (12ll * (31 - __builtin_clz(n)) * n < (ll)a.size() * (ll)b.size())
			return fft_multiply(b);
		else
			return brute_multiply(b);
	}

	poly_mint& operator*= (const poly_mint& b) {
		return *this = *this * b;
	}

	// @n - power of two
	poly_mint poly_inv(int n) const {
		poly_mint a = *this;
		a.a.resize(n);
		poly_mint rn(a[0].inv());
		for (int l=1; l<n; l<<=1) {
			poly_mint an(2*l);
			for (int i=0; i<2*l; i++)
				an[i] = a[i];
			auto tmp = rn * rn * an;
			(rn += rn) -= tmp;
			rn.a.resize(2*l);
		}
		return rn;
	}

	// @n - power of two, a[0] = 1
	poly_mint poly_sqrt(int n) const {
		if (size() == 0)
			return {};
		poly_mint a = *this;
		a.a.resize(n);
		poly_mint rn(mint(1));
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
		return rn;
	}
};

template<class T = mint>
struct binomial {
	vector<T> f, finv;

	binomial(int n) : f(n), finv(n) {
		f[0] = finv[0] = 1;
		for (int i=1; i<n; i++) {
			f[i] = f[i-1] * i;
			finv[i] = f[i].inv();
		}
	}

	mint mix(int a, int b) {
		if (a < 0 || b < 0)
			return 0;
		return f[a+b] * finv[a] * finv[b];
	}

	mint choose(int n, int k) {
		return mix(n-k, k);
	}
};

typedef poly_mint<mod> poly;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  binomial bin(200005);

  int n;
  cin >> n;

  int p = 1;
  poly a(1);
  a[0] = 1;

  for (int i=0; i<n; i++) {
    int x, y;
    cin >> x >> y;
    // +x-y
    int q = p+x-y;
    int c = x+y;
    int e = p;

    poly b(q+e);
    for (int i=0; i<q+e; i++) {
      b[i] = bin.choose(c, i+y-e);
    }

    a *= b;
    a.a.erase(a.a.begin(), a.a.begin() + e);
    a.a.resize(q);
    p = q;
  }

  cout << accumulate(begin(a), end(a), mint())() << '\n';
}