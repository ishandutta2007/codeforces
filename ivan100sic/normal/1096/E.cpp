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

const int MOD = 998244353;
typedef modint<MOD> mint;

mint f[10005], finv[10005];

void init_f() {
	f[0] = finv[0] = 1;
	for (int i=1; i<10005; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}
}

// treba mi broj nizova od:
// x nenegativnih brojeva
// y je suma svih brojeva
// svi su manji ili jednaki z

// ovo mi treba ukupno n*(s-r) puta pa bi mu bolje bilo da radi efikasno

// koliko ima nizova sa zbirom s ciji je upper bound:
// 4 4 4 4 4 4 | | 5 5 5 5 5 5 5 5
// ovo radi 100 * 5000 puta

int n, k, m;

mint sab(int coins, int places) {
	if (coins < 0)
		return 0;
	return f[coins + places - 1] * finv[coins] * finv[places - 1];
}

mint bk(int n, int k) {
	if (n < 0 || n-k < 0 || k < 0)
		return 0;
	return f[n] * finv[n-k] * finv[k];
}

// n = 100, l = 4, k = 6, s = 22
mint tezak_zadatak(int n, int l, int k, int s) {
	mint w = 0;
	// ubacimo sve, pa izbacimo one koji prekoracuju jednom
	// pa ubacimo one koji prekoracuju dvaput, itd itd
	for (int i=0; i<=n; i++) {
		bool minus = i % 2;
		if (s-i*l < 0)
			break;
		for (int p=0; p<=i; p++) {
			if (p > k)
				break;
			int q = i-p;
			if (q < 0 || q > n-k)
				continue;
			mint tmp = sab(s-p*l-q*(l+1), n) * bk(k, p) * bk(n-k, q);
			// cerr << "# " << i << ' ' << p << ' ' << (int)tmp << '\n';
			if (minus)
				w -= tmp;
			else
				w += tmp;
		}
	}

	return w;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	init_f();
	cin >> n >> m >> k;

	if (n == 1) {
		cout << "1\n";
		return 0;
	}

	mint q = sab(m-k, n) * n, p = 0;
	cerr << (int)q << '\n';

	for (int rank=1; rank<=n; rank++) {
		for (int dod=0; dod<=m-k; dod++) {
			mint tmp = tezak_zadatak(n-1, k+dod, rank-1, m-k-dod);
			// cerr << "? " << rank << ' ' << dod << ' ' << (int)tmp << '\n';
			// cerr << "= " << n-1 << ' ' << rank-1 << ' ' << k+dod << ' ' << m-k-dod << '\n';
			p += tmp;
		}
	}

	cerr << (int)p << '\n';

	cout << (int)(p * q.inv()) << '\n';
}