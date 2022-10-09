#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[300005], freq[300005], aa[300005];
basic_string<int> e[300005];

void no() {
	cout << "0\n";
	exit(0);
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

const int MOD = 998244353;
typedef modint<MOD> mint;

pair<int, int> dfs1(int x, int p) {
	basic_string<pair<int, int>> rz;
	for (int y : e[x]) {
		if (y != p) {
			rz += dfs1(y, x);
		}
	}
	if (a[x] == 0) {
		int b = 0;
		for (auto [p, q] : rz) {
			if (p > 0) {
				if (b == 0)
					b = p;
				else if (b != p)
					no();
			}
		}

		if (b == 0) {
			return {0, 0};
		} else {
			aa[x] = b;
			int c = 0;
			for (auto [p, q] : rz) {
				if (p > 0) {
					c += q;
				}
			}
			if (c == freq[b])
				return {0, 0};
			return {b, c};
		}
	} else {
		aa[x] = a[x];
		int c = 1;
		for (auto [p, q] : rz) {
			if (p > 0 && p != a[x]) {
				no();
			} else if (p > 0) {
				c += q;
			}
		}
		if (c == freq[a[x]])
			return {0, 0};
		return {a[x], c};
	}
}

// odredi povezane komponente i nadji stablo broj 2
// uradi dinamicko nad time

int m;
basic_string<int> f[300005];
bool h[300005];
int color_to_node[300005];
int node_to_node[300005];

int ntn(int x) {
	if (node_to_node[x])
		return node_to_node[x];

	if (aa[x] == 0) {
		return node_to_node[x] = ++m;
	} else if (color_to_node[aa[x]]) {
		return node_to_node[x] = color_to_node[aa[x]];
	} else {
		return node_to_node[x] = color_to_node[aa[x]] = ++m;
	}
}

void napravi_drvo() {
	for (int x=1; x<=n; x++) {
		int xx = ntn(x);
		for (int y : e[x]) {
			int yy = ntn(y);
			if (xx != yy) {
				f[xx] += yy;
			}
		}
		h[xx] = aa[x] > 0;
	}

	// for (int i=1; i<=n; i++)
	// 	cerr << i << " -> " << ntn(i) << '\n';
	// for (int i=1; i<=m; i++)
	// 	cerr << h[i] << "\0\n"[i == m];
}

mint d0[300005], d1[300005];

void dfs2(int x, int p) {

	basic_string<int> ch;
	for (int y : f[x]) {
		if (y == p)
			continue;
		ch += y;
		dfs2(y, x);
	}

	int r = ch.size();
	
	if (h[x]) {
		mint prod = 1;
		for (int y : ch)
			prod *= d0[y] + d1[y];
		d1[x] = prod;
		d0[x] = 0;
	} else {
		mint prod = 1;
		for (int y : ch)
			prod *= d0[y] + d1[y];
		d0[x] = prod;

		if (r > 0) {
			basic_string<mint> pref(r, 0), suff(r, 0);

			pref[0] = (d1[ch[0]] + d0[ch[0]]);
			for (int i=1; i<r; i++)
				pref[i] = pref[i-1] * (d1[ch[i]] + d0[ch[i]]);

			suff[r-1] = (d1[ch[r-1]] + d0[ch[r-1]]);
			for (int i=r-2; i>=0; i--)
				suff[i] = suff[i+1] * (d1[ch[i]] + d0[ch[i]]);

			for (int i=0; i<r; i++) {
				mint prod = d1[ch[i]];
				if (i > 0)
					prod *= pref[i-1];
				if (i < r-1)
					prod *= suff[i+1];
				d1[x] += prod;
			}
		} else {
			// nemoguce
			d1[x] = 0;
		}
	}

	// cerr << x << ' ' << (int)d0[x] << ' ' << (int)d1[x] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		freq[a[i]]++;
	}
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	dfs1(1, 1);
	napravi_drvo();
	dfs2(m, m);
	cout << (int)d1[m] << '\n';
}