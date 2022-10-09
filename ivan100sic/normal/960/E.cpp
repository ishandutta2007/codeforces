#include <bits/stdc++.h>
#ifdef LOCAL
#define dbg(x) (cerr << "ln " << __LINE__ << ": " << #x << " = " << (x) << '\n')
#else
#define dbg(x) {}
#endif
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

struct rez {
	mint up0s, up1s, dns, up0c, up1c, dnc;
};

int n;
basic_string<int> e[200005];
mint a[200005], sol;

rez dfs(int x, int p) {
	vector<rez> v;

	mint up0s, up1s, dns;
	mint up0c, up1c, dnc;

	for (int y : e[x]) {
		if (y != p) {
			auto r = dfs(y, x);
			v.push_back(r);
			
			up0s += r.up0s;
			up1s += r.up1s;
			dns += r.dns;

			up0c += r.up0c;
			up1c += r.up1c;
			dnc += r.dnc;
		}
	}

	for (auto r : v) {
		mint dnc_ostali = dnc - r.dnc;
		mint dns_ostali = dns - r.dns;

		dbg((int)sol);
		
		// up0 + dn ostalih
		sol += r.up0s * dnc_ostali - r.up0c * dns_ostali;
		sol += dnc_ostali * r.up0c * a[x];

		dbg((int)sol);

		// up1 + dn ostalih
		sol += r.up1s * dnc_ostali + r.up1c * dns_ostali;
		sol -= dnc_ostali * r.up1c * a[x];

		dbg((int)sol);

		// samo na gore do root-a
		sol += r.up0s + a[x] * r.up0c;
		sol += r.up1s - a[x] * r.up1c;

		dbg((int)sol);

		// samo na dole od root-a
		sol += a[x] * r.dnc - r.dns;

		dbg((int)sol);
	}

	// ja bato
	sol += a[x];
		
	dbg((int)sol);
	
	return {
		up1s - up1c * a[x],
		up0s + up0c * a[x] + a[x],
		a[x] * dnc - dns + a[x],
		up1c,
		up0c + 1,
		dnc + 1,
	};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[i] = x;
	}
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs(1, 1);
	cout << (int)sol << '\n';
}