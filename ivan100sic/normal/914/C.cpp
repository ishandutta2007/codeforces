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

string s;
int k;

int steps[1005];
set<int> ok;

mint f[1005];

mint bk(int n, int k) {
	if (n < 0 || k < 0 || n-k < 0) {
		return 0;
	}
	return f[n] * f[k].inv() * f[n-k].inv();
}

int ssteps(string s) {
	if (s == "1") {
		return 0;
	}

	return steps[count(s.begin(), s.end(), '1')] + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> k;

	if (k == 0) {
		cout << 1 << '\n';
		return 0;
	}

	if (k == 1) {
		cout << (int)s.size() - 1;
		return 0;
	}
	
	steps[1] = 0;
	steps[0] = -123123123;

	f[0] = f[1] = 1;

	for (int i=2; i<1005; i++) {
		int j = __builtin_popcount(i);
		steps[i] = steps[j] + 1;
		f[i] = f[i-1] * i;
	}

	if (k >= 8) {
		cout << 0;
		return 0;
	}

	for (int i=1; i<1005; i++) {
		if (steps[i] == k-1) {
			ok.insert(i);
		}
	}

	int tr1 = 0;

	mint sol = 0;

	for (int i=0; i<(int)s.size(); i++) {
		int rest = (int)s.size() - i - 1;

		if (s[i] == '1') {
			for (int kk : ok) {
				sol += bk(rest, kk-tr1);
			}
			tr1++;
		}
	}

	cerr << ssteps(s) << '\n';

	if (ssteps(s) == k) {
		sol += 1;
	}

	cout << sol.x << '\n';


}
/*
10000000000000000000000000000
*/