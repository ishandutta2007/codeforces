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

/*
	flipujemo vrednosti grana
	svaki trougao mora da ima xor = 2
	sledi da svaki ciklus mora da ima xor = 0

	neka su grane iz cvora 1 ka ostalim cvorovima e2, e3, e4, ...

	sta mora da vazi?

	eij = ei ^ ej
*/

int n, m, bad;
basic_string<pair<int, int>> e[100005];
int v[100005], d[100005];

void dfs(int x) {
	v[x] = 1;
	for (auto [y, w] : e[x]) {
		int& v1 = d[y];
		int v2 = d[x] ^ w;
		if (v[y] && v1 != v2)
			bad = 1;
		else if (!v[y]) {
			v1 = v2;
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int cc = 0;
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		w ^= 1;
		e[u] += {v, w};
		e[v] += {u, w};
	}

	for (int i=1; i<=n; i++) {
		if (v[i] == 0) {
			dfs(i);
			cc++;
		}
	}

	cout << (int)(mint(2) ^ (cc - 1)) * (1 - bad) << '\n';
}