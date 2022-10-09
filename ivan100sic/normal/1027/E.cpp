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

const int MOD = 998244353;
typedef modint<MOD> mint;

mint dp[2][505][505];
mint b[505];
int n, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	dp[1][1][1] = 1;
	for (int i=1; i<n; i++) {
		auto ol = dp[i%2];
		auto nu = dp[1-i%2];
		
		for (int j=1; j<=i+1; j++)
			for (int k=1; k<=i+1; k++)
				nu[j][k] = 0;

		for (int maxlen=1; maxlen<=i; maxlen++) {
			for (int len=1; len<=maxlen; len++) {
				// produzim ovaj niz
				nu[len+1][max(maxlen, len+1)] += ol[len][maxlen];
				// resetujem
				nu[1][maxlen] += ol[len][maxlen];
			}
		}
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			b[i] += dp[n%2][j][i]; // ?
	
	/*
	for (int i=1; i<=n; i++)
		cerr << i << ' ' << (int)b[i] << '\n';
	*/
		
	mint sol = 0;

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (i*j < k) {
				sol += b[i] * b[j] * 2;
			}

	cout << (int)sol << '\n';
}