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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

int n, m, p, s;
mint f[200005], finv[200005];

mint bk(int x, int y) {
	if (x < 0 || y < 0)
		return 0;
	return f[x+y] * finv[x] * finv[y];
}

struct pt {
	int x, y;
	bool operator< (const pt& b) const {
		return x+y < b.x+b.y;
	}
} a[2005];

mint dp[2005][25];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<200005; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}

	cin >> n >> m >> p >> s;
	bool has00 = false, has11 = false;
	for (int i=0; i<p; i++) {
		cin >> a[i].x >> a[i].y;
		if (a[i].x == 1 && a[i].y == 1)
			has00 = true;
		if (a[i].x == n && a[i].y == m)
			has11 = true;
	}
	if (!has00)
		a[p++] = {1, 1};
	if (!has11)
		a[p++] = {n, m};
	sort(a, a+p);

	/*
		dp[i][j] - broj nacina da se dodje do polja i, a da se "stane"
		na tacno j polja
	*/

	dp[0][1] = 1;
	for (int i=1; i<p; i++) {
		for (int k=1; k<25; k++) {
			dp[i][k] = bk(a[i].x - 1, a[i].y - 1);
			for (int j=0; j<i; j++) {
				dp[i][k] -= dp[j][k] * bk(a[i].x - a[j].x, a[i].y - a[j].y);
			}
		}
		dp[i][24] = bk(a[i].x - 1, a[i].y - 1);
		for (int k=24; k>0; k--)
			dp[i][k] -= dp[i][k-1];
	}

	mint sol = 0;
	for (int k=0, sx=s<<!has00<<!has11; k<25; k++, sx-=sx/2) {
		sol += dp[p-1][k] * sx;
	}
	cout << (int)(sol * bk(n-1, m-1).inv()) << '\n';
}

/*
s..
1.2
..t
*/