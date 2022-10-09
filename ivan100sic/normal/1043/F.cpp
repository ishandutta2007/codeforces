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

const int MOD = 858581351;
typedef modint<MOD> mint;

mint f[300005], finv[300005];

mint bk(int n, int k) {
	if (n < 0 || k < 0 || n-k < 0)
		return 0;
	return f[n] * finv[n-k] * finv[k];
}

int n;
int a[300005];

int c[300005], g[300005];
int m[300005];

mint d[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<300005; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}



	for (int i=1; i<=300000; i++)
		for (int j=i; j<=300000; j+=i)
			g[i] += c[j];

	fill(m+1, m+300001, 1);
	for (int i=2; i<=300000; i++)
		for (int j=2; i*j<=300000; j++)
			m[i*j] -= m[i];

	for (int x=1; x<=7; x++) {
		for (int i=1; i<=300000; i++)
			d[i] = bk(g[i], x);

		mint cnt = d[1];
		for (int i=2; i<=300000; i++)
			cnt -= d[i] * m[i];

		if (cnt.x != 0) {
			cout << x << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}