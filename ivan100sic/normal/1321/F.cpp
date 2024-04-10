// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

const int MOD = 1985561387;
typedef modint<MOD> mint;

const int B = 543751;

int n;
string s;
mint h[200005], p[200005];
int z[200005], f[200005];

mint hg(int x, int y) {
	return h[y] - h[x] * p[z[y] - z[x]];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	p[0] = 1;
	for (int i=0; i<n; i++)
		p[i+1] = p[i] * B;

	int last = -1;
	for (int i=0; i<n; i++) {
		if (s[i] == '0') {
			z[i+1] = z[i] + 1;
			h[i+1] = h[i] * B + ((i - last) % 2 ? 1 : -1);
			last = i;
		} else {
			z[i+1] = z[i];
			h[i+1] = h[i];
		}
	}

	for (int i=n-1; i>=0; i--)
		f[i] = s[i] == '0' ? 0 : f[i+1] + 1;

	int q;
	cin >> q;
	while (q--) {
		int a, b, l;
		cin >> a >> b >> l;
		a--, b--;

		bool ok = false;
		int d0 = f[a];
		int d1 = f[b];
		
		if (z[a+l] == z[a] && z[b+l] == z[b]) {
			ok = true;
		} else if (z[a+l] - z[a] == z[b+l] - z[b] && d0 % 2 == d1 % 2) {
			mint h1 = hg(a + f[a] + 1, a + l);
			mint h2 = hg(b + f[b] + 1, b + l);
			ok = h1 == h2;
		}

		cout << (ok ? "Yes\n" : "No\n");
	}
}

// I will still practice daily...