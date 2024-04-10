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

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll a, b;
	cin >> a >> b;

	ll t = (a+1)*(b+1);
	// sve
	mint sol = mint(t) * (t-1) * (t-2);

	// izbaci kolinearne
	for (ll x=1; x<=a; x++) {
		for (ll y=1; y<=b; y++) {
			ll g = gcd(x, y);
			ll u = g-1;

			sol -= mint(u) * 12 * (a-x+1) * (b-y+1);
		}
	}

	sol -= mint(a+1) * (b+1) * b * (b-1);
	sol -= mint(b+1) * (a+1) * a * (a-1);

	ll px[2] = {a+1 - (a+1)/2, (a+1)/2};
	ll py[2] = {b+1 - (b+1)/2, (b+1)/2};

	for (int ax : {0, 1})
	for (int bx : {0, 1})
	for (int cx : {0, 1})
	for (int ay : {0, 1})
	for (int by : {0, 1})
	for (int cy : {0, 1})
	{
		if ((ax*by + bx*cy + cx*ay + ay*bx + by*cx + cy*ax) % 2) {
			mint p = 1;
			p *= px[ax];
			p *= px[bx];
			p *= px[cx];
			p *= py[ay];
			p *= py[by];
			p *= py[cy];
			sol -= p;
		}
	}

	cout << sol() << '\n';
}