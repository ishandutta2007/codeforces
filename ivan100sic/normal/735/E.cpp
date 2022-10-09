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

basic_string<int> e[105];
int n, k;

mint dp[105][45];

void dfs(int x, int p) {
	vector<vector<mint>> d(2*k+1, vector<mint>(2*k+1, 0));
	d[2*k][0] = 1;

	int c = 0;
	for (int y : e[x]) {
		if (y == p)
			continue;
		c++;
		dfs(y, x);
		vector<vector<mint>> d2(2*k+1, vector<mint>(2*k+1, 0));
		for (int j=0; j<=2*k; j++) {
			for (int a=0; a<=2*k; a++) {
				for (int b=0; b<=2*k; b++) {
					d2[min(a, j)][max(b, j)] += d[a][b] * dp[y][j];
				}
			}
		}
		swap(d, d2);
	}

	if (!c) {
		dp[x][0] = dp[x][k+1] = 1;
	} else if (c == 1) {
		for (int a=0; a<=2*k; a++) {
			dp[x][0] += d[a][a];
			dp[x][a+1] += d[a][a];			
		}
	} else {
		for (int a=0; a<=2*k; a++) {
			for (int b=a; b<=2*k; b++) {
				int c = (a+b <= 2*k-1 ? a+1 : b+1);
				dp[x][0] += d[a][b];
				dp[x][c] += d[a][b];			
			}
		}
	}

	// dp[x][2*k+1] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs(1, 1);
	cout << (int)accumulate(dp[1]+0, dp[1]+k+1, mint(0)) << '\n';
}