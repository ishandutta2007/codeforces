#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	pt operator- (pt b) const {
		return {x-b.x, y-b.y};
	}
	bool operator== (pt b) const {
		return x == b.x && y == b.y;
	}
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

ll sq(ll x) {
	return x*x;
}

ll d2(pt a, pt b) {
	return sq(a.x-b.x) + sq(a.y-b.y);
}

ll sp(pt a, pt b) {
	return a.x*b.x + a.y*b.y;
}

bool kolin(pt a, pt b, pt c) {
	if (det(a, b, c) != 0)
		return false;
	return b == a || b == c || sp(a-b, b-c) > 0;
}

ll sgn(ll x) {
	if (x < 0) return -1;
	else if (x == 0) return 0;
	else return 1;
}

bool sek(pt a, pt b, pt c, pt d) {
	return
		sgn(det(a, b, c)) * sgn(det(a, b, d)) == -1
	 && sgn(det(c, d, a)) * sgn(det(c, d, b)) == -1;
}

int n;
pt a[205];

bool v[205][205];

bool pip(pt b) {
	ld w = 0;
	for (int i=0; i<n; i++) {
		int j = (i+1) % n;

		ld arg = sp(b - a[i], b - a[j]);
		arg /= sqrt(d2(b, a[i]));
		arg /= sqrt(d2(b, a[j]));
		arg = max(arg, (ld)-1);
		arg = min(arg, (ld)1);

		if (det(b, a[i], a[j]) < 0)
			w += acos(arg);
		else
			w -= acos(arg);

		// cerr << arg << ' ';
	}

	// cerr << b.x << ' ' << b.y << '\n';
	// cerr << w << '\n';

	return abs(w) > 1.5;
}

void visgraph() {
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			bool ok = true;
			// sece neku duz?
			for (int k=0; k<n; k++) {
				int l = (k+1) % n;
				if (sek(a[i], a[j], a[k], a[l]))
					ok = false;
			}

			// if (j == n-1)
			// 	cerr << "sek sek " << i << ' ' << ok << '\n';

			// prolazi kroz neku tacku?
			for (int k=0; k<n; k++) {
				if (k == i || k == j)
					continue;
				if (kolin(a[i], a[k], a[j])) {
					if (j == n-1) {
						// cerr << a[i].x << ' ' << a[i].y << '\n';
						// cerr << a[k].x << ' ' << a[k].y << '\n';
						// cerr << a[j].x << ' ' << a[j].y << '\n';
					}
					ok = false;
				}
			}

			// if (j == n-1)
			// 	cerr << "sek sek " << i << ' ' << ok << '\n';

			// prolazi spolja?
			if (ok) {
				pt tmp = {(a[i].x + a[j].x) / 2, (a[i].y + a[j].y) / 2};
				if (!pip(tmp))
					ok = false;
			}

			if (j == i+1 || (i == 0 && j == n-1))
				ok = true;

			v[i][j] = v[j][i] = ok;
		}
	}
}

void flip() {
	ll s = 0;
	for (int i=1; i<n-1; i++)
		s += det(a[0], a[i], a[i+1]);
	if (s < 0)
		reverse(a, a+n);
}

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

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;

mint dp[205][205];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].x *= 2;
		a[i].y *= 2;
	}
	flip();
	visgraph();

	// for (int i=0; i<n; i++) {
	// 	for (int j=0; j<n; j++)
	// 		cerr << v[i][j];
	// 	cerr << '\n';
	// }

	for (int i=n-2; i>=0; i--) {
		dp[i][i+1] = 1;
		for (int j=i+2; j<n; j++) {
			if (v[i][j]) {
				for (int k=i+1; k<j; k++)
					dp[i][j] += dp[i][k] * dp[k][j];
			}
		}
	}

	// for (int i=0; i<n; i++)
	// 	for (int j=i+1; j<n; j++)
	// 		cerr << i << ' ' << j << ' ' << (int)dp[i][j] << '\n';

	cout << (int)dp[0][n-1] << '\n';
}