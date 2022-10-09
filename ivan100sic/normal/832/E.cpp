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

	modint& operator/= (const modint& other) {
		x = (x * 1ull * other.inv().x) % m;
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

	modint operator/ (const modint& other) const {
		modint tmp = *this;
		tmp /= other;
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

const int MOD = 5;
typedef modint<MOD> mint;

typedef valarray<mint> niz;

struct gaus {
	niz a[500];
	int rank;

	gaus() {
		rank = 0;
		for (int i=0; i<500; i++)
			a[i] = niz(mint(0), 500);
	}

	void add(niz b) {
		for (int i=0; i<500; i++) {
			if (b[i] == 0)
				continue;
			if (a[i][i] == 0) {
				a[i] = b / b[i];
				rank++;
				return;
			} else {
				b -= a[i] * b[i];
			}
		}
	}

	bool ima(niz b) {
		for (int i=0; i<500; i++) {
			if (b[i] == 0)
				continue;
			if (a[i][i] == 0) {
				return false;
			} else {
				b -= a[i] * b[i];
			}
		}
		return true;
	}
};

int pw5[5555];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pw5[0] = 1;
	for (int i=1; i<5555; i++) {
		pw5[i] = pw5[i-1] * 5ll % 1'000'000'007;
	}

	gaus g;

	int n, q, m;
	cin >> n >> q;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		m = s.size();
		niz a(mint(0), 500);
		for (int i=0; i<m; i++) {
			a[i] = s[i] - 'a';
		}
		g.add(a);
	}

	cin >> q;
	while (q--) {
		string s;
		cin >> s;
		niz a(mint(0), 500);
		for (int i=0; i<m; i++)
			a[i] = s[i] - 'a';
		if (g.ima(a)) {
			cout << pw5[n - g.rank] << '\n';
		} else {
			cout << "0\n";
		}
	}
}