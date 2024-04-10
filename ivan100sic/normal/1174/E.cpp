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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;


/*

5 4 4 3 3 3 3 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 1

5 4 3 2 1

a,b,c,d,e

a*b*c*d*e

5_ 4_ 3_ 2_ 1_

*/

int n;
mint sol;

void dodaj(basic_string<int> v) {
	for (int x : v)
		cerr << x << ' ';
	cerr << '\n';

	vector<int> c(v.size());
	int k = v.size();
	for (int i=0; i<k; i++) {
		c[i] = n / v[i];
		if (i)
			c[i] -= n / v[i-1];
	}

	for (int i=0; i<k; i++)
		cerr << i << ' ' << v[i] << ' ' << c[i] << '\n';

	mint p = 1;
	for (int x : c)
		p *= x;

	int z = 0;
	for (int i=k-1; i>=0; i--) {
		for (int j=1; j<c[i]; j++) {
			z++;
			p *= z;
		}
		z++;
	}

	cerr << (int)p << '\n';

	sol += p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int h = 1;
	while ((1 << (h+1)) <= n)
		h++;

	// dvojka niz
	basic_string<int> v;
	for (int i=(1<<h); i>=1; i>>=1)
		v += i;
	dodaj(v);

	// trojka nizovi?
	int trojka = (1 << (h-1)) * 3;
	if (trojka <= n) {
		for (int i=0; i<h; i++) {
			int x = trojka;
			v = {x};
			for (int j=0; j<i; j++) {
				x /= 2;
				v += x;
			}
			x /= 3;
			v += x;
			while (x > 1) {
				x /= 2;
				v += x;
			}
			dodaj(v);
		} 
	}

	cout << (int)sol << '\n';
}