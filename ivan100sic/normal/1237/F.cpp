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
		x = (x * 1ull * other.x) % m;
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

const int MOD = 998'244'353;
typedef modint<MOD> mint;

bool r[4444], c[4444];
int n, m, k;

mint dr[4444][4444];
mint dc[4444][4444];
mint bk[4444][4444];
mint f[4444];

template<class T, class U>
void dp(T a, int n, U d) {
	d[0][0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (i+1 < n && !a[i] && !a[i+1]) {
				d[i+2][j+1] += d[i][j];
			}
			d[i+1][j] += d[i][j];
		}
	}
}

mint bk_(int n, int k) {
	if (n < 0 || k < 0 || n-k < 0)
		return 0;
	return bk[n-k][k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = 1;
	for (int i=1; i<4444; i++)
		f[i] = f[i-1] * i;

	for (int i=0; i<4444; i++)
		bk[i][0] = bk[0][i] = 1;
	for (int i=1; i<4444; i++)
		for (int j=1; j<4444; j++)
			bk[i][j] = bk[i-1][j] + bk[i][j-1];

	cin >> n >> m >> k;
	for (int i=0; i<2*k; i++) {
		int x, y;
		cin >> x >> y;
		r[x-1] = c[y-1] = true;
	}

	dp(r, n, dr);
	dp(c, m, dc);

	int u = count(r, r+n, false);
	int v = count(c, c+m, false);

	mint sol = 0;
	for (int i=0; i<=u/2; i++) {
		for (int j=0; j<=v/2; j++) {
			sol += dr[n][i] * dc[m][j] * bk_(u-2*i, j) * bk_(v-2*j, i)
				* f[i] * f[j];
		}
	}

	cout << (int)sol << '\n';
}