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

int n, m;
string s;
int fail[2][205];
mint dp[2][205][205];

int sufpref(string q) {
	for (int i=q.size(); i>0; i--)
		if (q.substr(q.size() - i, i) == s.substr(0, i))
			return i;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	m = s.size();
	// meh just brute force this
	for (int i=0; i<=m; i++) {
		// najduzi sufiks koji je prefiks od q
		fail[0][i] = sufpref(s.substr(0, i) + '(');
		fail[1][i] = sufpref(s.substr(0, i) + ')');

		// cerr << "fail " << i << ' ' << fail[0][i] << ' ' << fail[1][i] << '\n';
	}

	dp[0][0][0] = 1;
	for (int i=0; i<=2*n; i++) {

		auto nu = dp[1-i%2];
		auto ol = dp[i%2];

		memset(nu, 0, sizeof(dp[0]));

		for (int j=0; j<=n; j++) {
			for (int k=0; k<=m; k++) {

				// cerr << i << ' ' << j << ' ' << k << ": " << (int)ol[j][k] << '\n';

				int k1 = k < m ? fail[0][k] : m;
				int k2 = k < m ? fail[1][k] : m;

				nu[j+1][k1] += ol[j][k];
				if (j > 0)
					nu[j-1][k2] += ol[j][k];
			}
		}
	}

	cout << (int)dp[0][0][m] << '\n';
}