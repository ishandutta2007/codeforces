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

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

typedef vector<mint> vec;
typedef vector<vec> mat;

mat mul(const mat& a, const mat& b) {
	int n = a.size();
	mat c(n, vec(n));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				c[i][k] += a[i][j] * b[j][k];
	return c;
}

mat pw(mat a, int k) {
	if (k == 1)
		return a;
	mat b = pw(a, k >> 1);
	b = mul(b, b);
	if (k & 1)
		b = mul(b, a);
	return b;
}

int n, k, w;
vector<int> a;

int calc_disp(const vector<int>& a) {
	int z = 0;
	for (int i=0; i<n; i++)
		if (a[i] != (i >= w))
			z += 1;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	vector<int> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		w += a[i] == 0;
	}

	vector<int> b = a;
	set<int> disps;

	mat mt(n+1, vec(n+1));

	sort(b.begin(), b.end());
	for (int i=0; i<n; i++) {
		int disp = calc_disp(b);
		if (!disps.count(disp)) {
			disps.insert(disp);
			auto c = b;
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {
					swap(c[i], c[j]);
					mt[disp][calc_disp(c)]++;
					swap(c[i], c[j]);
				}
			}
		}
		rotate(b.begin(), b.begin()+1, b.end());
	}
	mt = pw(mt, k);
	cout << (int)(mt[calc_disp(a)][0] * (mint(n*(n-1)/2).inv() ^ k)) << '\n';
}