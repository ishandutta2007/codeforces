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

const int MOD = 998244353;
typedef modint<MOD> mint;

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<int, 200005> drvo;

int n;
int a[200005], c[200005];
basic_string<int> fale;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	mint sol;
	int rupe = 0;

	for (int i=1; i<=n; i++) {
		if (a[i] != -1) {
			c[a[i]] = i;
			sol += drvo.sum(n) - drvo.sum(a[i]-1);
			drvo.add(a[i], 1);
		} else {
			rupe++;
		}
	}

	sol += mint(4).inv() * rupe * (rupe - 1);

	for (int i=1; i<=n; i++)
		if (c[i] == 0)
			fale += i;

	sort(fale.begin(), fale.end());

	ll zbir_neki = 0;

	mint q = mint(fale.size()).inv();

	for (int i=1; i<=n; i++) {
		if (a[i] != -1) {
			zbir_neki += lower_bound(fale.begin(), fale.end(), a[i]) - fale.begin();
		} else {
			sol += q * zbir_neki;
		}
	}

	zbir_neki = 0;

	for (int i=n; i>=1; i--) {
		if (a[i] != -1) {
			zbir_neki += fale.end() - lower_bound(fale.begin(), fale.end(), a[i]);
		} else {
			sol += q * zbir_neki;
		}
	}

	cout << (int)sol << '\n';
}