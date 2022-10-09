#include <bits/stdc++.h>
using namespace std;

template<unsigned long long m>
struct modint {

	unsigned long long x;

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
		x = (x * other.x) % m;
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

	explicit operator unsigned long long () const {
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

	modint operator^ (unsigned long long arg) const {
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

	modint inv(unsigned long long exp = m - 2) const {
		return *this ^ exp;
	}
};

const unsigned long long MOD = 1'000'000'007;
typedef modint<MOD> mint;

int m, n;
bitset<1024> a[1005];

mint d[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> m >> n;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;

		for (int j=0; j<m; j++) {
			a[i][j] = s[j] == '1';
		}
	}

	vector<int> b;

	for (int j=0; j<m; j++) {
		bitset<1024> xd;
		for (int i=0; i<m; i++) {
			xd.set(i);
		}
		
		for (int i=1; i<=n; i++) {
			if (a[i][j]) {
				xd &= a[i];
			} else {
				xd &= ~a[i];
			}
		}
		bool ok = true;
		for (int i=j+1; i<m; i++) {
			if (xd[i]) {
				ok = false;
			}
		}
		if (ok) {
			b.push_back(xd.count());
			cerr << "add " << xd.count() << '\n';
		}
	}

	d[0] = d[1] = 1;
	for (int i=1; i<=m; i++) {
		mint bk = 1;
		for (int k=0; k<=i; k++) {
			d[i+1] += bk * d[k];
			bk *= i-k;
			bk *= mint(k+1).inv();
		}

		cerr << d[i+1].x << '\n';
	}

	mint sol = 1;
	for (int x : b) {
		sol *= d[x];
	}

	cout << sol.x << '\n';

}