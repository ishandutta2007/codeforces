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

struct mat {
	mint a[100][100];

	mat operator* (const mat& o) const {
		mat tmp;
		for (int i=0; i<100; i++)
			for (int j=0; j<100; j++)
				for (int k=0; k<100; k++)
					tmp.a[i][k] += a[i][j] * o.a[j][k];
		return tmp;
	}

	static mat diag() {
		mat tmp;
		for (int i=0; i<100; i++)
			tmp.a[i][i] = 1;
		return tmp;
	}
};

mat stepen(mat a, ll y) {
	if (y == 0)
		return mat::diag();
	mat b = stepen(a, y >> 1);
	b = b * b;
	if (y & 1) {
		b = b * a;
	}
	return b;
}

ll a[105], k;
int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	mat t;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (__builtin_popcountll(a[i] ^ a[j]) % 3 == 0)
				t.a[i][j] = 1;

	t = stepen(t, k-1);
	mint res = 0;	
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			res += t.a[i][j];

	cout << (int)res << '\n';
}