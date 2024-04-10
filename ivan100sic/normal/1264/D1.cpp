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

const int MOD = 998244353;
typedef modint<MOD> mint;

string s;
mint bk[2005][2005], zk[2005][2005], d[2005];
int zv[2005], op[2005], cl[2005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	int n = s.size();
	for (int i=0; i<2005; i++) {
		bk[i][0] = zk[i][0] = 1;
		for (int j=1; j<=i; j++) {
			bk[i][j] = bk[i-1][j] + bk[i-1][j-1];
			zk[i][j] = zk[i][j-1] + bk[i][j];
		}
	}

	for (int i=0; i<n; i++) {
		zv[i+1] = zv[i] + (s[i] == '?');
		op[i+1] = op[i] + (s[i] == '(');
		cl[i+1] = cl[i] + (s[i] == ')');
	}

	mint sol = 0;
	for (int k=1; k<=n/2+2; k++) {
		mint ways = 0;
		for (int j=0; j<n; j++) {
			if (s[j] == '(' || s[j] == '?') {

				mint t = 0;

				int x = zv[j], y = k-1-op[j];
				if (y >= 0 && y <= x)
					t = bk[x][y];

				x = zv[n] - zv[j+1];
				y = cl[n] - cl[j+1];

				// imas y zatv, treba dodati neko u in [0, x] tako da je zbir bar k
				// y + u >= k
				// u >= k - y
				// odnosno
				// x - u <= x - k + y

				if (x - k + y >= 0)
					t *= zk[x][min(x, x-k+y)];
				else
					t = 0;

				ways += t;
			}
		}

		d[k] = ways;
		sol += (d[k-1] - d[k]) * (k-1);
	}

	cout << (int)sol << '\n';
}