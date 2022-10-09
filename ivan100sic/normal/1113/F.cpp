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

// broj drva sa putem od k grana: (k+1) * n^(n-(k+1)-1) (paziti za k=n-1)
//     puta binomni koeficijent (biramo k-1 cvorova od n-2 da budu izmedju)
//     puta redosled tih cvorova

// broj nacina da napravimo zbir m od brojeva 1..m sa k brojeva:
//     biras k-1 mesto da seces niz duzine m

mint f[1000005], finv[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, a, b;
	cin >> n >> m >> a >> b;

	f[0] = finv[0] = 1;
	for (int i=1; i<1000005; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}

	mint sol = 0, st1 = mint(n) ^ (n-2);
	mint n_inv = mint(n).inv();
	for (int k=1; k<n && k<=m; k++) {
		st1 *= n_inv;
		mint p = st1 * (k+1);
		p *= f[n-2] * f[n-k-1].inv();
		mint q = f[m-1] * f[k-1].inv() * f[m-k].inv();
		mint r = mint(m) ^ (n-1-k);
		sol += p*q*r;
	}
	cout << (int)sol << '\n';
}