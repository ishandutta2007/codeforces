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

int n, k;
int a[205];
int z[205];

map<int, mint> dp[2][105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	sort(a+1, a+n+1);

	for (int i=1; i<=n; i++)
		z[i] = z[i-1] + a[i];

	dp[0][0] = {{0, 1}};

	for (int i=1; i<=n; i++) {

		auto ol = dp[1-i%2];
		auto nu = dp[i%2];

		fill(nu, nu+105, map<int, mint>());

		for (int j=0; j<=n/2; j++) {
			for (auto p : ol[j]) {

				// ako ne moze da se dovrsi, prekini
				if (p.first + z[i+j-1] - z[i-1] > k)
					// continue;
					break;

				// otvaramo novi skup
				nu[j+1][p.first - a[i]] += p.second;

				// zatvaramo ranije otvoreni skup
				if (j > 0)
					nu[j-1][p.first + a[i]] += p.second * j;

				// dodajemo u novi skup i odmah ga zatvaramo
				nu[j][p.first] += p.second;

				// dodajemo u neki ranije otvoreni skup bez zatvaranja
				nu[j][p.first] += p.second * j;
			}
		}
	}

	mint sol;
	for (int kk=0; kk<=k; kk++)
		sol += dp[n%2][0][kk];

	cout << (int)sol << '\n';
}