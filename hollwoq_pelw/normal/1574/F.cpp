/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 3e5 + 5, mod = 998244353;

#define defop(type, op) \
	friend inline type operator op (type a, const type &b) { return a op##= b; } \
	type& operator op##= (const type &oth)

template<int mod> struct mod_int {
	int v;
	mod_int(long long _v = 0) 
		: v(norm(_v)) {}
	
	inline int norm(long long a) {
		return a < 0 ? a % mod + mod : a % mod;
	}
	mod_int neg() const { return v == 0 ? 0 : mod - v; }
	
	template <typename T>
	explicit operator T() const { return v; }	

	mod_int operator - () const { return neg(); }
	mod_int operator + () const { return mod_int(*this); }

	mod_int& operator -- () { if (v == 0) v = mod; -- v; return *this; }
	friend mod_int operator -- (mod_int& a, int) { mod_int r = a; --a; return r; }
	mod_int& operator ++ () { ++ v; if (v == mod) v = 0; return *this; }
	friend mod_int operator ++ (mod_int& a, int) { mod_int r = a; ++a; return r; }
	
	defop(mod_int, +) {
		if ((v += oth.v) >= mod) v -= mod;
		return *this;
	}
	defop(mod_int, -) {
		if ((v -= oth.v) < 0) v += mod;
		return *this;
	}
	defop(mod_int, *) {
		return *this = norm(1ll * v * oth.v);
	}

	mod_int pow(long long b) const {
		mod_int a = *this, r = 1;
		while (b) {
			if (b&1) r *= a;
			b >>= 1; a *= a;
		}
		return r;
	}
	mod_int inv() const { return pow(mod - 2); }

	defop(mod_int, /) { 
		return *this *= oth.inv();
	}

	friend std::ostream& operator << (std::ostream& out, const mod_int& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& inp, mod_int& n) { long long x; inp >> x; n = mod_int(x); return inp; }
};

using Mint = mod_int<mod>;

int n, m, k, a[N], cnt[N];
vector<int> prv[N], nxt[N];

bool vis[N], bad[N];

Mint dp[N];

void Hollwo_Pelw() {
	cin >> n >> m >> k;
	for (int i = 1, c; i <= n; i++) {
		cin >> c;
		for (int j = 0; j < c; j++)
			cin >> a[j];
		if (set<int>(a, a + c).size() != c) {
			for (int j = 0; j < c; j++)
				bad[a[j]] = 1;
			continue ;
		}
		for (int j = 1; j < c; j++) {
			prv[a[j]].push_back(a[j - 1]);
			nxt[a[j - 1]].push_back(a[j]);
		}
	}

	for (int i = 1; i <= k; i++) {
		sort(prv[i].begin(), prv[i].end());
		sort(nxt[i].begin(), nxt[i].end());

		prv[i].erase(unique(prv[i].begin(), prv[i].end()), prv[i].end());
		nxt[i].erase(unique(nxt[i].begin(), nxt[i].end()), nxt[i].end());
	}

	for (int i = 1; i <= k; i++) if (!vis[i]) {
		vector<int> comp;
		queue<int> q; q.push(i), vis[i] = 1;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			comp.push_back(u);
			for (auto v : nxt[u])
				if (!vis[v]) q.push(v), vis[v] = 1;
			for (auto v : prv[u])
				if (!vis[v]) q.push(v), vis[v] = 1;
			// cout << u << ' ';
		}
		// cout << '\n';
		int cntend = 0;
		bool ok = 1;
		for (auto v : comp) {
			if (prv[v].empty()) cntend ++;
			if (prv[v].size() > 1 || nxt[v].size() > 1 || bad[v]) ok = 0;
		}
		if (cntend > 0 && ok)
			cnt[comp.size()] ++;
	}
	dp[0] = 1;
	vector<int> chain;
	for (int i = 1; i <= k; i++)
		if (cnt[i] > 0) chain.push_back(i);
	for (int i = 1; i <= m; i++)
		for (auto j : chain) if (i >= j)
			dp[i] += dp[i - j] * cnt[j];
	cout << dp[m] << '\n'; 
}