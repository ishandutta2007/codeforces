// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

const int H = 100000;

int c[H+1];
int u[H+1];
mint i2 = mint(2).inv();

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	u[1] = 1;
	for (int i=1; i<=H; i++) {
		for (int j=2*i; j<=H; j+=i) {
			u[j] -= u[i];
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		c[x] = y;
	}

	mint sol = 0;
	for (int i=1; i<=H; i++) {
		mint ssq = 0;
		mint c2 = 0;
		mint s = 0;
		ll n = 0;
		for (int j=i; j<=H; j+=i) {
			mint w = c[j];
			ssq += w*j*j;
			c2 += s*j*w + w*(w-1)*i2*j*j;
			s += w*j;
			n += c[j];
		}

		if (n < 2) continue;

		mint pw = mint(2) ^ (n-2);

		sol += pw * (ssq * (n-1) + c2 * n) * u[i];
	}

	cout << sol() << '\n';
}