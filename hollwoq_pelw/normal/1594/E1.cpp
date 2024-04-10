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

const int N = 65, mod = 1e9 + 7;

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

map<string, int> comp;
string color[6] = {"white", "yellow", "green", "blue", "red", "orange"}, s;

Mint dp[N];

map<pair<int64_t, int>, Mint> real_dp;
map<int64_t, int> col;
int n, m;

inline Mint get(int64_t u, int c) {
	if (real_dp.count({u, c}))
		return real_dp[{u, c}];
	return dp[n - (int) __lg(u)];
}

void Hollwo_Pelw() {
	for (int i = 0; i < 6; i++)
		comp[color[i]] = i;

	cin >> n;

	dp[1] = 1;
	for (int i = 2; i < N; i++)
		dp[i] = dp[i - 1] * dp[i - 1] * 16;
	
	set<int64_t> st;

	for (int64_t u; m --; ) {
		cin >> u >> s;
		col[u] = comp[s];
		st.insert(u);
	}

	while (!st.empty()) {
		auto it = -- st.end();
		int64_t u = *it; st.erase(it);
		for (int c = 0; c < 6; c++) {
			real_dp[{u, c}] = 0;
			if (col.count(u) && col[u] != c)
				continue ;
			if (__lg(u) == n - 1) {
				real_dp[{u, c}] = 1;
				continue ;	
			}
			Mint lef = 0, rig = 0;
			for (int i = 0; i < 6; i++) {
				if (i / 2 != c / 2) {
					lef += get(u << 1, i);
					rig += get(u << 1 | 1, i);
				}
			}
			real_dp[{u, c}] = lef * rig;
		}
		if (u > 1)
			st.insert(u >> 1);
	}

	Mint res = 0;
	for (int i = 0; i < 6; i++)
		res += get(1, i);
	cout << res;
}