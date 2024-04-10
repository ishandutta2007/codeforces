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

template<class T> struct mod_int {
	static constexpr int mod() { return T::mod; }

	int v;
	mod_int(long long _v = 0) 
		: v(norm(_v)) {}

	inline int norm(long long a) {
		return a < 0 ? a % mod() + mod() : a % mod();
	}
	mod_int neg() const { return v == 0 ? 0 : mod() - v; }

	template <typename U>
	explicit operator U() const { return v; }

	mod_int operator - () const { return neg(); }
	mod_int operator + () const { return mod_int(*this); }

	mod_int& operator -- () { if (v == 0) v = mod(); -- v; return *this; }
	friend mod_int operator -- (mod_int& a, int) { mod_int r = a; --a; return r; }
	mod_int& operator ++ () { ++ v; if (v == mod()) v = 0; return *this; }
	friend mod_int operator ++ (mod_int& a, int) { mod_int r = a; ++a; return r; }
	
#define defop(type, op) \
	friend inline type operator op (type a, const type &b) { return a op##= b; } \
	type& operator op##= (const type &oth)

	defop(mod_int, +) {
		if ((v += oth.v) >= mod()) v -= mod();
		return *this;
	}
	defop(mod_int, -) {
		if ((v -= oth.v) < 0) v += mod();
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
	mod_int inv() const { return pow(mod() - 2); }

	defop(mod_int, /) { 
		return *this *= oth.inv();
	}
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

const int N = 1e5 + 5;

int k, n, m, list_val[N << 2], cnt, nxt[N << 2][2];
pair<int, int> range[N][2];

inline int getp(int x) {
	return lower_bound(list_val + 1, list_val + cnt + 1, x) - list_val;
}

Mint dp[N << 2][3];

void Hollwo_Pelw() {
	cin >> k >> n >> m;
	for (int i = 1, l, r; i <= n; i++) {
		cin >> l >> r, range[i][0] = {-- l, r};
		list_val[++ cnt] = r;
		list_val[++ cnt] = l;
	}
	for (int i = 1, l, r; i <= m; i++) {
		cin >> l >> r, range[i][1] = {-- l, r};
		list_val[++ cnt] = r;
		list_val[++ cnt] = l;
	}
	list_val[++ cnt] = 0;
	list_val[++ cnt] = k;

	sort(list_val + 1, list_val + cnt + 1);
	cnt = unique(list_val + 1, list_val + cnt + 1) - list_val - 1;

	for (int i = 1; i <= cnt; i++)
		nxt[i][0] = nxt[i][1] = cnt + 1;
	for (int i = 1; i <= n; i++) {
		int l = getp(range[i][0].first), r = getp(range[i][0].second);
		range[i][0] = {l, r};
		nxt[l][0] = min(nxt[l][0], r);
	}
	for (int i = 1; i <= m; i++) {
		int l = getp(range[i][1].first), r = getp(range[i][1].second);
		range[i][1] = {l, r};
		nxt[l][1] = min(nxt[l][1], r);
	}

	for (int i = cnt; i; i--) {
		nxt[i - 1][0] = min(nxt[i - 1][0], nxt[i][0]);
		nxt[i - 1][1] = min(nxt[i - 1][1], nxt[i][1]);
	}

	dp[cnt][0] = dp[cnt][1] = dp[cnt][2] = 1;
	for (int i = cnt - 1; i; i--) {
		Mint f0 = dp[i + 1][0] - dp[nxt[i][0]][0];
		Mint f1 = dp[i + 1][1] - dp[nxt[i][1]][1];
		Mint f2 = dp[i + 1][2] * (Mint(2).pow(list_val[i + 1] - list_val[i]) - 2);

		dp[i][0] = dp[i + 1][0] + f1 + f2;
		dp[i][1] = dp[i + 1][1] + f0 + f2;
		dp[i][2] = f0 + f1 + f2;
	}

	cout << dp[1][2] << '\n';
}