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

int n;
int a[1000005];
mint q[1000005];

/*
0
1 0
2 3 0
6 8 12 0
24 30 40 60 0
120 144 180 240 360 0
720 840 1008 1260 1480 2520
*/

void test() {
	const int N = 6;
	int a[N] = {0, 1, 2, 3, 3, 4};
	int p[N];
	iota(p, p+N, 0);
	int c[N] = {0, 0, 0, 0, 0, 0};
	do {
		int b[N];
		for (int i=0; i<N; i++)
			b[i] = a[p[i]];
		int z = b[0];
		for (int i=1; i<N; i++) {
			if (b[i] > z) {
				c[z]++;
				z = b[i];
			}
		}
	} while (next_permutation(p, p+N));
	for (int i=0; i<N; i++) {
		cerr << i << ": " << c[i] << '\n';
	}
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// test();

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	mint f = 1;
	for (int i=1; i<n; i++)
		f *= i;
	q[0] = f;
	for (int i=1; i<n; i++) {
		q[i] = q[i-1] * (n+1-i) * mint(n-i).inv();
	}

	mint sol = 0;
	int j = 0;

	for (int i=1; i<n; i++) {
		if (a[i] != a[i-1]) {
			sol += q[j] * (i-j) * a[i-1];
			// cerr << (int)q[j] << ' ' << (i-j) << ' ' << a[i-1] << '\n';
			j = i;
		}
	}
	cout << (int)sol << '\n';
}