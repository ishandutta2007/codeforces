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

int n, d;
vector<int> e[3005];
mint dp[3005][3005];

void dfs(int x) {
	for (int i=1; i<=n+1; i++)
		dp[x][i] = 1;
	for (int y : e[x]) {
		dfs(y);
		for (int i=1; i<=n+1; i++)
			dp[x][i] *= dp[y][i];
	}

	for (int i=1; i<=n+1; i++)
		dp[x][i] += dp[x][i-1];
}

map<int, mint> invv;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> d;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		e[x].push_back(i);
	}

	dfs(1);

	mint sol = 0;

	for (int i=-4004; i<=4004; i++) 
		if (i)
			invv[i] = mint(i).inv();

	for (int i=1; i<=n+1; i++) {
		mint prod = 1;
		for (int j=1; j<=n+1; j++)
			if (j != i)
				prod *= mint(d - j) * invv[i-j];
		sol += dp[1][i] * prod;
	}

	cout << (int)sol << '\n';
}