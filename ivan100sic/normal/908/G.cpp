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

const int n = 703;
string s;
int c[10];
mint sol;

mint choices[10][705][705];
mint czs[10][705][705];
// koliko nizova duzine y ima z elemenata vrednosti 0..x
// prefiksna suma (incl)

mint daj() {
	mint z = 0;
	int fri = n - accumulate(c, c+10, 0);
	for (int i=0; i<n; i++) {
		int il = 0;
		mint t = 0;
		for (int j=1; j<10; j++) {
			il += c[j-1];
			int bar = i - il;
			if (bar >= 0)
				t += czs[j-1][fri][bar];
		}
		z += t * (mint(10) ^ (n-i-1));
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<10; i++) {
		choices[i][0][0] = 1;
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				choices[i][j+1][k+1] += choices[i][j][k] * (i+1);
				choices[i][j+1][k+0] += choices[i][j][k] * (9-i);
			}
		}

		for (int j=0; j<n; j++) {
			czs[i][j][0] = choices[i][j][0];
			for (int k=1; k<=n; k++) {
				czs[i][j][k] = czs[i][j][k-1] + choices[i][j][k];
			}
		}
	}

	cin >> s;
	if (s == string(s.size(), '9'))
		s = string("1") + string(s.size(), '0');
	else {
		int j = s.size() - 1;
		while (1) {
			if (s[j] == '9') {
				s[j] = '0';
				j--;
			} else {
				s[j]++;
				break;
			}
		}
	}

	while (s.size() < n)
		s = string("0") + s;

	for (int i=0; i<n; i++) {
		for (int j=0; j<s[i]-'0'; j++) {
			c[j]++;
			sol += daj();
			c[j]--;
		}
		c[s[i]-'0']++;
	}	

	cout << (int)sol << '\n';
}