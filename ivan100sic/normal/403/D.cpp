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

mint f[1005], finv[1005];

mint bk(int n, int k) {
	if (n < 0 || k < 0 || n-k < 0)
		return 0;
	return f[n] * finv[k] * finv[n-k];
}

mint dp[1005][1005][52];
mint gusto[2005][75];
mint retko[2005][75];
mint resenje[2005][75];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<1005; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}

	for (int x=0; x<=1000; x++)
		dp[x][x][1] = 1;

	for (int k=1; k<=50; k++) {
		for (int n=0; n<=1000; n++) {
			for (int p=0; p<=1000; p++) {
				if (dp[n][p][k] == 0)
					continue;
				gusto[n+k-1][k] += dp[n][p][k];

				// for (int x=p+1; n+x<=1000; x++) {
				// 	dp[n+x][x][k+1] += dp[n][p][k];
				// }

				if (n+p+1 <= 1000)
					dp[n+p+1][p+1][k+1] += dp[n][p][k];
			}
		}

		for (int n=1; n<=1000; n++)
			for (int p=1; p<=1000; p++)
				dp[n][p][k+1] += dp[n-1][p-1][k+1];
	}

	for (int n=0; n<=1000; n++) {
		for (int k=1; k<=50; k++) {
			if (gusto[n][k] == 0)
				continue;
			for (int m=n; m<=1000; m++) {
				// if (m == 4 && k == 2)
				// 	cerr << "~~ " << n << ' ' << (int)gusto[n][k] << ' ' << (int)bk(m-n+k, k) << '\n';
				retko[m][k] += gusto[n][k] * bk(m-n+k, k);
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (y > 50) {
			cout << "0\n";
			continue;
		}
		cout << (int)(retko[x-1][y] * f[y]) << '\n';
	}

}