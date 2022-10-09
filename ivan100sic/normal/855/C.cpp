#include <bits/stdc++.h>
using namespace std;

template<unsigned long long m>
struct modint {

	unsigned long long x;

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
		x = (x * other.x) % m;
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

	explicit operator unsigned long long () const {
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

	modint operator^ (unsigned long long arg) const {
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

	modint inv(unsigned long long exp = m - 2) const {
		return *this ^ exp;
	}
};

const unsigned long long MOD = 1'000'000'007;
typedef modint<MOD> mint;

int N, M, K, X;
mint dp[100005][11][3];

vector<int> e[100005];

void dfs(int x, int p) {
	for (int y : e[x]) if (y != p) {
		dfs(y, x);
	}

	// uzimam manje od k
	{
		mint knap[2][11];

		knap[0][0] = 1;

		auto old = knap[0];
		auto nu = knap[1];

		for (int y : e[x]) if (y != p) {

			for (int j=0; j<=X; j++) {
				nu[j] = 0;
			}

			for (int amt=0; amt<=X; amt++) {
				for (int novo=amt; novo<=X; novo++) {
					nu[novo] += old[novo-amt] * dp[y][amt][0];
					nu[novo] += old[novo-amt] * dp[y][amt][1];
					nu[novo] += old[novo-amt] * dp[y][amt][2];
				}
			}

			swap(old, nu);
		}

		for (int i=0; i<=X; i++) {
			dp[x][i][0] = old[i] * (K-1);
		}
	}

	// uzimam tacno K
	{
		mint knap[2][11];

		knap[0][0] = 1;

		auto old = knap[0];
		auto nu = knap[1];

		for (int y : e[x]) if (y != p) {

			for (int j=0; j<=X; j++) {
				nu[j] = 0;
			}

			for (int amt=0; amt<=X; amt++) {
				for (int novo=amt; novo<=X; novo++) {
					nu[novo] += old[novo-amt] * dp[y][amt][0];
				}
			}

			swap(old, nu);
		}

		for (int i=0; i<X; i++) {
			dp[x][i+1][1] = old[i];
		}
	}

	// uzimam vise od K
	// uzimam tacno K
	{
		mint knap[2][11];

		knap[0][0] = 1;

		auto old = knap[0];
		auto nu = knap[1];

		for (int y : e[x]) if (y != p) {

			for (int j=0; j<=X; j++) {
				nu[j] = 0;
			}

			for (int amt=0; amt<=X; amt++) {
				for (int novo=amt; novo<=X; novo++) {
					nu[novo] += old[novo-amt] * dp[y][amt][0];
					nu[novo] += old[novo-amt] * dp[y][amt][2];
				}
			}

			swap(old, nu);
		}

		for (int i=0; i<=X; i++) {
			dp[x][i][2] = old[i] * (M - K);
		}
	}

}

typedef unsigned long long ull;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> N >> M;
	for (int i=1; i<N; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	cin >> K >> X;

	dfs(1, 1);


	mint sol = 0;
	for (int i=0; i<=X; i++) {
		sol += dp[1][i][0] + dp[1][i][1] + dp[1][i][2];
	}

	cout << (ull)sol;
}