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

template<class T, int N>
struct matrix {
	T a[N][N];
	int n;

	matrix(int _n = N) : n(_n) {
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				a[i][j] = T();
	}

	T* operator[] (int x) {
		return a[x];
	}

	const T* operator[] (int x) const {
		return a[x];
	}

	static matrix eye(int n = N) {
		matrix t(n);
		for (int i=0; i<n; i++)
			t[i][i] = 1;
		return t;
	}

	matrix operator* (const matrix& b) const {
#ifdef LOCAL
		if (n != b.n)
			throw "matrix size mismatch";	
#endif
		matrix c(n);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<n; k++)
					c[i][k] += a[i][j] * b[j][k];
		return c;
	}

	matrix& operator*= (const matrix& b) {
		return *this = *this * b;
	}

	template<class U>
	matrix operator^ (U arg) const {
		if (arg == 0)
			return matrix::eye(n);
		if (arg == 1)
			return *this;
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1)
			t *= *this;
		return t;
	}

	template<class U>
	matrix operator^= (U arg) {
		return *this = *this ^ arg;
	}
};

typedef matrix<mint, 3> mat;

map<ll, int> e[3];
map<ll, int> f;

mat b[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	ll m;
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		ll l, r;
		cin >> x >> l >> r;
		x--;
		e[x][l] += 1;
		e[x][r+1] -= 1;
		e[(x+1)%3][l];
		e[(x+1)%3][r+1];
		e[(x+2)%3][l];
		e[(x+2)%3][r+1];
		f[l];
		f[r+1];
	}
	f[2]; e[0][2]; e[1][2]; e[2][2];
	f[m]; e[0][m]; e[1][m]; e[2][m];

	map<ll, int>::iterator ite[3];
	for (int i=0; i<3; i++)
		ite[i] = e[i].begin();
	int z[3] = {0};

	for (auto& p : f) {
		for (int i=0; i<3; i++) {
			z[i] += ite[i]->second;
			ite[i]++;
			if (z[i])
				p.second |= 1 << i;
		}
	}

	b[0][0][0] = 1;
	b[0][0][1] = 1;
	b[0][1][0] = 1;
	b[0][1][1] = 1;
	b[0][1][2] = 1;
	b[0][2][1] = 1;
	b[0][2][2] = 1;

	for (int mask=1; mask<8; mask++) {
		b[mask] = b[0];
		for (int i=0; i<3; i++) {
			if (mask & (1 << i)) {
				b[mask][0][i] = 0;
				b[mask][1][i] = 0;
				b[mask][2][i] = 0;
			}
		}
	}

	mat kompozit = mat::eye();
	auto it1 = f.begin();
	auto it2 = next(it1);
	while (it2 != f.end()) {
		// cerr << "mnozim " << bitset<3>(it1->second)
			// << ' ' << (it2->first - it1->first) << '\n';
		kompozit *= b[it1->second] ^ (it2->first - it1->first);
		++it1;
		++it2;
	}
	kompozit *= b[0];
	cout << (int)kompozit[1][1] << '\n';
}