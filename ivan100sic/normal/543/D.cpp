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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

int n;
int p[200005];
basic_string<int> e[200005];
mint dn[200005], up[200005];

void dfs1(int x) {
	mint p = 1;
	for (int y : e[x]) {
		dfs1(y);
		p *= dn[y];
	}
	dn[x] = p + 1;
}

void dfs2(int x) {
	vector<mint> val, pref, suff;
	for (int y : e[x])
		val.push_back(dn[y]);
	int k = e[x].size();
	mint z = 1;
	pref = {z};
	for (int i=0; i<k; i++) {
		z *= val[i];
		pref.push_back(z);
	}
	z = 1;
	suff = {z};
	for (int i=k-1; i>=0; i--) {
		z *= val[i];
		suff.push_back(z);
	}

	z = (x == 1 ? 1 : up[x]);
	for (int i=0; i<k; i++) {
		int y = e[x][i];
		up[y] = z * pref[i] * suff[k-i-1] + 1;
	}

	for (int y : e[x]) {
		dfs2(y);
	}
}

int ans(int x) {
	mint p = 1;
	for (int y : e[x])
		p *= dn[y];
	if (x != 1)
		p *= up[x];
	return (int)p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++) {
		cin >> p[i];
		e[p[i]] += i;
	}

	dfs1(1);
	dfs2(1);

	for (int i=1; i<=n; i++)
		cout << ans(i) << " \n"[i == n];
}