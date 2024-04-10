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

int n, k;
mint dp[155][155][2], f[155], finv[155];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	f[0] = finv[0] = 1;
	for (int i=1; i<155; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}
	
	dp[1][0][0] = 1;

	for (int a=2; a<=n; a++) {
		for (int b=0; b<=k; b++) {

			if (b > 0) dp[a][b][1] += dp[a-1][b-1][0] * a;
			dp[a][b][0] += dp[a-1][b][1] * a;

			for (int i=1; i<a; i++) {
				for (int j=0; j<=b; j++) {
					mint w = f[a] * finv[i] * finv[a-i-1] * finv[2];

					if (b-j > 0) dp[a][b][1] += dp[i][j][0] * dp[a-i-1][b-j-1][0] * w;
					if (b-j > 0) dp[a][b][1] += dp[i][j][0] * dp[a-i-1][b-j-1][1] * w;
					if (b-j > 0) dp[a][b][1] += dp[i][j][1] * dp[a-i-1][b-j-1][0] * w;
					dp[a][b][0] += dp[i][j][1] * dp[a-i-1][b-j  ][1] * w;
				}
			}
		}
	}

	cout << (int)((dp[n][k][0] + dp[n][k][1]) * mint(n).inv()) << '\n';
	// cout << (int)(dp[n][k][0] + dp[n][k][1]) << '\n';
}