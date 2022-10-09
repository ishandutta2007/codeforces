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

const int mod = 998244353;
typedef modint<mod> mint;

mint d[1000005][4];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;

	d[0][0] = 1;

	mint i2 = mint(2).inv();
	mint i6 = mint(6).inv();

	for (int i=1; i<=n; i++) {
		mint p = d[i-1][0] + d[i-1][1] + d[i-1][2];
		d[i][0] = 1;
		d[i][1] = p;
		d[i][2] = p*(p+1)*i2;
		d[i][3] = p*(p+1)*(p+2)*i6;
	}

	mint nrm = d[n][1] + d[n][2] + d[n][3] - d[n-1][1] - d[n-1][2] - d[n-1][3];
	nrm = nrm * 2 - 1;
	mint sol = nrm;

	mint rs = 0;
	for (int i=1; i<=n-2; i++) {
		int j = n-1-i;
		rs += d[i][2] - d[i-1][2];
		sol += rs * (d[j][2] - d[j-1][2]);
	}

	cout << sol() << '\n';
}