#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

ll n, m, d;

struct state {
	ll c, msk, cnt;

	template<class T>
	auto operator< (const T& b) const {
		return tie(c, msk) < tie(b.c, b.msk);
	}
};

ll g[60];
void gadd(ll x) {
	for (int i=0; i<m; i++) {
		if (x & (1ll << (m-1-i))) {
			if (!g[i]) {
				g[i] = x;
				d++;
				return;
			} else {
				x ^= g[i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		gadd(x);
	}

	for (int i=m-1; i>=0; i--) {
		if (g[i]) {
			for (int j=i-1; j>=0; j--) {
				if (g[j] & (1ll << (m-1-i))) {
					g[j] ^= g[i];
				}
			}
		}
	}

	vector<ll> b;
	for (int i=0; i<m; i++) {
		if (g[i]) {
			b.push_back(g[i]);
		}
	}

	vector<state> dp = {{0, 0, 1}};

	for (ll x : b) {
		vector<state> tmp;
		ll hi = 1ll << (63 - __builtin_clzll(x));
		for (auto [c, msk, cnt] : dp) {
			tmp.push_back({c + __builtin_popcountll(   msk  & ~(hi-1)),     msk & (hi-1), cnt});
			tmp.push_back({c + __builtin_popcountll((x^msk) & ~(hi-1)), (msk^x) & (hi - 1), cnt});
		}

		sort(begin(tmp), end(tmp));
		dp.clear();
		for (auto [c, msk, cnt] : tmp) {
			if (dp.size() && dp.back().c == c && dp.back().msk == msk) {
				dp.back().cnt += cnt;
			} else {
				dp.push_back({c, msk, cnt});
			}
		}
	}

	mint sol[55];
	for (auto [c, msk, cnt] : dp) {
		sol[c + __builtin_popcountll(msk)] += cnt;
	}

	mint mul = mint(2) ^ (n-d);
	for (int i=0; i<=m; i++)
		cout << (mul * sol[i])() << " \n"[i == m];
}