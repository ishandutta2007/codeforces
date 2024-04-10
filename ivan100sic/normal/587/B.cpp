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

int n, k;
ll l;
vector<int> a, as;
vector<vector<mint>> dp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> l >> k;
	a.resize(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	as.resize(n);
	iota(as.begin(), as.end(), 0);
	sort(as.begin(), as.end(), [&](int x, int y) { return a[x] < a[y]; });

	dp.resize(k+1, vector<mint>(n));
	for (int j=0; j<n; j++)
		dp[1][j] = 1;
	for (int i=2; i<=k; i++) {
		int r = 0;
		mint sum = 0;
		for (int j=0; j<n; j++) {
			while (r < n && a[as[r]] <= a[as[j]]) {
				sum += dp[i-1][as[r]];
				r++;
			}
			dp[i][as[j]] = sum;
		}
	}

	mint sol = 0;

	for (int x=1; x<=k; x++) {
		for (int i=0; i<n; i++) {
			ll w = l/n - x + 1 + (i<l%n);
			sol += dp[x][i] * max(0ll, w);
		}
	}

	cout << (int)sol << '\n';
}