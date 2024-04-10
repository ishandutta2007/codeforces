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

const int MOD = 998244353;
typedef modint<MOD> mint;

int n, k, len;
int a[100005], seen[105], seen_pref[105], seen_suff[105];
mint dp[100005][105], z[100005][105];

int get_razl(int i) {
	if (i == 0)
		return seen_suff[1];
	else if (i == k)
		return seen_pref[k-1];
	else
		return max(seen_pref[i-1], seen_suff[i+1]);
}

mint get_range(int x, int l, int r) {
	if (l <= 0)
		return z[r][x];
	else
		return z[r][x] - z[l-1][x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> len;
	len--;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	dp[0][0] = 1;
	for (int i=1; i<=n; i++) {
		// dodaj trenutnu barijeru
		if (a[i-1] == -1 && a[i] == -1) {
			mint zbir_svih = 0;
			for (int j=0; j<=k; j++)
				zbir_svih += dp[i-1][j];
			for (int j=0; j<=k; j++) {
				z[i-1][j] = zbir_svih - dp[i-1][j];
			}
		} else if (a[i-1] == -1 && a[i] != -1) {
			mint zbir_svih = 0;
			for (int j=0; j<=k; j++)
				zbir_svih += dp[i-1][j];
			{
				int j = a[i];
				z[i-1][j] = zbir_svih - dp[i-1][j];
			}
		} else if (a[i-1] != -1 && a[i] == -1) {
			mint zbir_svih = dp[i-1][a[i-1]];
			for (int j=0; j<=k; j++) {
				if (j == a[i-1])
					continue;
				z[i-1][j] = zbir_svih;
			}
		} else if (a[i-1] != a[i]) {
			z[i-1][a[i]] = dp[i-1][a[i-1]];
		}

		// prefiks
		if (i > 1)
			for (int j=0; j<=k; j++)
				z[i-1][j] += z[i-2][j];

		int lo = a[i];
		int hi = a[i];
		if (a[i] == -1) {
			lo = 1;
			hi = k;
		}

		for (int j=lo; j<=hi; j++) {
			int razl = get_razl(j);
			dp[i][j] = get_range(j, max(razl, i-len), i-1);
		}

		if (a[i] != -1) {
			seen[a[i]] = i;
			seen_pref[0] = seen[0];
			for (int i=1; i<=k; i++)
				seen_pref[i] = max(seen_pref[i-1], seen[i]);
			seen_suff[k] = seen[k];
			for (int i=k-1; i>=0; i--)
				seen_suff[i] = max(seen_suff[i+1], seen[i]);
		}
	}

	mint sol;
	for (int j=1; j<=k; j++)
		sol += dp[n][j];
	cout << (int)sol << '\n';
}