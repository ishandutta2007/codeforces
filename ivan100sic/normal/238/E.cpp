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

const int mod = 1870126589;
typedef modint<mod> mint;

int n, m, a0, b0, k;
int a[105][105];
int s[105], t[105];

int d[105][105];

basic_string<int> dep[105][105];
basic_string<int> invdep[105][105];
int sol[105][105];

bool inq[105][105];

bool onsp(int x, int p) {
	return d[s[p]][x] + d[x][t[p]] == d[s[p]][t[p]];
}

bool onsp(int x, int y, int p) {
	return a[x][y] && onsp(x, p) && onsp(y, p) && d[y][t[p]] == d[x][t[p]] - 1;
}

bool onsp2(int x, int y, int tgt) {
	return a[x][y] && d[y][tgt] < 5e8 && d[y][tgt] == d[x][tgt] - 1;
}

// num sp
mint cs[105][105];
int pas[105][105];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	memset(d, 63, sizeof d);
	memset(sol, 63, sizeof sol);

	cin >> n >> m >> a0 >> b0;
	a0--;
	b0--;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x][y] = 1;
		d[x][y] = 1;
	}

	for (int i=0; i<n; i++) {
		d[i][i] = 0;
	}

	cin >> k;
	for (int i=0; i<k; i++) {
		cin >> s[i] >> t[i];
		s[i]--;
		t[i]--;
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}

	for (int i=0; i<n; i++) {
		vector<int> ord(n);
		iota(begin(ord), end(ord), 0);
		sort(begin(ord), end(ord), [&](int x, int y) {
			return d[x][i] < d[y][i];
		});

		cs[i][i] = 1;

		for (int j : ord) {
			for (int w=0; w<n; w++) {
				if (onsp2(j, w, i)) {
					cs[j][i] += cs[w][i];
				}
			}
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<k; j++) {
			if (cs[s[j]][i] * cs[i][t[j]] == cs[s[j]][t[j]] && d[i][t[j]] < 5e8) {
				pas[i][j] = 1;
			}
		}
	}

	for (int p=0; p<k; p++) {
		for (int x=0; x<n; x++) {
			if (!onsp(x, p)) continue;

			for (int y=0; y<n; y++) {
				if (onsp(x, y, p)) {
					// cerr << "dep " << x+1 << ' ' << y+1 << " bus " << p << '\n';
					dep[x][p] += y;
					invdep[y][p] += x;
				}
			}
		}
	}

	queue<pair<int, int>> q;
	auto enq = [&](int x, int y) {
		if (inq[x][y]) return;
		q.emplace(x, y);
		inq[x][y] = 1;
	};

	for (int p=0; p<k; p++) {
		sol[b0][p] = 0;
		for (auto y : invdep[b0][p]) {
			enq(y, p);
		}
	}

	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		inq[x][y] = 0;

		int vr = 0;

		if (dep[x][y].size()) {
			for (int u : dep[x][y]) {
				vr = max(vr, sol[u][y]);
			}
		} else {
			vr = 1e9;
		}

		for (int j=0; j<k; j++) {
			if (j != y) {
				// mozemo da promenimo bus samo ako smo sigurni da on tu prolazi
				if (pas[x][j]) {
					vr = min(vr, sol[x][j] + 1);
				}
			}
		}

		if (vr < sol[x][y]) {
			sol[x][y] = vr;
			for (int u : invdep[x][y]) {
				enq(u, y);
			}
			for (int j=0; j<k; j++) {
				if (j != y) {
					enq(x, j);
				}
			}
		}

		// for (int x=0; x<n; x++) {
		// 	for (int p=0; p<k; p++) {
		// 		cerr << sol[x][p] << " \n"[p == k-1];
		// 	}
		// }
		// cerr << '\n';
	}

	int z = 1e9;
	for (int i=0; i<k; i++) {
		if (pas[a0][i]) {
			z = min(z, sol[a0][i] + 1);
		}
	}

	if (z > 5e8)
		z = -1;
	cout << z << '\n';
}