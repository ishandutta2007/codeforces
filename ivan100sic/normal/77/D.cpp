// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 1'000'000'007;
typedef modint<mod> mint;

int n, m;
string a[1005];
char b[255][255];

mint d1[255], d2[255], d[255];

mint t[255];

char daj(int u, int v) {
	int cnt = 0;
	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			cnt += a[u+i][v+j] == 'O';
		}
	}

	switch (cnt) {
	case 0:
	case 1:
	case 4:
	case 5:
		return 'b';
	case 2:
	case 3:
		return a[u][v] == 'O' ? 'h' : 'v';
	case 6:
		return a[u][v+1] == 'O' ? 'h' : 'v';
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<4*n+1; i++) {
		cin >> a[i];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			b[i][j] = daj(4*i+1, 4*j+1);
		}
	}

	for (int j=0; j<m; j++) {
		// d1
		if (n % 2 == 0) {
			int ok = 1;
			for (int i=0; i<n; i+=2) {
				if (b[i][j] == 'h' || b[i+1][j] == 'h') {
					ok = 0;
				}
			}
			d1[j] = ok;
		}

		// d2
		if (j == m-1) {
			break;
		}

		fill(t, t+255, 0);
		t[0] = 1;

		for (int i=0; i<n; i++) {
			if (b[i][j] != 'v' && b[i][j+1] != 'v') {
				t[i+1] += t[i];
			}

			if (i+1 < n && b[i][j] != 'h' && b[i][j+1] != 'h' &&
			    b[i+1][j] != 'h' && b[i+1][j+1] != 'h')
			{
				t[i+2] += t[i];
			}
		}

		d2[j] = t[n];
	}

	d[0] = 1;
	for (int j=0; j<m; j++) {
		d[j+1] += d[j] * d1[j];
		d[j+2] += d[j] * (d2[j] - d1[j] * d1[j+1]);
	}

	cout << d[m]() << '\n';
}