/* serem vam se na servere */

#include <bits/stdc++.h>
using namespace std;

/* na sta sam ja dao 5 dolara... */

template<unsigned long long m>
struct modint {

	unsigned long long x;

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
		x = (x * other.x) % m;
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

	explicit operator unsigned long long () const {
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

	modint operator^ (unsigned long long arg) const {
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

	modint inv(unsigned long long exp = m - 2) const {
		return *this ^ exp;
	}
};

const unsigned long long MOD = 1'000'000'007;
typedef modint<MOD> mint;

int n, k;
mint f[1000005], finv[1000005];

int solve(int n, int k) {
	vector<mint> v(n+1);
	for (int i=1; i<=min(n, k+1); i++) {
		v[i] = f[i];
	}
	for (int i=k+2; i<=n; i++) {
		v[i] = v[i-1] * i - v[i-k-1] * f[i-2] * finv[i-k-2];
	}
	return (unsigned long long)(f[n] - v[n]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	f[0] = 1;
	finv[0] = 1;
	for (int i=1; i<=n; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}

	cout << solve(n, k);

}