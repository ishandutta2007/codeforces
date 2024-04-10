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

const int mod = 998'244'353;
typedef modint<mod> mint;

template<class R>
struct matrix {
	vector<R> a;
	int n, m;

	matrix(int _n, int _m = -1) : n(_n) {
		m = _m == -1 ? n : _m;
		a.resize(n*m);
	}

	static matrix eye(int n) {
		matrix t(n);
		for (int i=0; i<n; i++)
			t[i][i] = 1;
		return t;
	}

	matrix operator* (const matrix& b) const {
		matrix c(n, b.m);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				for (int k=0; k<b.m; k++)
					c[i][k] += a[m*i+j] * b[j][k];
		return c;
	}

	matrix& operator+= (const matrix& b) {
		for (int i=0; i<n*m; i++)
			a[i] += b.a[i];
		return *this;
	}

	matrix& operator-= (const matrix& b) {
		for (int i=0; i<n*m; i++)
			a[i] += b.a[i];
		return *this;
	}

	R* operator[] (int x) { return a.data() + m*x; }
	const R* operator[] (int x) const { return a.data() + m*x; }
	matrix operator+ (const matrix& b) const { auto t = *this; t += b; return t; }
	matrix operator- (const matrix& b) const { auto t = *this; t -= b; return t; }
	matrix& operator*= (const matrix& b) { return *this = *this * b; }
	template<class U> matrix operator^= (U arg) { return *this = *this ^ arg; }

	template<class U>
	matrix operator^ (U arg) const {
		if (arg == 0)
			return matrix::eye(n);
		if (arg == 1)
			return *this;
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1)
			t *= *this;
		return t;
	}

	matrix T() const {
		matrix b(m, n);
		for (int i=0; i<n; i++)
			for (int j=0; j<m; j++)
				b[j][i] = a[i][j];
		return b;
	}
};

bool compat(string a, string b) {
	if (a.size() > b.size()) {
		swap(a, b);
	}

	return equal(a.begin(), a.end(), b.end() - a.size());
}

bool rst[222][26];
int pe[222][26];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

	int n, m;
  cin >> n >> m;
	vector<string> pref = {{}};
	set<string> a;

	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		a.insert(s);
		int l = s.size();
		for (int j=1; j<=l; j++) {
			pref.push_back(s.substr(0, j));
		}
	}

	sort(begin(pref), end(pref));
	pref.erase(unique(begin(pref), end(pref)), end(pref));
	int ps = pref.size();

	map<pair<int, int>, int> mp;
	map<int, pair<int, int>> imp;
	int k = 0;

	for (int i=0; i<ps; i++) {
		for (int j=0; j<ps; j++) {
			if (compat(pref[i], pref[j])) {
				mp[{i, j}] = k++;
				imp[k-1] = {i, j};
			}
		}
	}

	for (int i=0; i<ps; i++) {
		for (char j='a'; j<='z'; j++) {
			if (a.count(pref[i] + j)) {
				// moze reset
				rst[i][j-'a'] = 1;
			}

			// moze prefiks?
			auto it = find(begin(pref), end(pref), pref[i] + j);
			if (it != end(pref)) {
				pe[i][j-'a'] = it - begin(pref);
			}
		}
	}

	matrix<mint> ma(k);

	for (int i=0; i<k; i++) {
		auto [x, y] = imp[i];

		for (int c=0; c<26; c++) {
			for (int rx : {0, 1}) {

				if (rx ? !rst[x][c] : !pe[x][c]) {
					continue;
				}

				int xx = rx ? 0 : pe[x][c];

				for (int ry : {0, 1}) {
					if (ry ? !rst[y][c] : !pe[y][c]) {
						continue;
					}

					int yy = ry ? 0 : pe[y][c];

					auto it = mp.find({xx, yy});
					if (it != mp.end()) {
						ma[i][it->second] += 1;
					}
				}
			}
		}
	}

	cout << (ma ^ m)[0][0]() << "\n";
}