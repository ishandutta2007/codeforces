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

struct sieve {
	const int maxn;
	vector<int> f, primes;

	sieve(int maxn) : maxn(maxn), f(maxn) {
		for (int i=2; i<maxn; i++) {
			if (f[i] == 0) {
				f[i] = i;
				primes.push_back(i);
			}

			for (int p : primes) {
				if (p > f[i] || i * p >= maxn) {
					break;
				}

				f[i*p] = p;
			}
		}
	}

 	auto factor_small(int x) const {
		vector<pair<int, int>> v;
		while (x > 1) {
			int p = f[x], c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.emplace_back(p, c);
		}
		return v;
	}

	template<class T>
	auto factor(T x) const {
		vector<pair<T, int>> v;
		for (int p : primes) {
			if ((ll)p*p > x) {
				break;
			}

			if (x % p == 0) {
				int c = 0;
				while (x % p == 0) {
					x /= p;
					c++;
				}
				v.emplace_back(p, c);
			}
		}

		if (x > 1) {
			v.emplace_back(x, 1);
		}

		return v;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	sieve s(sqrt(1e15) + 5);
	ll d;
	cin >> d;
	auto v = s.factor(d);
	int m = v.size();

	vector<int> q(m+1);
	q[0] = 1;
	for (int i=0; i<m; i++)
		q[i+1] = q[i] * (v[i].second + 1);

	vector<mint> dp(q[m]);
	cerr << m << ' ' << q[m] << '\n';
	dp[0] = 1;

	for (int i=0; i<q[m]; i++) {
		int t = i;
		for (int j=0; j<m; j++) {
			int r = t % (v[j].second + 1);
			t /= v[j].second + 1;

			if (r < v[j].second) {
				dp[i + q[j]] += dp[i];
			}
		}
	}

	auto ch = [&](ll x) {
		vector<int> r(m);
		for (int i=0; i<m; i++) {
			int c = 0;
			while (x % v[i].first == 0) {
				x /= v[i].first;
				c++;
			}
			r[i] = c;
		}
		return r;
	};

	auto resi = [&](ll x, ll y) {
		auto a = ch(x), b = ch(y);
		if (a > b)
			swap(a, b);
		int t = 0;
		for (int i=0; i<m; i++)
			t += (b[i] - a[i]) * q[i];
		return dp[t];
	};

	int qt;
	cin >> qt;
	while (qt--) {
		ll x, y;
		cin >> x >> y;
		ll z = gcd(x, y);
		cout << (resi(x, z) * resi(y, z))() << '\n';
	}
}