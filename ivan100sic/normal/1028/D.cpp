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

void nema() {
	cout << 0;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	mint ways = 1;

	cin >> n;
	set<int> buys, sells, idk;

	buys.insert(0);
	sells.insert(1123123123);

	auto transfer = [&](int x) {
		for (int y : idk)
			if (y > x)
				sells.insert(y);
			else if (y < x)
				buys.insert(y);
		idk.clear();
	};

	while (n--) {
		string t;
		cin >> t;
		int x;
		cin >> x;

		if (t == "ADD") {

			if (x < *buys.rbegin()) {
				buys.insert(x);
			} else if (x > *sells.begin()) {
				sells.insert(x);
			} else {
				idk.insert(x);
			}

		} else {

			if (x < *buys.rbegin()) {
				nema();
			} else if (x > *sells.begin()) {
				nema();
			} else if (x == *buys.rbegin()) {
				buys.erase(x);
				transfer(x);
			} else if (x == *sells.begin()) {
				sells.erase(x);
				transfer(x);
			} else {
				ways *= 2;
				transfer(x);
			}
		}
	}

	ways *= idk.size() + 1;

	cout << (int)ways << '\n';
}