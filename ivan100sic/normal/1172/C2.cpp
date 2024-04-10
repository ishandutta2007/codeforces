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

int n, m;
int w[200005], t[200005], w0, w1;
mint dp[3005][3005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> t[i];
	for (int i=0; i<n; i++) {
		cin >> w[i];
		if (t[i] == 0)
			w0 += w[i];
		else
			w1 += w[i];
	}

	mint* offset_inv = new mint[6001] + 3000;

	for (int i=-3000; i<=3000; i++)
		offset_inv[i] = mint(w0+w1+i).inv();

	dp[0][0] = 1;
	for (int i=0; i<m; i++) {
		for (int j=0; j<m; j++) {
			int w0 = ::w0 - i;
			int w1 = ::w1 + j;
			if (w0 < 0)
				continue;

			mint xd = dp[i][j] * offset_inv[j-i];
			dp[i+1][j] += xd * w0;
			dp[i][j+1] += xd * w1;
		}
	}

	// prvo brut
	mint sol0, sol1;

	for (int j=0; j<=m; j++)
		sol1 += dp[j][m-j] * (w1+m-j);

	for (int j=0; j<=m && j<=w0; j++)
		sol0 += dp[j][m-j] * (w0-j); 

	for (int i=0; i<n; i++) {
		if (t[i] == 1) {
			mint sol = sol1;
			sol *= mint(w1).inv() * w[i];
			cout << (int)sol << '\n';
		} else {
			mint sol = sol0;
			sol *= mint(w0).inv() * w[i];
			cout << (int)sol << '\n';
		}
	}
}