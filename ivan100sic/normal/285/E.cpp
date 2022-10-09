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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

const int H = 1001;
mint dp[1005][1005][2][2];
mint rz[1005][1005];
mint f[1005];

void dpcc() {
	dp[1][0][0][0] = 1;
	dp[1][1][0][1] = 1;

	f[0] = 1;
	for (int i=1; i<=H; i++)
		f[i] = f[i-1] * i;

	for (int n=1; n<=H; n++) {
	for (int j=0; j<=n; j++) {
	for (int a=0; a<=1; a++) {
	for (int b=0; b<=1; b++) {
		mint w = dp[n][j][a][b];
		// sta stavljam na poziciju n+1?
		// stavljam n
		if (a == 0)
			dp[n+1][j+1][b][0] += w;
		// stavljam n+2
		dp[n+1][j+1][b][1] += w;
		// ne stavljam nista
		dp[n+1][j][b][0] += w;
	}}}}

	for (int i=1; i<=H; i++)
		for (int j=0; j<=i; j++) {
			mint w = dp[i][j][0][0] + dp[i][j][1][0];
			w *= f[i-j];
			rz[i][j] = w;
		}
}

void solve(int n, int k) {
	mint bk = 1, z = 0;
	for (int j=k; j<=n; j++) {
		z += rz[n][j] * bk;
		bk = bk * (-j-1) * mint(j-k+1).inv();
	}
	cout << (int)z << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	dpcc();
	int n, k;
	cin >> n >> k;
	solve(n, k);
}