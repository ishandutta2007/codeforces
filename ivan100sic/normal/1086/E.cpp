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

int n;
int a[2005][2005];

// fenwick

struct fenwick {
	vector<int> c, cc;

	fenwick(int n) : c(n+1, 0), cc(n+1, 0) {}

	void add(int x, int y) {
		cc[x] += y;
		for (int i=x; i<=n; i+=i&-i)
			c[i] += y;
	}

	int sum(int x) {
		int y = 0;
		for (int i=x; i>0; i-=i&-i)
			y += c[i];
		return y;
	}

	int peek(int x) {
		return cc[x];
	}
};
// end fenwick

mint f[2005];

mint calc_rank(const int* a) {
	fenwick w(n);
	mint p = 0;
	for (int i=1; i<=n; i++) {
		p += f[n-i] * (a[i] - w.sum(a[i]) - 1);
		w.add(a[i], 1);
	}
	return p;
}

mint presek[2005][2005];

struct spt {
	vector<int> a, b;
	fenwick w;

	spt(int n) : a(n+1, 0), b(n+1, 0), w(n) {}

	void add_a(int x, int y) {
		w.add(x, y * b[x]);
		a[x] += y;
	}

	void add_b(int x, int y) {
		w.add(x, y * a[x]);
		b[x] += y;
	}

	int sum(int y) {
		return w.sum(y);
	}

	int peek(int y) {
		return w.peek(y);
	}
};

mint calc_rank(const int* a, const int* b) {
	// koliko permutacija "razlicitih" od a je manje od b
	spt w(n);
	fenwick wb(n);
	fenwick wa(n);

	for (int i=1; i<=n; i++) {
		w.add_a(i, 1);
		w.add_b(i, 1);
		wa.add(i, 1);
		wb.add(i, 1);
	}

	mint sol = 0;

	for (int i=1; i<=n; i++) {
		w.add_a(a[i], -1);
		w.add_b(b[i], -1);
		wa.add(a[i], -1);
		wb.add(b[i], -1);

		int xkand = wb.sum(b[i] - 1);
		if (wb.peek(a[i]) && a[i] < b[i])
			xkand--;
	
		int h0 = w.sum(n) + wa.peek(b[i]);
		int g1 = w.sum(b[i] - 1);		
		int g0 = xkand - g1;

		sol += presek[n-i][h0] * g0;
		sol += presek[n-i][h0 - 1] * g1;

		// cerr << n-i << ' ' << h0 << ' ' << g0 << ' ' << g1 << ' ' << (int)sol << '\n';

		if (a[i] == b[i])
			break;
	}

	return sol;
}

int crbrut(const int* a, const int* b) {
	vector<int> c(n+1);
	iota(c.begin(), c.end(), 0);
	int fk = (int)f[n];
	int z = 0;
	while (fk--) {
		int ok = 1;
		for (int i=1; i<=n; i++)
			if (c[i] == a[i])
				ok = 0;
		if (vector<int>(c.begin() + 1, c.end()) >= vector<int>(b+1, b+n+1))
			ok = 0;
		z += ok;
		next_permutation(c.begin() + 1, c.end());
	}
	return z;
}

void test() {
	n = 4;
	int a[5] = {0, 2, 1, 4, 3};
	int b[5] = {0, 1, 2, 3, 4};
	for (int i=0; i<24; i++) {
		for (int j=1; j<=4; j++)
			cerr << b[j] << ' ';
		cerr << " : ";
		cerr << (int)calc_rank(a, b) << ' ' << crbrut(a, b) << '\n';
		next_permutation(b+1, b+5);
	}
}

void test_spec() {
	n = 4;
	int a[5] = {0, 2, 1, 4, 3};
	int b[5] = {0, 1, 2, 4, 3};
	cerr << (int)calc_rank(a, b) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = 1;
	for (int i=1; i<2005; i++)
		f[i] = f[i-1] * i;

	presek[0][0] = 1;

	for (int n=1; n<2005; n++) {
		presek[n][0] = f[n];
		for (int k=1; k<=n; k++)
			presek[n][k] = presek[n][k-1] - presek[n-1][k-1];
	}

	for (int i=0; i<=6; i++) {
		for (int j=0; j<=i; j++) 
			cerr << (int)presek[i][j] << ' ';
		cerr << '\n';
	}

	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> a[i][j];
		}
	}

	// test();
	// test_spec();

	mint sol = 0;
	sol += calc_rank(a[1]) * (presek[n][n] ^ (n-1));
	for (int i=2; i<=n; i++) {
		mint tmp = calc_rank(a[i-1], a[i]);
		sol += tmp * (presek[n][n] ^ (n-i));
	}
	cout << (int)sol << '\n';
}