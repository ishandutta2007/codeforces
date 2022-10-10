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

const int MOD = 2'000'000'011;
typedef modint<MOD> mint;

string s, t;
mint h[1000005], p[1000005];

const mint BASE = 4432321;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s >> t;
	if (s[0] == '1')
		for (char& x : s)
			x ^= 1;

	int m = s.size();
	int nula = 0;
	for (char x : s)
		if (x == '0')
			nula++;
	int kec = m - nula;
	int n = t.size();
	p[0] = 1;
	for (int i=1; i<=n; i++)
		p[i] = p[i-1] * BASE;

	for (int i=0; i<n; i++)
		h[i+1] = h[i] * BASE + t[i];

	int init0 = 0;

	int sol = 0;

	while (s[init0] == '0')
		init0++;

	for (int k=1; k*nula<=n; k++) {
		if ((n - k*nula) % kec)
			continue;
		int l = (n - k*nula) / kec;
		if (l <= 0)
			continue;

		// proveri
		mint nula_hes = h[k];
		mint kec_hes = h[k * init0 + l] - h[k * init0] * p[l];

		if (nula_hes == kec_hes)
			continue;

		int pos = 0, ok = 1;
		for (char x : s) {
			if (x == '0') {
				mint parce = h[pos + k] - h[pos] * p[k];
				if (parce != nula_hes) {
					ok = 0;
					break;
				}
				pos += k;
			} else {
				mint parce = h[pos + l] - h[pos] * p[l];
				if (parce != kec_hes) {
					ok = 0;
					break;
				}
				pos += l;
			}
		}

		// if (ok)
		// 	cerr << k << ' ' << l << '\n';

		sol += ok;
	}

	cout << sol << '\n';
}