#include <bits/stdc++.h>
using namespace std;

void __main__();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	
	// int test = 1; for (cin >> test; test --; )
		__main__();
}

template<class T> struct mod_int {
	static constexpr int mod() { return T::mod; }

	int v;
	mod_int(long long _v = 0) : v(norm(_v)) {}

	inline int norm(long long a) { return a < 0 ? a % mod() + mod() : a % mod(); }
	mod_int neg() const { return v == 0 ? 0 : mod() - v; }

	template <typename U> explicit operator U() const { return v; }
	mod_int operator - () const { return neg(); }
	mod_int operator + () const { return mod_int(*this); }
	mod_int& operator -- () { if (v == 0) v = mod(); -- v; return *this; }
	friend mod_int operator -- (mod_int& a, int) { mod_int r = a; --a; return r; }
	mod_int& operator ++ () { ++ v; if (v == mod()) v = 0; return *this; }
	friend mod_int operator ++ (mod_int& a, int) { mod_int r = a; ++a; return r; }
	
#define defop(type, op) \
	friend inline type operator op (type a, const type &b) { return a op##= b; } \
	type& operator op##= (const type &oth)

	defop(mod_int, +) { if ((v += oth.v) >= mod()) v -= mod(); return *this; }
	defop(mod_int, -) { if ((v -= oth.v) < 0) v += mod(); return *this; }
	defop(mod_int, *) { return *this = norm(1ll * v * oth.v); }
	defop(mod_int, /) { return *this *= oth.inv(); }

	inline mod_int pow(long long b) const {
		mod_int a = *this, r = 1;
		for (; b; b >>= 1, a *= a)
			if (b & 1) r *= a;
		return r;
	}
	inline mod_int inv() const { return pow(mod() - 2); }

#undef defop

#define compare(op) friend bool operator op \
(const mod_int& lhs, const mod_int& rhs) { return lhs.v op rhs.v; }
	compare(==) compare(!=) compare(<) compare(<=) compare(>) compare(>=)
#undef compare

	friend std::ostream& operator << (std::ostream& out, const mod_int& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& inp, mod_int& n) { long long x; inp >> x; n = mod_int(x); return inp; }
};

struct modular { static constexpr int mod = static_cast<int>(1e9 + 7); };

// struct modular { static int mod; };
// int modular::mod;

using Mint = mod_int<modular>;

const int N = 2e5 + 5;

int n, k, siz[N];
vector<int> adj[N];
Mint fac[N], inv[N], res;

inline Mint C(int n, int k) {
	return (k > n || k < 0) ? 0 : fac[n] * inv[k] * inv[n - k];
}

void pre_dfs(int u, int p) {
	siz[u] = 1;
	for (int v : adj[u])
		if (v != p) {
			pre_dfs(v, u);
			siz[u] += siz[v];
		}
}

void __solve__(int u, int p) {
	Mint tot = 0;
	for (int v : adj[u])
		tot += C(siz[v], k);

	res += (C(n, k) - tot) * n;
	for (int v : adj[u]) {
		res += (C(n - siz[v], k) - (tot - C(siz[v], k))) * (n - siz[v]) * siz[v];
	}

	for (int v : adj[u]) if (v != p) {
		siz[u] -= siz[v];
		siz[v] += siz[u];
		__solve__(v, u);
		siz[v] -= siz[u];
		siz[u] += siz[v];
	}
}

void __main__() {
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i, inv[i] = inv[i - 1] / i;

	pre_dfs(1, 0);
	__solve__(1, 0);

	cout << res;
}