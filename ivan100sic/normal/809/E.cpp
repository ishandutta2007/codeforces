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

template<class T = int, class F = plus<T>>
struct sparse_table {
	vector<vector<T>> d;
	T e;
	F f;

	sparse_table(vector<T> a, T e = T(), F f = F()) : e(e), f(f) {
		d.push_back(a);
		int n = a.size();
		for (int h=1; h*2<=n; h<<=1) {
			int m = a.size() - h;
			vector<T> b(m);
			for (int i=0; i<m; i++)
				b[i] = f(a[i], a[i+h]);
			d.push_back(b);
			swap(a, b);
		}
	}

	T operator() (int l, int r) const {
		if (l >= r) return e;
		int i = 31 - __builtin_clz(r-l);
		return f(d[i][l], d[i][r-(1<<i)]);
	}
};

struct par {
	int x = 123123123, i = -1;
	template<class T>
	auto operator+ (const T& b) const {
		return x < b.x ? *this : b;
	}
};

int n;
basic_string<int> e[200005], divs[200005];
int a[200005];
int phi[200005];

int tl[200005], tr[200005], dt, d[200005], tlca[200005];

void dfs(int x, int p, vector<par>& vt) {
	tlca[x] = vt.size();
	vt.push_back({d[x], x});
	tl[x] = dt++;
	for (int y : e[x]) {
		if (y == p) continue;
		d[y] = d[x] + 1;
		dfs(y, x, vt);
		vt.push_back({d[x], x});
	}
	tr[x] = dt;
}

vector<vector<pair<int, int>>> gg;

int remap[200005];
mint vv[200005];
mint vals[200005];

pair<mint, mint> resi(int x, mint sve) {
	mint sol = 0, c = 0;
	for (auto [y, l] : gg[x]) {
		auto [subsol, subc] = resi(y, sve);
		sol += subsol;
		c += subc;
		sol += subc * (sve - subc) * l;
	}
	return {sol, c + vv[x]};
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	iota(phi, phi+n+1, 0);
	for (int i=1; i<=n; i++)
		for (int j=2*i; j<=n; j+=i)
			phi[j] -= phi[i];
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j+=i)
			divs[j] += i;

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		u = a[u], v = a[v];
		e[u] += v, e[v] += u;
	}

	vector<par> vt;
	dfs(1, 0, vt);
	sparse_table tbl(vt);

	auto cmp_dfs = [&](int x, int y) {
		return tl[x] < tl[y];
	};

	auto above = [&](int x, int y) {
		return tl[x] <= tl[y] && tr[y] <= tr[x];
	};

	auto lca = [&](int x, int y) {
		return tbl(tlca[x], tlca[y]).i;
	};

	for (int g=1; g<=n; g++) {
		vector<int> v0, v1;
		for (int x=g; x<=n; x+=g)
			v0.push_back(x);
		sort(begin(v0), end(v0), cmp_dfs);

		v1 = v0;
		for (int i=1; i<(int)v0.size(); i++)
			v1.push_back(lca(v0[i-1], v0[i]));

		sort(begin(v1), end(v1), cmp_dfs);
		v1.erase(unique(begin(v1), end(v1)), end(v1));


		gg.assign(v1.size(), {});
		int mm = v1.size();
		for (int i=0; i<mm; i++)
			remap[v1[i]] = i;

		vector<int> st;
		for (int x : v1) {
			vv[remap[x]] = 0;
			while (st.size() && !above(st.back(), x))
				st.pop_back();
			if (st.size()) {
				int y = st.back();
				gg[remap[y]].emplace_back(remap[x], d[x] - d[y]);
			}
			st.push_back(x);
		}

		for (int x : v0)
			vv[remap[x]] = phi[x];

		mint sve = 0;
		for (int x : v1)
			sve += vv[remap[x]];

		vals[g] = resi(0, sve).first;
	}

	for (int i=n; i>=1; i--)
		for (int j=2*i; j<=n; j+=i)
			vals[i] -= vals[j];

	mint sol = 0;
	for (int i=1; i<=n; i++)
		sol += vals[i] * i * mint(phi[i]).inv();

	cout << (sol * 2 * (mint(n-1)*n).inv())() << '\n';
}