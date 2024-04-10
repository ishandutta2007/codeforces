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

const int MOD = 998244353;
typedef modint<MOD> mint;

ostream& operator<< (ostream& os, mint x) {
	return os << (int)x;
}

struct stanje {
	mint sa_broj, bez_broj;
	mint sa_zbir, bez_zbir;
};

int n;
basic_string<int> e[500005];
stanje d[500005];

struct binom {
	mint i, x, y, xy;

	binom() : i(1), x(0), y(0), xy(0) {}

	binom(mint i, mint x, mint y, mint xy=0) : i(i), x(x), y(y), xy(xy) {}

	binom operator* (const binom& b) const {
		return {
			i*b.i,
			i*b.x + x*b.i + x*b.x,
			i*b.y + y*b.i,
			i*b.xy + xy*b.i + x*b.y + y*b.x + x*b.xy + xy*b.x
		};
	}
};

void dfs(int x, int p) {
	binom zb;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
		zb = zb * binom(
			d[y].sa_broj + d[y].sa_broj + d[y].bez_broj,
			d[y].bez_broj,
			d[y].sa_zbir + d[y].sa_zbir + d[y].bez_zbir,
			d[y].bez_zbir
		);
	}

	d[x].bez_broj = zb.i;
	d[x].sa_broj = zb.x;
	d[x].bez_zbir = zb.y;
	d[x].sa_zbir = zb.xy + zb.x;
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

	// for (int x=1; x<=n; x++) {
	// 	cerr << x << ": " << d[x].bez_broj << ' ' << d[x].sa_broj <<
	// 		          ' ' << d[x].bez_zbir  << ' ' << d[x].sa_zbir << '\n';
	// }

	cout << (d[1].sa_zbir + d[1].bez_zbir)*2 << '\n';
}