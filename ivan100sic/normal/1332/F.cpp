// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
		x = (x * 1ull * other.x) % m;
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

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 998244353; // ovo je maltretiranje vise
typedef modint<MOD> mint;

int n;
basic_string<int> e[300005];

template<class T>
struct por {
	T x, y;

	por operator+ (const por& b) const {
		return {x + b.x, y + b.y};
	}

	por operator* (const por& b) const {
		return {x * b.x, x * b.y + y * b.x + y * b.y};
	}
};

typedef por<por<mint>> rez;
// [neprazna komponenta u root-u] [uzet cvor u ind set u korenu]

rez d[300005];

void dfs(int x, int p) {
	rez r;
	r.x.x = 1;

	for (int v : e[x]) {
		if (v == p)
			continue;
		dfs(v, x);
		rez t, f = d[v];
		// uzmi granu
		t.y = f.x + f.y;
		// ne uzimaj granu
		t.x.x = f.x.x + f.y.x + f.y.y;
		r = r * t;
	}

	rez w;
	// samo nakaci cvor gore bez uzimanja
	w.x.x = r.x.x + r.x.y;
	w.y.x = r.y.x + r.y.y;
	// nakaci cvor gore
	w.x.y = r.x.x;
	w.y.y = r.y.x;
	// zapisi
	d[x] = w;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs(1, 1);
	cout << (int)(d[1].x.x + d[1].y.x + d[1].y.y - 1) << '\n';
}

// I will still practice daily...