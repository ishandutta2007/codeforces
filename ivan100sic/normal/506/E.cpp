#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned short x;

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
		x = ((unsigned)x * other.x) % m;
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

const int MOD = 10007;
typedef modint<MOD> mint;

template<class T, int N>
struct matrix {
	T a[N][N];
	int n;

	matrix(int _n = N) : n(_n) {
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				a[i][j] = T();
	}

	T* operator[] (int x) {
		return a[x];
	}

	const T* operator[] (int x) const {
		return a[x];
	}

	static matrix eye(int n = N) {
		matrix t(n);
		for (int i=0; i<n; i++)
			t[i][i] = 1;
		return t;
	}

	matrix operator* (const matrix& b) const {
#ifdef LOCAL
		if (n != b.n)
			throw "matrix size mismatch";	
#endif
		matrix c(n);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				for (int k=0; k<n; k++)
					c[i][k] += a[i][j] * b[j][k];
		return c;
	}

	matrix& operator*= (const matrix& b) {
		return *this = *this * b;
	}

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

	template<class U>
	matrix operator^= (U arg) {
		return *this = *this ^ arg;
	}
};

typedef matrix<mint, 402> mat;

void pmul(vector<mint>& b, int k) {
	b.emplace_back();
	for (int i=(int)b.size()-2; i>=0; i--)
		b[i+1] -= b[i] * k;
}

// hey at least I found this gf
struct gf {
	int q[3];
	vector<mint> b;

	gf(int x = 0) : b(1, x) {
		q[0] = q[1] = q[2] = 0;
	}

	void loop(int k) {
		q[k-24]++;
	}

	void extend(int k) {
		loop(k);
		pmul(b, k);
	}

	gf& operator+=(gf o) {
		for (int i=0; i<3; i++) {
			while (q[i] > o.q[i]) o.extend(i + 24);
			while (q[i] < o.q[i]) extend(i + 24);
		}
		b.resize(max(b.size(), o.b.size()));
		for (int i=0; i<(int)o.b.size(); i++)
			b[i] += o.b[i];
		while (b.size() && b.back() == 0)
			b.pop_back();
		return *this;
	}

	void mulx() {
		b.insert(b.begin(), mint(0));
	}

	mint coeff(int n) {
		vector<mint> kroz = {1};
		for (int i=0; i<3; i++)
			for (int j=0; j<q[i]; j++)
				pmul(kroz, i+24);
		mat a;

		for (int i=0; i<401; i++)
			a[i][i+1] += 1;
		for (int i=1; i<(int)kroz.size(); i++)
			a[i-1][0] -= kroz[i];

		a ^= n;
		mint ret = 0;
		for (int i=0; i<(int)b.size(); i++) {
			if (n < i)
				break;
			ret += b[i] * a[0][i];
		}
		return ret;
	}

	void dbg() {
		cerr << q[0] << ' ' << q[1] << ' ' << q[2] << '\n';
		for (int i=0; i<(int)b.size(); i++)
			cerr << (int)b[i] << ' ';
		cerr << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	int c = 0;
	map<pair<int, int>, int> mp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<=i; j++) {
			mp[{j, i-j}] = c++;
		}
	}
	mp[{0, n}] = c++;
	vector<gf> f(c);
	vector<vector<int>> par(c);
	vector<int> loops(c);

	for (auto [p, y] : mp) {
		for (char c='a'; c<='z'; c++) {
			auto [i, j] = p;
			int ii = i, jj = j;
			if (ii + jj != n) {
				if (s[ii] == c)
					ii++;
				if (s[n-1-jj] == c)
					jj++;
				if (ii+jj >= n)
					ii = 0, jj = n;
			}
			int z = mp[{ii, jj}];
			if (z == y)
				loops[y]++;
			else
			par[z].emplace_back(y);
		}
	}

	f[0] = gf(1);
	f[0].loop(loops[0]);

	for (int i=1; i<c; i++) {
		for (int j : par[i])
			f[i] += f[j];
		f[i].mulx();
		f[i].loop(loops[i]);
	}

	int m;
	cin >> m;
	m += n;

	gf solf;
	if (m % 2 == 0) {
		solf += f[c-1];
	} else {
		for (int i=0; i<26; i++)
			solf += f[c-1];
		for (int i=0; i<n; i++)
			solf += f[mp[{i, n-1-i}]];
	}

	cout << (int)solf.coeff(m / 2) << '\n';
}