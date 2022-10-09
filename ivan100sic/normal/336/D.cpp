// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

char sim(string s) {
	char c = s[0];
	for (int i=1; i<(int)s.size(); i++) {
		if (c == s[i] && c == '0')
			c = '1';
		else
			c = '0';
	}
	return c;
}

int brut(int n, int m, int g) {
	int k = n + m, z = 0;
	for (int mask=0; mask<(1<<k); mask++) {
		string s;
		for (int i=0; i<k; i++) {
			if (mask & (1 << i))
				s += '1';
			else
				s += '0';
		}
		if (__builtin_popcount(mask) == m && sim(s) - '0' == g)
			z++;
	}
	return z;
}

mint f[200005], finv[200005];

mint bk(int a, int b) {
	return f[a+b] * finv[a] * finv[b];
}

int solve(int n, int m, int g) {
	if (m == 0)
		return n % 2 == 1 - g;
	if (m == 1) {
		int g0 = n % 2 == 0 ? n / 2 : n / 2 + 2;
		return g == 0 ? g0 : n+1 - g0;
	}
	mint sol = 0;
	for (int x=0; x<=n; x++)
		if (x % 2 == g)
			sol += bk(n-x, m-1);
	return (int)sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<200005; i++)
		f[i] = f[i-1] * i, finv[i] = f[i].inv();

	for (int a=0; a<=5; a++)
		for (int b=(a==0); b<=5; b++)
			for (int g=0; g<1; g++) {
				int x = brut(a, b, g);
				int y = solve(a, b, g);
				if (x != y)
					cerr << a << ' ' << b << ' ' << g << ' ' << x << ' ' << y << '\n';
			}
	for (int a=0; a<=5; a++)
		for (int b=(a==0); b<=5; b++)
			for (int g=0; g<2; g++)
				cerr << (brut(a, b, g) == solve(a, b, g));
	cerr << '\n';
	cerr << brut(1, 1, 0) << '\n';
	cerr << brut(2, 2, 0) << '\n';
	cerr << brut(1, 1, 1) << '\n';
	cerr << '\n';
	cerr << solve(1, 1, 0) << '\n';
	cerr << solve(2, 2, 0) << '\n';
	cerr << solve(1, 1, 1) << '\n';

	int n, m, g;
	cin >> n >> m >> g;
	cout << solve(n, m, g) << '\n';
}

// I will still practice daily...