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

ll satmul(ll x, ll y) {
	if (x * 1.0 * y > 1e18) return 1e18;
	return x * y;
}

ll satpow(ll x, ll e) {
	if (e == 0) return 1;
	ll q = satpow(x, e >> 1);
	q = satmul(q, q);
	if (e & 1) q = satmul(q, x);
	return q;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, p;
		cin >> n >> p;
		vector<int> a(n);
		for (int& x : a) cin >> x;
		sort(begin(a), end(a), greater<int>());

		ll t = -1, c = 0;
		mint diff;

		for (int x : a) {
			if (t == -1) {
				t = x;
				c = 1;
				diff = mint(p) ^ t;
			} else {

				if (t > x) {
					c = satmul(c, satpow(p, t-x));
					t = x;
				}

				if (c > 0) {
					c--;

					diff -= mint(p) ^ t;

					if (c == 0) {
						t = -1;
					}
				} else {

					diff += mint(p) ^ t;

					c++;
				}
			}
		}

		cout << diff() << '\n';
	}
}