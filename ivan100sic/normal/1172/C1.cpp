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
int w[55], t[55], w0, w1;
mint dp[55][55][55], inverz[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=1; i<10000; i++)
		inverz[i] = mint(i).inv();

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

	for (int i=0; i<n; i++) {
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		int x = w[i];
		int w0 = ::w0;
		int w1 = ::w1;
		if (t[i] == 0)
			w0 -= x;
		else
			w1 -= x;
		int dir = t[i] == 0 ? -1 : 1;

		for (int p=0; p<m; p++)
			for (int q=0; p+q<m; q++)
				for (int r=0; p+q+r<m; r++) {
					int ukupno = (x+p*dir) + (w0-q) + (w1+r);
					if (w0-q < 0 || x+p*dir < 0)
						continue;

					mint ukinv = inverz[ukupno] * dp[p][q][r];
					dp[p+1][q][r] += ukinv * mint(x+p*dir);
					dp[p][q+1][r] += ukinv * mint(w0-q);
					dp[p][q][r+1] += ukinv * mint(w1+r);
				}

		mint sol;

		for (int p=0; p<=m; p++)
			for (int q=0; p+q<=m; q++) {
				int r = m-p-q;
				sol += dp[p][q][r] * (x+p*dir);
			}

		cout << (int)sol << '\n';
	}
}