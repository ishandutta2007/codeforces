#include <bits/stdc++.h>
using namespace std;

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

mint bk[5005][5005];
mint pows[5005];

mint vr[5005];

int n, k;

mint smallinv[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	bk[0][0] = 1;

	bk[1][0] = 1;
	bk[1][1] = 1;

	pows[1] = 1;

	for (int i=2; i<=k; i++) {
		bk[i][0] = 1;
		bk[i][i] = 1;
		for (int j=1; j<i; j++) {
			bk[i][j] = bk[i-1][j] + bk[i-1][j-1];
		}
		pows[i] = mint(i) ^ k;
	}

	for (int i=1; i<=k; i++) {
		for (int j=1; j<=i; j++) {
			vr[i] += bk[i][j] * pows[j];
		}
	}

	// interpolate
	if (n <= k) {
		cout << vr[n].x << '\n';
		return 0;
	}

	for (int i=0; i<=2*k; i++) {
		smallinv[i] = mint(i - k + MOD).inv();
	}

	mint sol = 0;
	
	for (int i=0; i<=k; i++) {
		mint pi = vr[i] * (mint(2).inv() ^ i);

		for (int j=0; j<=k; j++) {
			if (j != i) {
				pi *= mint(n) - j;
				pi *= smallinv[i-j+k];
			}
		}

		sol += pi;
	}

	sol *= mint(2) ^ n;

	cout << sol.x << '\n';

}