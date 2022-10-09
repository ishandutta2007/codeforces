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

int n;
int a[100005];
vector<mint> old_veci, old_nije;

const int H = 200;

// posle "veci" ne smes da stavis broj strogo manji
// nu[x] += o_v_[y] akko x >= y
// pri cemu, ako je x = y to ide u nije, inace u veci

// posle "nije" mozes da stavis bilo sta
// pri cemu, ako je x <= y to ide u nije, inace u veci

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	old_veci.assign(H+1, 0);
	old_nije.assign(H+1, 0);
	old_nije[0] = 1;

	for (int i=1; i<=n; i++) {
		int lo, hi;
		if (a[i] == -1)
			lo = 1, hi = H;
		else
			lo = hi = a[i];

		vector<mint> z_veci(H+1), z_nije(H+1);
		vector<mint> nu_veci(H+1), nu_nije(H+1);
		partial_sum(old_veci.begin(), old_veci.end(), z_veci.begin());
		partial_sum(old_nije.begin(), old_nije.end(), z_nije.begin());

		for (int x=lo; x<=hi; x++) {
			nu_nije[x] += old_veci[x];
			nu_veci[x] += z_veci[x-1];

			nu_nije[x] += z_nije[H] - z_nije[x-1];
			nu_veci[x] += z_nije[x-1];
		}

		swap(nu_veci, old_veci);
		swap(nu_nije, old_nije);
	}

	cout << (int)accumulate(old_nije.begin(), old_nije.end(), mint(0)) << '\n';
}