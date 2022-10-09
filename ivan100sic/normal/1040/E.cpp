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
		x = (x * 1ll * other.x) % m;
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

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

mint p[500005], sol;
int n, m, k;
ll a[500005];
map<ll, vector<pair<int, int>> > mp;

struct dsu {
	vector<int> p, s, ch;
	int cc, n;

	dsu(int n) : p(n), s(n), cc(n), n(n) {
		iota(p.begin(), p.end(), 0);
		fill(s.begin(), s.end(), 1);
	}

	void reset() {
		for (int x : ch) {
			p[x] = x;
			s[x] = 1;
		}
		cc = n;
		ch.clear();
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	void merge(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return;
		ch.push_back(x);
		ch.push_back(y);
		if (s[x] > s[y])
			swap(x, y);
		p[x] = y;
		s[y] += s[x];
		cc--;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		mp[a[x] ^ a[y]].push_back({x, y});
	}

	dsu d(n);

	p[0] = 1;
	for (int i=1; i<=n; i++)
		p[i] = p[i-1] + p[i-1];

	for (auto p : mp) {
		d.reset();
		for (auto e : p.second)
			d.merge(e.first, e.second);
		sol += ::p[d.cc];
	}
	sol += p[n] * ((1ll << k) - mp.size());
	cout << (int)sol << '\n';
}