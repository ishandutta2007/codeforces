#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * 1ll * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator int () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	template<class T>
	modint operator^ (T arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 998244353;
typedef modint<MOD> mint;

typedef vector<mint> vm;

namespace fft {

	const int root = 15311432;
	const int root_1 = 469870224;
	const int root_pw = 1 << 23;

	int fftc = 0;

	void fft(vm& a, bool invert) {

		cerr << "fft brojac: " << ++fftc << '\n';

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
			const int lenh = len >> 1;
			mint wlen = invert ? root_1 : root;
			for (int i = len; i < root_pw; i <<= 1)
				wlen *= wlen;

			for (int i = 0; i < n; i += len) {
				mint w = 1;
				for (int j = i; j < i + lenh; j++) {
					mint u = a[j], v = a[j + lenh] * w;
					a[j] = u + v; 
					a[j+(len >> 1)] = u - v;
					w *= wlen;
				}
			}
		}

		if (invert) {
			mint n_1 = mint(n).inv();
			for (mint& x : a)
				x *= n_1;
		}
	}
}

mint fak[200005], fakinv[200005];

pair<vm, vm> dizi_polinom(vm p, int k1, int k2) {
	int n = 1;
	int orig = (int)p.size();
	while (n < 2*(int)p.size())
		n <<= 1;
	vm z = p;
	z.resize(n);

	// z je spremljena verzija ulaznog polinoma p

	vector<vm> stepeni(17);
	stepeni[0] = z;
	fft::fft(stepeni[0], false);
	for (int i=1; i<=16; i++) {
		stepeni[i].assign(n, 0);
		for (int j=0; j<n; j++)
			stepeni[i][j] = stepeni[i-1][j] * stepeni[i-1][j];
		fft::fft(stepeni[i], true);
		fill(stepeni[i].begin() + orig, stepeni[i].end(), mint(0));
		fft::fft(stepeni[i], false);
	}

	vm zajednicki(n, 0);
	zajednicki[0] = 1;

	for (int i=16; i>=0; i--) {
		if (((1 << i) & k1 & k2)) {
			fft::fft(zajednicki, false);
			for (int j=0; j<n; j++)
				zajednicki[j] *= stepeni[i][j];
			fft::fft(zajednicki, true);
			fill(zajednicki.begin() + orig, zajednicki.end(), mint(0));
		}
	}

	vm v1 = zajednicki, v2 = zajednicki;

	for (int i=16; i>=0; i--) {
		if (((1 << i) & k1 & ~k2)) {
			fft::fft(v1, false);
			for (int j=0; j<n; j++)
				v1[j] *= stepeni[i][j];
			fft::fft(v1, true);
			fill(v1.begin() + orig, v1.end(), mint(0));
		}

		if (((1 << i) & k2 & ~k1)) {
			fft::fft(v2, false);
			for (int j=0; j<n; j++)
				v2[j] *= stepeni[i][j];
			fft::fft(v2, true);
			fill(v2.begin() + orig, v2.end(), mint(0));
		}
	}

	return {v1, v2};
}

pair<vm, vm> kps(int n, int k1, int k2) {
	// operator primenjen k puta na niz {1, 0, 0, 0, ...}
	vector<mint> a(n);
	for (int i=1; i<n; i++)
		a[i] = mint(i).inv();
	auto [b, c] = dizi_polinom(a, k1, k2);
	for (int i=0; i<n; i++) {
		b[i] *= fak[i] * fakinv[k1];
		c[i] *= fak[i] * fakinv[k2];
	}
	return {b, c};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, a, b;

	fak[0] = fakinv[0] = 1;
	for (int i=1; i<200005; i++) {
		fak[i] = fak[i-1] * i;
		fakinv[i] = fak[i].inv();
	}

	cin >> n >> a >> b;

	if (a == 0 || b == 0) {
		cout << "0\n";
		return 0;
	}

	a--; b--;

	if (a + b >= n) {
		cout << "0\n";
		return 0;
	}

	auto [v1, v2] = kps(n, a, b);
	mint sol = 0;

	for (int j=0; j<n; j++) {
		int k = n-1-j;
		sol += v1[j] * v2[k] * fakinv[j] * fakinv[k] * fak[j+k];
	}

	cout << (int)sol << "\n";
}