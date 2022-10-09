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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

int n, t;
pair<int, int> a[55];
int P=1, Q=1, R=1;
mint dp[2505][5508];
mint ways[55][55][55][4];
mint f[55];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> t;
	for (int i=0; i<n; i++)
		cin >> a[i].second >> a[i].first;
	sort(a, a+n);
	dp[0][0] = 1;
	for (int i=0; i<n; i++) {
		switch (a[i].first) {
			case 1: P++; break;
			case 2: Q++; break;
			case 3: R++; break;
		}
	}

	f[0] = 1;
	for (int i=1; i<55; i++)
		f[i] = f[i-1] * i;

	int thi = 0;
	for (int i=0; i<n; i++) {
		for (int t=thi; t>=0; t--) {
			for (int j=0; j<P*Q*R; j++) {
				if (dp[t][j] == 0)
					continue;

				// dodajem ga?
				int delta = 0;
				switch (a[i].first) {
					case 1: delta = 1; break;
					case 2: delta = P; break;
					case 3: delta = P*Q; break;
				}

				dp[t+a[i].second][j+delta] += dp[t][j];
			}
		}
		thi += a[i].second;
	}

	ways[0][0][0][0] = 1;
	for (int i=0; i<P; i++) {
		for (int j=0; j<Q; j++) {
			for (int k=0; k<R; k++) {
				mint v0 = ways[i][j][k][0];
				mint v1 = ways[i][j][k][1];
				mint v2 = ways[i][j][k][2];
				mint v3 = ways[i][j][k][3];
				mint vall = v0 + v1 + v2 + v3;

				ways[i+1][j][k][1] += vall - v1;
				ways[i][j+1][k][2] += vall - v2;
				ways[i][j][k+1][3] += vall - v3;
			}
		}
	}

	mint sol;
	for (int j=0; j<P*Q*R; j++) {
		int x = j % P;
		int y = j / P % Q;
		int z = j / P / Q;
		mint w = ways[x][y][z][1] + ways[x][y][z][2] + ways[x][y][z][3];

		// cerr << x << ' ' << y << ' ' << z << ": ";
		// cerr << (int)w << ' ' << (int)dp[t][j] << '\n';

		sol += w * dp[t][j] * f[x] * f[y] * f[z];
	}
	cout << (int)sol << '\n';
}