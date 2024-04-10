#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
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
	friend mod_int operator -- (mod_int& a, signed) { mod_int r = a; --a; return r; }
	mod_int& operator ++ () { ++ v; if (v == mod()) v = 0; return *this; }
	friend mod_int operator ++ (mod_int& a, signed) { mod_int r = a; ++a; return r; }
	
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

struct modular { static constexpr int mod = static_cast<int>(998244353); };

// struct modular { static int mod; }; int modular::mod;

using Mint = mod_int<modular>;

const int N = 1e3 + 5;

Mint dp[N];
vector<int> adj[N];
int n, m, a[N], vis[N];

void calc(int u) {
	dp[u] = adj[u].empty() ? 1 : 0;
	vis[u] = 1;
	for (int v : adj[u]) 
		if (!vis[v]) calc(v);
	for (int v : adj[u])
		dp[u] += dp[v];
}

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], adj[i].clear(), vis[i] = 0;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) calc(i);
	for (int turn = 0; turn < n; turn ++) {
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			if (a[i]) v.push_back(i);
		}
		if (v.empty())
			return cout << turn << '\n', (void) 0;
		for (int x : v) {
			a[x] --;
			for (int y : adj[x])
				a[y] ++;
		}
	}
	// cout << "dp -> ";
	// for (int i = 1; i <= n; i++)
	// 	cout << dp[i] << " \n"[i == n];
	// for (int i = 1; i <= n; i++)
	// 	cout << a[i] << " \n"[i == n];
	Mint res = n;
	for (int i = 1; i <= n; i++)
		res += dp[i] * a[i];
	cout << res << '\n';
}