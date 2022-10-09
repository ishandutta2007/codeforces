// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update>
	ordered_set;
// find_by_order(size_t) -> iterator, order_of_key(val) -> size_t

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

template<class T = mint>
struct binomial {
	vector<T> f, finv;

	binomial(int n) : f(n), finv(n) {
		f[0] = finv[0] = 1;
		for (int i=1; i<n; i++) {
			f[i] = f[i-1] * i;
			finv[i] = f[i].inv();
		}
	}

	mint mix(int a, int b) {
		if (a < 0 || b < 0)
			return 0;
		return f[a+b] * finv[a] * finv[b];
	}

	mint choose(int n, int k) {
		return mix(n-k, k);
	}
};

struct seg {
	int l, r;

	template<class T>
	auto operator< (const T& b) const {
		return l < b.l;
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, k;
	cin >> n >> k;

	vector<seg> a(n);
	for (int i=0; i<n; i++) {
		cin >> a[i].l >> a[i].r;
	}

	sort(begin(a), end(a));
	binomial bk(600005);

	ordered_set os;

	mint sol = 0;

	for (int i=0; i<n; i++) {
		int c = i - os.order_of_key({a[i].l, -1});
		sol += bk.choose(c, k-1);
		os.insert({a[i].r, i});
	}

	cout << sol() << '\n';

}