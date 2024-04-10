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

mint f[400005], finv[400005], pw_half[400005];

int n;
ll T;
int a[200005];

mint bk(ll n, ll k) {
	if (n < 0 || k < 0 || n-k < 0)
		return 0;
	return f[n] * finv[k] * finv[n-k];
}

void incr_i(int i_new, ll T, mint& curr) {
	if (i_new <= T) {
		curr += curr;
	} else {
		curr += curr;
		curr -= bk(i_new-1, T);
	}
}

void decr_t(ll i, ll Told, ll Tnew, mint& curr) {
	Told = clamp(Told, -1ll, i);
	Tnew = clamp(Tnew, -1ll, i);
	while (Told != Tnew) {
		curr -= bk(i, Told--);
	}
}

void readstdin() {
	cin >> n >> T;
	for (int i=0; i<n; i++)
		cin >> a[i];
}

void generate() {
	n = 200000;
	T = 1000000000;
	mt19937 eng;
	for (int i=0; i<n; i++)
		a[i] = uniform_int_distribution<int>(1, 123123123)(eng);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = pw_half[0] = 1;
	mint half = mint(2).inv();
	for (int i=1; i<400005; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
		pw_half[i] = pw_half[i-1] * half;
	}

	// generate();
	readstdin();

	mint curr = 1, sol = 0;
	for (int i=0; i<n; i++) {
		incr_i(i+1, T, curr);
		decr_t(i+1, T, T-a[i], curr);
		// cerr << i << ' ' << (int)curr << '\n';
		sol += pw_half[i+1] * curr;
		T -= a[i];
	}
	cout << (int)sol << '\n';
}