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

const int MOD = 1123123213;
const int B = 5489358;
typedef modint<MOD> mint;

string s[2005], t[205];
int n, m;
mint a[2005][205], b[205][2005];
mint row, pw[2005], pw_row[2005];

template<class T>
void prefix_sum(T* a, int n, int m) {
	for (int i=1; i<=n; i++)
		for (int j=0; j<=m; j++)
			a[i][j] += a[i-1][j];
	for (int i=0; i<=n; i++)
		for (int j=1; j<=m; j++)
			a[i][j] += a[i][j-1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	row = mint(B) ^ 65536;
	pw[0] = pw_row[0] = 1;
	for (int i=1; i<2005; i++) {
		pw[i] = pw[i-1] * B;
		pw_row[i] = pw_row[i-1] * row;
	}

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<m; i++)
		cin >> t[i];

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			a[i+1][j+1] = pw_row[i] * pw[j] * s[i][j];
		}
	}

	for (int i=0; i<m; i++) {
		for (int j=0; j<n; j++) {
			b[i+1][j+1] = pw_row[i] * pw[j] * t[i][j];
		}
	}

	prefix_sum(a, n, m);
	prefix_sum(b, m, n);

	for (int i=0; i<=n-m; i++) {
		for (int j=0; j<=n-m; j++) {
			mint x = (a[i+m][m] - a[i][m]) * pw[j];
			mint y = (b[m][j+m] - b[m][j]) * pw_row[i];
			if (x == y) {
				cout << i+1 << ' ' << j+1 << '\n';
				return 0;
			}
		}
	}
}