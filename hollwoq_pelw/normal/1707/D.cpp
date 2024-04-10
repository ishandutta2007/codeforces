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
	// cin >> testcases;
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

// struct modular { static constexpr int mod = static_cast<int>(1e9 + 7); };

struct modular { static int mod; }; int modular::mod = 1;

using Mint = mod_int<modular>;

const int N = 2005;


Mint C[N][N], dp[N][N], f[N][N], pre[N][N], suf[N][N];
int n;
vector<int> adj[N];

void solve(int u, int p) {
	int m = 0, c = 0;
	for (int v : adj[u]) if (v != p)
		solve(v, u), m ++;

	// cout << "solve " << u << '\n';

	if (!m) {
		for (int i = 1; i < n; i++)
			dp[u][i] = 1, f[u][i] = i;
		// for (int i = 1; i < n; i++)
		// 	cout << dp[u][i] << " \n"[i == n - 1];
		return ;
	}

	c = 0;
	for (int v : adj[u]) if (v != p) {
		++ c;
		for (int i = 1; i < n; i++)
			pre[i][c] = suf[i][c] = f[v][i];
	}
	for (int i = 1; i < n; i++)
		pre[i][0] = suf[i][m + 1] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++)
			pre[i][j] *= pre[i][j - 1];
		for (int j = m; j >= 1; j--)
			suf[i][j] *= suf[i][j + 1];
	}

	for (int i = 1; i < n; i++) {
		dp[u][i] = pre[i][m];
	}

	// for (int i = 1; i < n; i++)
	// 	cout << dp[u][i] << " \n"[i == n - 1];

	c = 0;
	if (u != 1)  for (int v : adj[u]) if (v != p) {
		Mint sum = 0; ++ c;
		for (int i = 1; i < n; i++) {
			// cout << sum << '\n';
			dp[u][i] += dp[v][i] * sum;
			sum += pre[i][c - 1] * suf[i][c + 1];
		}
	}

	// for (int i = 1; i < n; i++)
	// 	cout << dp[u][i] << " \n"[i == n - 1];

	for (int i = 1; i < n; i++)
		f[u][i] = dp[u][i] + f[u][i - 1];
}

void Hollwo_Pelw(){
	cin >> n >> modular::mod;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	solve(1, 0);

	for (int i = 0; i <= n; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}

	for (int i = 1; i < n; i++) {
		Mint res = 0;
		for (int j = 1; j <= i; j++)
			res += ((i - j) & 1 ? -1 : 1) * dp[1][j] * C[i][j];
		cout << res << ' ';
	}
}