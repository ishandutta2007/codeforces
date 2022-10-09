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

const int MOD = 998244353;
typedef modint<MOD> mint;

mint f[5005], finv[5005], p2[5005], inv[5005];
mint dp[5005][5005];
int n;
int c[5005], z[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	p2[0] = f[0] = finv[0] = 1;
	for (int i=1; i<5005; i++) {
		f[i] = f[i-1] * i;
		inv[i] = mint(i).inv();
		finv[i] = finv[i-1] * inv[i];
		p2[i] = p2[i-1] + p2[i-1];
	}

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}
	for (int i=1; i<=n; i++)
		z[i] = z[i-1] + c[i];

	dp[0][0] = 1;
	for (int i=1; i<=n; i++) {
		// ne uzmes nista
		for (int j=0; j<=n; j++) {
			dp[i][j] += dp[i-1][j];
		}
		// uzmes jedan i
		for (int j=1; j<=n; j++) {
			dp[i][j] += dp[i-1][j-1] * c[i] * inv[n-j+1];
		}
	}

	// cerr << (int)(dp[1][0]) << '\n';

	mint total = 0;
	for (int i=1; i<=n; i++) {
		mint q = c[i] * (c[i] - 1), w = 0;
		for (int l=0; l<=z[i-1]; l++) {
			w += dp[i-1][l] * inv[n-l] * inv[n-l-1];
		}
		total += w * q;
	}

	cout << (int)total << '\n';
}