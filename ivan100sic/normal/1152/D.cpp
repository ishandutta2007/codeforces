#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

namespace brut {
	ll dp[105][105][2];
	bool solved[105][105];

	void solve(int n, int k) {
		if (solved[n][k])
			return;
		solved[n][k] = true;
		ll& d0 = dp[n][k][0];
		ll& d1 = dp[n][k][1];

		bool otv = n-1 >= 0 && n-1-(k+1) >= 0;
		bool zatv = n-1 >= 0 && k-1 >= 0;

		if (otv) solve(n-1, k+1);
		if (zatv) solve(n-1, k-1);

		if (otv && zatv) {
			d0 = max(dp[n-1][k+1][0], dp[n-1][k+1][1])
			   + max(dp[n-1][k-1][0], dp[n-1][k-1][1]);
			d1 = max(
				dp[n-1][k+1][0] + max(dp[n-1][k-1][0], dp[n-1][k-1][1]),
				dp[n-1][k-1][0] + max(dp[n-1][k+1][0], dp[n-1][k+1][1])
			) + 1;
		} else if (otv) {
			d0 = max(dp[n-1][k+1][0], dp[n-1][k+1][1]);
			d1 = dp[n-1][k+1][0] + 1;
		} else if (zatv) {
			d0 = max(dp[n-1][k-1][0], dp[n-1][k-1][1]);
			d1 = dp[n-1][k-1][0] + 1;
		} else {
			d0 = d1 = 0;
		}
	}
}

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

namespace nochoice {
	typedef mint T;

	T dp[2005][2005][2];
	bool solved[2005][2005];

	void solve(int n, int k) {
		if (solved[n][k])
			return;
		solved[n][k] = true;
		T& d0 = dp[n][k][0];
		T& d1 = dp[n][k][1];

		bool otv = n-1 >= 0 && n-1-(k+1) >= 0;
		bool zatv = n-1 >= 0 && k-1 >= 0;

		if (otv) solve(n-1, k+1);
		if (zatv) solve(n-1, k-1);

		if (otv && zatv) {
			d0 = dp[n-1][k+1][1] + dp[n-1][k-1][1];
			/*
			d1 = max(
				dp[n-1][k+1][0] + dp[n-1][k-1][1],
				dp[n-1][k-1][0] + dp[n-1][k+1][1]
			) + 1;
			*/
			d1 = dp[n-1][k-1][0] + dp[n-1][k+1][1] + 1;
		} else if (otv) {
			d0 = dp[n-1][k+1][1];
			d1 = dp[n-1][k+1][0] + 1;
		} else if (zatv) {
			d0 = dp[n-1][k-1][1];
			d1 = dp[n-1][k-1][0] + 1;
		} else {
			d0 = d1 = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	using namespace nochoice;

	int n;
	cin >> n;
	solve(2*n, 0);
	cout << (int)dp[2*n][0][1] << '\n';
}