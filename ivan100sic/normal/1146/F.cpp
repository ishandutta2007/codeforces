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

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 998'244'353;
typedef modint<MOD> mint;

int n;
basic_string<int> e[200005];
mint sa[200005], bez[200005];

void dfs(int x) {
	if (e[x].size() == 0) {
		sa[x] = bez[x] = 1;
		return;
	}
	for (int y : e[x])
		dfs(y);
	mint p0 = 1, p1 = 0, p2 = 0;
	for (int y : e[x]) {
		mint q0 = p0 * bez[y];
		mint q1 = p0 * sa[y] + p1 * bez[y];
		mint q2 = p1 * sa[y] + p2 * bez[y] + p2 * sa[y];

		p0 = q0;
		p1 = q1;
		p2 = q2;
	}
	bez[x] = p0 + p2;
	sa[x] = p1 + p2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		e[x] += i;
	}
	dfs(1);
	cout << (int)bez[1] << '\n';
	// for (int i=1; i<=n; i++) {
	// 	cerr << i << ' ' << (int)sa[i] << ' ' << (int)bez[i] << '\n';
	// }
	// cerr << '\n';
}