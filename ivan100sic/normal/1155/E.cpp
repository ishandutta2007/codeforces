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

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'003;
typedef modint<MOD> mint;
typedef array<mint, 12> poli;

poli mul(poli a, poli b) {
	poli c;
	for (int i=0; i<12; i++) {
		for (int j=0; i+j<12; j++) {
			c[i+j] += a[i] * b[j];
		}
	}
	return c;
}

poli add(poli a, poli b) {
	for (int i=0; i<12; i++)
		a[i] += b[i];
	return a;
}

mint vals[12];
mint ninv[12];
poli nadjeni;

mint inverz(int x) {
	if (x < 0)
		return mint(0) - ninv[-x];
	else
		return ninv[x];
}

void racunaj_poli() {
	for (int i=0; i<12; i++) {
		poli p;
		p[0] = 1;
		for (int j=0; j<12; j++) {
			if (j == i)
				continue;
			poli tmp;
			tmp[1] = inverz(i-j);
			tmp[0] = tmp[1] * -j;
			p = mul(p, tmp);
		}
		poli tmp;
		tmp[0] = vals[i];
		nadjeni = add(nadjeni, mul(p, tmp));
	}
}

mint rac(mint x) {
	mint r = 0;
	for (int i=11; i>=0; i--) {
		r = r * x + nadjeni[i];
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<12; i++) {
		ninv[i+1] = mint(i+1).inv();
		cout << "? " << i << '\n' << flush;
		int x;
		cin >> x;
		vals[i] = x;
		if (x == 0) {
			cout << "! " << i << '\n';
			return 0;
		}
	}

	racunaj_poli();

	for (int i=12; i<1000003; i++) {
		if (rac(i) == 0) {
			cout << "! " << i << '\n' << flush;
			return 0;
		}
	}

	cout << "! -1\n" << flush;
}