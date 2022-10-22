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

const int N = 1e6 + 5, K = 3e5 + 5, mod = 998244353;

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
/*
zigzag row => 2^(not fix row)
	1010101
	1010101 -> fix ?
	0101010
zigzag col => 2^(not fix row)
	0101101
	1010010
	0101101
zigzag both => 2^(not fix)
	010101
	101010
	010101
*/

struct count_fix {
	int cnt[N][2], res, ans; // res = number of 1zer, ans = number of 2zer
	inline void del(int x, int y, int t) {
		ans -= (cnt[x][0] != 0) && (cnt[x][1] != 0);
		res -= (cnt[x][0] != 0) || (cnt[x][1] != 0);
		cnt[x][(y & 1) ^ t] --;
		ans += (cnt[x][0] != 0) && (cnt[x][1] != 0);
		res += (cnt[x][0] != 0) || (cnt[x][1] != 0);
	}
	inline void add(int x, int y, int t) {
		ans -= (cnt[x][0] != 0) && (cnt[x][1] != 0);
		res -= (cnt[x][0] != 0) || (cnt[x][1] != 0);
		cnt[x][(y & 1) ^ t] ++;
		ans += (cnt[x][0] != 0) && (cnt[x][1] != 0);
		res += (cnt[x][0] != 0) || (cnt[x][1] != 0);
	}
	inline Mint calc(int n) {
		return ans ? 0 : Mint(2).pow(n - res);
	}
} fcol, frow;

map<pair<int, int>, int> mp;
int cnt[2];

void do_erase(int x, int y) {
	int t = mp[{x, y}];
	frow.del(x, y, t), fcol.del(y, x, t);
	mp.erase({x, y});
	cnt[(x ^ y ^ t) & 1] --;
}

void do_insert(int x, int y, int t) {
	frow.add(x, y, t), fcol.add(y, x, t);
	mp[{x, y}] = t;
	cnt[(x ^ y ^ t) & 1] ++;
}

Mint get_both() {
	if (mp.empty()) return 2;
	return !(frow.ans || fcol.ans) && (cnt[0] == 0 || cnt[1] == 0);
}

int n, m, k;

void Hollwo_Pelw() {
	cin >> n >> m >> k;
	for (int x, y, t; k --; ) {
		cin >> x >> y >> t;
		if (t == -1) {
			if (mp.count({x, y}))
				do_erase(x, y);
		} else {
			if (mp.count({x, y}))
				do_erase(x, y);
			do_insert(x, y, t);
		}
		// cout << frow.calc(n) << ' ';
		// cout << fcol.calc(m) << ' ';
		Mint res = frow.calc(n) + fcol.calc(m) - get_both();
		// cout << res + get_both() << " : ";
		cout << res << '\n';
	}
}