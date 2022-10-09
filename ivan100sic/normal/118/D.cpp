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

const int MOD = 100000000;
typedef modint<MOD> mint;

mint dp[105][105][2][11];
int a, b, c, d;

void dod(mint& x, mint y) {
	x += y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a >> b >> c >> d;
	dp[0][0][0][0] = 1;
	for (int i=0; i<=a; i++) {
		for (int j=0; j<=b; j++) {
			for (int k=0; k<2; k++) {
				for (int l=0; l<=10; l++) {

					mint v = dp[i][j][k][l];

					// smem da stavim A?
					if (i < a && (k == 1 || l < c))
						dod(dp[i+1][j][0][k == 0 ? l+1 : 1], v);
					// B?
					if (j < b && (k == 0 || l < d))
						dod(dp[i][j+1][1][k == 1 ? l+1 : 1], v);
				}
			}
		}
	}

	mint sol;
	for (int l=1; l<=c; l++)
		dod(sol, dp[a][b][0][l]);
	for (int l=1; l<=d; l++)
		dod(sol, dp[a][b][1][l]);
	cout << (int)sol << '\n';
}