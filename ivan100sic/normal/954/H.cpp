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

const int mod = 1'000'000'007;
typedef modint<mod> mint;

int n;
mint a[5005], b[5005];
mint sol[10005];

typedef double reale;
typedef complex<reale> cd;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	b[0] = 1;
	for (int i=0; i<n-1; i++) {
		int x;
		cin >> x;
		a[i] = x;
		b[i+1] = b[i] * a[i];
	}

	vector<mint> pn2 = {1}, pn = {1};

	for (int i=n-2; i>=0; i--) {
		mint mul = a[i] * (a[i] - 1) * mint(2).inv() * b[i];
		for (int j=0; j<(int)pn2.size(); j++)
			sol[j+2] += mul * pn2[j];

		for (mint& x : pn)
			x *= a[i];
		pn.insert(pn.begin(), mint(1));

		mul = a[i] * a[i];
		for (mint& x : pn2)
			x *= mul;
		pn2.insert(pn2.begin(), mint(0));
		pn2.insert(pn2.begin(), mint(-1));
		for (int i=0; i<(int)pn.size(); i++)
			pn2[i] += pn[i] + pn[i];

		mul = b[i];
		for (int j=0; j<(int)pn.size(); j++)
			sol[j] += mul * pn[j];
	}

	for (int i=1; i<=2*n-2; i++)
		cout << sol[i]() << " \n"[i == 2*n-2];
}