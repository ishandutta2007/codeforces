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


struct fenw1 {
	vector<ll> a;

	fenw1() : a(262144, 0) {}

	void add(int p, ll x) {
		for (; p<262144; p+=p&-p) a[p] += x;
	}

	ll get(int p) const {
		ll z = 0;
		for (; p; p-=p&-p) z += a[p];
		return z;
	}

	// prvo mesto gde je suma >= z
	int lower_bound(ll z) const {
		int j = 0;
		for (int i=17; i>=0; i--) {
			if (a[j + (1 << i)] * 2 < z)
				z -= a[j += (1 << i)] * 2;
		}
		return j + 1;
	}
} drvo1;

struct fenw2 {
	vector<mint> a;

	fenw2() : a(262144, 0) {}

	void add(int p, mint x) {
		for (; p<262144; p+=p&-p) a[p] += x;
	}

	mint get(int p) const {
		mint z = 0;
		for (; p; p-=p&-p) z += a[p];
		return z;
	}

} drvo2;

int n, q;
int a[200005];
int w[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] -= i;
	}

	for (int i=1; i<=n; i++) {
		cin >> w[i];
		drvo1.add(i, w[i]);
		drvo2.add(i, a[i] * 1ll * w[i]);
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l > 0) {
			ll s3 = drvo1.get(r);
			ll s1 = drvo1.get(l-1);
			int i = drvo1.lower_bound(s1 + s3);
			ll s2 = drvo1.get(i);

			// cerr << s1 << ' ' << s3 << ' ' << '\n';
			// cerr << l << ' ' << r << ' ' << i << '\n';

			ll wlevo = s2 - s1;
			ll wdesno = s3 - s2;

			// cerr << wlevo << ' ' << wdesno << " wd\n";

			mint pp = drvo2.get(l-1);
			mint qq = drvo2.get(i);
			mint rr = drvo2.get(r);

			mint awlevo = qq - pp;
			mint awdesno = rr - qq;

			// cerr << (int)awlevo << ' ' << (int)awdesno << " aw\n";

			mint sol = mint(a[i]) * wlevo - awlevo;
			sol += awdesno - mint(a[i]) * wdesno;

			cout << (int)sol << '\n';

		} else {
			l = -l;
			drvo1.add(l, r - w[l]);
			drvo2.add(l, a[l] * 1ll * (r - w[l]));
			w[l] = r;
		}
	}
}