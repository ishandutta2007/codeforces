// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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

const int SITO_MAX = 1000005;

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

int n, m;
int a[200005];
vector<pair<int, int>> v[200005];
int l[200005], r[200005];
int u[200005];

int c[1000005];
mint w = 1, inv[1000005], z[200005];
mint tle[1000005], tle_inv[1000005];
int ans[200005], tl = 1, tr = 0;

void aa(int p, int e) {
	if (c[p] == 0)
		w *= tle[p];
	c[p] += e;
}

void rr(int p, int e) {
	if (e == c[p])
		w *= tle_inv[p];
	c[p] -= e;
}

void add(int i) {
	for (auto [p, e] : v[i]) {
		aa(p, e);
	}
}

void rem(int i) {
	for (auto [p, e] : v[i]) {
		rr(p, e);
	}
}

// da vidimo koliko je 9.2.0 64bit brzi

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=1; i<1000005; i++) {
		inv[i] = mint(i).inv();
		if (f[i] == i) {
			tle[i] = inv[i] * (i-1);
			tle_inv[i] = inv[i-1] * i;
		}
	}

	z[0] = 1;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i], v[i] = factor_small(a[i]), z[i] = z[i-1] * a[i];
	cin >> m;
	for (int i=0; i<m; i++)
		cin >> l[i] >> r[i], u[i] = i;

	sort(u, u+m, [&](int x, int y) {
		int a = l[x] >> 9, b = l[y] >> 9;
		if (a != b)
			return a < b;
		return r[x] < r[y];
	});

	for (int i=0; i<m; i++) {
		int j = u[i];
		int l = ::l[j], r = ::r[j];
		while (tr < r) add(++tr);
		while (tl > l) add(--tl);
		while (tr > r) rem(tr--);
		while (tl < l) rem(tl++);
		ans[j] = (int)(w * z[r] * z[l-1].inv());
	}

	for (int i=0; i<m; i++)
		cout << ans[i] << '\n';
}

// I will still practice daily...