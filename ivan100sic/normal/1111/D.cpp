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

const int M = 52;

struct seg {
	int l, r, w;
	bool operator< (const seg& b) const {
		if (w != b.w)
			return w > b.w;
		return l < b.l;
	}
};

basic_string<seg> segs;

void gen_rec_segments(int l, int r) {
	segs += seg{l, r, r-l};
	if (r-l > 1) {
		int m = (l+r) >> 1;
		gen_rec_segments(l, m);
		gen_rec_segments(m, r);
	}
}

basic_string<int> canonical_form(int n, int x, int y) {
	basic_string<int> b(M, 0), z;
	b[x] = b[y] = 1;
	for (auto [l, r, w] : segs) {
		if (count(b.begin()+l, b.begin()+r, 1) == 0) {
			for (int i=l; i<r; i++) {
				b[i] = 1;
				z += i;
			}
		}
	}
	return z;
}

struct trie_node {
	int nx[M], fx, fy;
} buff[40000]; int sz;

int cid(char x) {
	if (islower(x))
		return x - 'a';
	return x - 'A' + 26;
}

int a[M], h;
mint sol[M][M], globalsol;
mint f[100005], finv[100005];

mint bc(int x, int y) {
	return f[x+y] * finv[x] * finv[y];
}

int adp_calls;

vector<mint> advance_dp(const vector<mint>& dp, int v, int z) {
	adp_calls++;

	if (v == 0)
		return dp;

	vector<mint> dpy(h+1, 0);
	for (int j=0; j<=min(h, z); j++) {
		if ((int)dp[j] == 0)
			continue;
		if (j + v <= h)
			dpy[j + v] += dp[j];
		dpy[j] += dp[j];
	}
	return dpy;
}

void resi(const vector<mint>& dp, int x, int z) {
	int fx = buff[x].fx;
	int fy = buff[x].fy;
	if (fy) {
		if (fx == -1)
			globalsol = dp[h];
		else
			sol[fx][fy] = advance_dp(dp, a[fx] + a[fy], z)[h];
	}

	for (int i=0; i<M; i++) {
		int y = buff[x].nx[i];
		if (y)
			resi(advance_dp(dp, a[i], z), y, z + a[i]);
	}
}

void trie_add(basic_string<int> v, int i, int j) {
	int r = 0;
	for (int x : v) {
		int& r2 = buff[r].nx[x];
		if (!r2) r2 = ++sz;
		r = r2;
	}
	buff[r].fx = i;
	buff[r].fy = j;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = finv[0] = 1;
	for (int i=1; i<100005; i++) {
		f[i] = f[i-1] * i;
		finv[i] = f[i].inv();
	}

	gen_rec_segments(0, M);
	sort(segs.begin(), segs.end());

	for (int i=0; i<M; i++)
		for (int j=i+1; j<M; j++)
			trie_add(canonical_form(M, i, j), i, j);

	basic_string<int> sve(M, 0);
	iota(sve.begin(), sve.end(), 0);
	trie_add(sve, -1, -1);

	string s;
	cin >> s;
	for (char x : s)
		a[cid(x)]++;

	h = s.size() / 2;

	vector<mint> init_dp(h+1, 0);
	init_dp[0] = 1;

	resi(init_dp, 0, 0);

	mint pp = f[h] * f[h];
	for (int i=0; i<M; i++)
		pp *= finv[a[i]];

	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x = cid(s[x-1]);
		y = cid(s[y-1]);
		if (x > y)
			swap(x, y);
		if (x == y)
			cout << (int)(pp * globalsol) << '\n';
		else
			cout << (int)(pp * sol[x][y]) << '\n';
	}
}