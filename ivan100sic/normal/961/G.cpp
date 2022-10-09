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

int n, k;
int a[200005];

mint f[200005];

mint binom(int n, int k) {
	return f[n] * f[n-k].inv() * f[k].inv();
}

mint m1(int x) {
	return x % 2 ? -1 : 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = 1;
	for (int i=1; i<200005; i++)
		f[i] = f[i-1] * i;

	cin >> n >> k;

	mint zbir = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		zbir += x;
	}

	mint sol = 0;

	if (k == 1) {
		sol = n;
	} else {
		for (int j=0; j<k; j++) {
			// velicina mog seta, ostale delim na k-1 nepraznih
			// mint t = i * binom(n-1, i-1) * part(n-i, k-1);
			mint t = m1(k-j) * (mint(-j) * (mint(j+1)^n) + n + mint(2*j)*n
				+ mint(j)*j*n - (mint(j+1)^n)*n) * binom(k-1, j);
			mint r = mint(1+j)*(j+1)*f[k-1];
			sol += t * r.inv();
		}
	}


	cout << (int)(sol*zbir) << '\n';
}