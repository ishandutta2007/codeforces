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

mint f[100005], finv[100005];

mint bk(int n, int k) {
	if (n < 0 || k < 0 || n-k < 0)
		return 0;
	return f[n] * finv[k] * finv[n-k];
}

mint func(int n, int k) {
	// (n-k) stvari na k ljudi
	// n-k stars, k-1 bars
	return bk(n-1, k-1);
}

basic_string<int> divs[100005];
int mob[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<100005; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}

	mob[1] = 1;
	for (int i=1; i<100005; i++) {
		for (int j=2*i; j<100005; j+=i) {
			mob[j] -= mob[i];
		}
	}

	for (int i=1; i<100005; i++)
		for (int j=i; j<100005; j+=i)
			divs[j] += i;

	int q;
	cin >> q;
	while (q--) {
		int n, f;
		cin >> n >> f;
		mint sol = 0;
		for (int d : divs[n]) {
			if (mob[d] == 1)
				sol += func(n/d, f);
			else if (mob[d] == -1)
				sol -= func(n/d, f);
		}
		cout << (int)sol << '\n';
	}
}