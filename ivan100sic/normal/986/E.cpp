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


const int SITO_MAX = 10'000'000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<pair<int, int>> factor_small(int x) {
	vector<pair<int, int>> v;
	while (x > 1) {
		int p = f[x];
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		v.push_back({p, c});
	}
	return v;
}

vector<pair<int, int>> factor(int x) {
	vector<pair<int, int>> v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v.push_back({p, c});
		}			
	}

	if (x > 1) {
		v.push_back({x, 1});
	}
	return v;
}

struct upit {
	int u, v, x;
	mint ans;
};

int n, q;
basic_string<int> e[100005];
vector<pair<int, int>> ask[100005];
int p[100005][18];
int a[100005];
int dub[100005];
upit u[100005];

void dfs1(int x, int par) {
	p[x][0] = par;
	for (int i=1; i<18; i++)
		p[x][i] = p[p[x][i-1]][i-1];
	for (int y : e[x]) {
		if (y == par)
			continue;
		dub[y] = dub[x] + 1;
		dfs1(y, x);
	}
}

int dizi(int x, int k) {
	for (int i=0; i<18; i++)
		if (k & (1 << i))
			x = p[x][i];
	return x;
}

int lca(int x, int y) {
	if (dub[x] > dub[y])
		swap(x, y);
	y = dizi(y, dub[y] - dub[x]);
	if (x == y)
		return x;
	for (int i=17; i>=0; i--) {
		int xx = p[x][i];
		int yy = p[y][i];
		if (xx != yy)
			x = xx, y = yy;
	}
	return p[x][0];
}

int pid[10000005];
int c[666666][24], hi[666666];

void dfs2(int x, int p) {
	auto v = factor_small(a[x]);
	for (auto [r, b] : v)
		c[pid[r]][b]++, hi[pid[r]] = max(hi[pid[r]], b);

	for (auto [i, sgn] : ask[x]) {
		auto w = factor_small(u[i].x);
		mint t = 1;
		for (auto [r, b] : w) {
			for (int i=1; i<=hi[pid[r]]; i++)
				t *= mint(r) ^ (min(b, i) * c[pid[r]][i]);

		}
		u[i].ans *= t ^ (MOD - 1 + sgn);
	}

	for (int y : e[x]) {
		if (y != p) {
			dfs2(y, x);
		}
	}

	for (auto [r, b] : v)
		c[pid[r]][b]--;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	{
		int z = 0;
		for (int p : prosti)
			pid[p] = z++;
	}

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs1(1, 1);

	for (int i=1; i<=n; i++)
		cin >> a[i];

	cin >> q;
	for (int i=0; i<q; i++) {
		int& x = u[i].u;
		int& y = u[i].v;
		cin >> x >> y >> u[i].x;
		int z = lca(x, y);
		if (z == x || z == y) {
			ask[dub[x] > dub[y] ? x : y].emplace_back(i, 1);
			if (z != 1) {
				ask[p[z][0]].emplace_back(i, -1);
			}
		} else {
			ask[x].emplace_back(i, 1);
			ask[y].emplace_back(i, 1);
			ask[z].emplace_back(i, -1);
			if (z != 1) {
				ask[p[z][0]].emplace_back(i, -1);
			}
		}
			
		u[i].ans = 1;
	}

	dfs2(1, 1);

	for (int i=0; i<q; i++)
		cout << (int)u[i].ans << "\n";
}