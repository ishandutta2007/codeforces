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

struct polje {
	int x, y;
	bool operator< (const polje& o) const {
		return x+y < o.x+o.y;
	}
};

mint f[200005], finv[200005];

mint bk(int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	return f[x + y] * finv[x] * finv[y];
}

int n, m, k;
polje a[2005];
mint w[2005]; // g = gazim

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<200005; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}

	cin >> n >> m >> k;
	for (int i=1; i<=k; i++)
		cin >> a[i].x >> a[i].y;

	a[0] = {1, 1};
	a[k+1] = {n, m};
	sort(a+1, a+k+1);

	w[0] = 1;
	for (int j=1; j<=k+1; j++) {
		mint g = bk(a[j].x - a[0].x, a[j].y - a[0].y);
		for (int k=1; k<j; k++) {
			g -= w[k] * bk(a[j].x - a[k].x, a[j].y - a[k].y);
		}
		w[j] = g;
	}
	cout << (int)w[k+1] << '\n';
}