#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct mexer {
	int a[4];

	mexer() {
		fill(a, a+4, 0);
	}

	void add(int x) {
		a[x] = 1;
	}
	int get() {
		return find(a, a+4, 0) - a;
	}
};

tuple<int, int, int> trojka_map[64];
int trojka_inv[4][4][4];

void nadji_trojke() {
	vector<tuple<int, int, int>> q;
	int seen[4][4][4];
	memset(seen, 0, sizeof(seen));
	seen[0][0][0] = 1;
	seen[3][3][3] = 1;
	q.emplace_back(0, 0, 0);
	q.emplace_back(3, 3, 3);
	size_t qs = 0;
	while (qs != q.size()) {
		auto [x, y, z] = q[qs++];
		for (int mask=0; mask<8; mask++) {
			mexer mx;
			if (mask & 1) mx.add(x);
			if (mask & 2) mx.add(y);
			if (mask & 4) mx.add(z);

			int t = mx.get();
			if (!seen[y][z][t]) {
				q.emplace_back(y, z, t);
				seen[y][z][t] = 1;
			}
		}
	}
	cerr << q.size() << '\n';
	for (int i=0; i<50; i++) {
		trojka_map[i] = q[i];
		auto [x, y, z] = q[i];
		trojka_inv[x][y][z] = i;
	}
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
			for (int j=0; j<n; j++) {
				ll zbir = 0;
				for (int k=0; k<n; k++) {
					zbir += (ll)(int)a[i][k] * (int)b[k][j];
					if ((k & 7) == 7)
						zbir %= MOD;
				}
				c[i][j] = zbir;
			}
		return c;
	}

	matrix operator+ (const matrix& b) const {
#ifdef LOCAL
		if (n != b.n)
			throw "matrix size mismatch";	
#endif
		matrix c(n);
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				c[i][j] = a[i][j] + b[i][j];
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

typedef matrix<mint, 50> mat;

// 10k mnozenja matrica 48x48: 5616ms na CF
int n, m;
int a[1005];
int f[4][4];
vector<pair<int, int>> e[1005];

mat jedan[1005], hiljadu[1005], milion[1005];
mat boja[4];

void pcp() {
	for (int c=1; c<=3; c++) {
		for (int i=0; i<50; i++) {
			auto [x, y, z] = trojka_map[i];
			mexer mx;
			if (f[c][1]) mx.add(z);
			if (f[c][2]) mx.add(y);
			if (f[c][3]) mx.add(x);

			int t = mx.get();
			int j = trojka_inv[y][z][t];
			boja[c][i][j] += 1;
		}
	}

	boja[0] = boja[1] + boja[2] + boja[3];

	milion[0] = hiljadu[0] = jedan[0] = mat::eye();
	for (int i=1; i<=1000; i++)
		jedan[i] = jedan[i-1] * boja[0];
	for (int i=1; i<=1000; i++)
		hiljadu[i] = hiljadu[i-1] * jedan[1000];
	for (int i=1; i<=1000; i++)
		milion[i] = milion[i-1] * hiljadu[1000];
}

mat stepen(int k) {
	return jedan[k % 1000] * hiljadu[k / 1000 % 1000] * milion[k / 1000000];
}

mint ways[1005][4];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	nadji_trojke();

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	cin >> m;
	for (int j=0; j<m; j++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		e[x].emplace_back(y, z);
	}
	for (int i=1; i<=3; i++)
		for (int j=1; j<=3; j++)
			cin >> f[i][j];
	
	pcp();

	const int nista = trojka_inv[3][3][3];

	for (int i=0; i<n; i++) {
		auto& v = e[i];
		sort(v.begin(), v.end());
		mat p;
		if (v.size()) {
			p = stepen(v[0].first) * boja[v[0].second]; 
			for (int j=1; j<(int)v.size(); j++) {
				p *= stepen(v[j].first - v[j-1].first - 1);
				p *= boja[v[j].second];
			}
			p *= stepen(a[i] - 1 - v.back().first);
		} else {
			p = stepen(a[i]);
		}

		for (int j=0; j<50; j++) {
			auto [x, y, z] = trojka_map[j];
			ways[i][z] += p[nista][j];
		}
	}

	vector<mint> dp(4);
	dp[0] = 1;

	for (int i=0; i<n; i++) {
		vector<mint> nu(4);
		for (int j=0; j<4; j++)
			for (int k=0; k<4; k++)
				nu[j^k] += dp[j] * ways[i][k];
		swap(dp, nu);
	}

	cout << (int)dp[0] << '\n';

}