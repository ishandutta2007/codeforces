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

int n;
int l[200005], r[200005];
mint y[200005];

int presek(int i, int j) {
	return max(0, min(r[i], r[j]) - max(l[i], l[j]) + 1);
}

int presek(int i, int j, int k) {
	int b = min({r[i], r[j], r[k]});
	int a = max({l[i], l[j], l[k]});
	return max(0, b-a+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> l[i];
	for (int i=0; i<n; i++)
		cin >> r[i];

	for (int i=0; i<n-1; i++) {
		mint p = presek(i, i+1);
		mint q = r[i] - l[i] + 1;
		q *= r[i+1] - l[i+1] + 1;
		y[i] = (mint(1) - p*q.inv());
		// cerr << (int)y[i] << '\n';
	}

	mint sol;
	mint t = accumulate(y, y+n-1, mint(0));
	sol += t*t;

	for (int i=0; i<n-1; i++)
		sol -= y[i]*y[i];

	sol += t*3+1; // uracunat je i zadnji korak

	for (int i=0; i<n-2; i++) {
		sol -= y[i]*y[i+1]*2;
	}

	for (int i=0; i<n-2; i++) {
		mint p = presek(i, i+1, i+2);
		mint q = r[i] - l[i] + 1;
		q *= r[i+1] - l[i+1] + 1;
		q *= r[i+2] - l[i+2] + 1;
		sol += (y[i] + y[i+1] + p*q.inv() - 1)*2;
	}

	cout << (int)sol << '\n';
}