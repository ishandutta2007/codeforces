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

const int MOD = 1'000'000'009;
typedef modint<MOD> mint;

const int PHI1 = 691504013;
const int PHI2 = 308495997;
const int SQRT5INV = 276601605;
const int MAXN = 524288;

template<int PHI>
struct segtree {
	mint a[2*MAXN], b[2*MAXN];
	mint geom[50], step[50];
	mint pows[2*MAXN];

	segtree() {
		for (int i=0; i<=19; i++) {
			geom[i] = ((mint(PHI) ^ (1<<i)) - 1) * mint(PHI-1).inv();
			if (i)
				step[i] = mint(PHI) ^ (1<<(i-1)); 
		}
		pows[0] = 1;
		for (int i=1; i<2*MAXN; i++) {
			pows[i] = pows[i-1] * PHI;
		}
	}

	void push(int x, int lvl) {
		if (b[x] == 0)
			return;
		if (x < MAXN) {
			b[2*x] += b[x];
			b[2*x+1] += b[x] * step[lvl];
		}
		a[x] += b[x] * geom[lvl];
		b[x] = 0;
	}

	void update(int l, int r, int x=1, int lvl=19, int xl=0, int xr=MAXN-1) {
		if (r < xl || xr < l) {
			push(x, lvl);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x] += pows[xl-l+1];
			push(x, lvl);
			return;
		}
		push(x, lvl);
		int xm = (xl+xr) >> 1;
		update(l, r, 2*x, lvl-1, xl, xm);
		update(l, r, 2*x+1, lvl-1, xm+1, xr);
		a[x] = a[2*x] + a[2*x+1];
	}

	mint query(int l, int r, int x=1, int lvl=19, int xl=0, int xr=MAXN-1) {
		push(x, lvl);
		if (r < xl || xr < l)
			return 0;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return query(l, r, 2*x, lvl-1, xl, xm)
			+ query(l, r, 2*x+1, lvl-1, xm+1, xr);
	}
};

segtree<PHI1> d1;
segtree<PHI2> d2;

int a[300005], z[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = (z[i-1] + a[i]) % MOD;
	}
	while (q--) {
		int t, l, r;
		cin >> t >> l >> r;
		if (t == 1)
			d1.update(l, r), d2.update(l, r);
		else {
			mint w = (d1.query(l, r) - d2.query(l, r)) * SQRT5INV + z[r] - z[l-1];
			cout << (int)w << '\n';
		}
	}
}