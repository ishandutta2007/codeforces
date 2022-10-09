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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

typedef vector<mint> vec;
typedef vector<vec> mat;

mat ident(int k) {
	mat a(k, vec(k));
	for (int i=0; i<k; i++)
		a[i][i] = 1;
	return a;
}

mat zero(int k) {
	return mat(k, vec(k));
}

mat mul(mat a, mat b) {
	int n = a.size();
	mat c = zero(n);
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			for (int k=0; k<n; k++)
				c[i][k] += a[i][j] * b[j][k];
	return c;
}

mat pw(mat a, int k) {
	if (k == 0)
		return ident(a.size());
	if (k == 1)
		return a;

	auto b = pw(a, k >> 1);
	b = mul(b, b);
	if (k & 1)
		b = mul(b, a);
	return b;
}

int n, x;
int d[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	for (int i=0; i<n; i++)
		cin >> d[i];

	mat a = zero(111);
	for (int i=0; i<110; i++)
		a[i][i+1] = 1;
	for (int i=0; i<n; i++) {
		a[110][111 - d[i]] += 1;
		a[110][110 - d[i]] -= 1;
	}
	a[110][110] += 1;

	auto b = pw(a, x);
	// resenje je b.v[110] gde je v = {0, ..., 1}

	// ofstream fout("tmp");
	// for (int i=0; i<111; i++)
	// 	for (int j=0; j<111; j++)
	// 		fout << (int)b[i][j] << " \n"[j == 110];


	cout << (int)b[110][110] << '\n';
}