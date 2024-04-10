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

#define defop(type, op) \
	friend inline type operator op (type a, const type &b) { return a op##= b; } \
	type& operator op##= (const type &oth)
 
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

const int N = 1e5 + 5, mod = 1e9 + 7;

Mint fac[N], ifac[N];

struct __init__ {
	__init__() {
		fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
		for (int i = 2; i < N; i++)
			ifac[i] = - (mod / i) * ifac[mod % i];
		for (int i = 2; i < N; i++) {
			ifac[i] *= ifac[i - 1] ;
			fac[i] = fac[i - 1] * i;
		}
	}
} __init__;

inline Mint C(int n, int k) {
	return n < k || k < 0 ? 0 : fac[n] * ifac[n - k] * ifac[k]; 
}

inline Mint ways(int n, int k) {
	return !n && !k ? 1 : C(n + k - 1, k - 1);
}

string l, r;
int d[2][2], c[2][2], sz = 1;


inline Mint okayge(const string &s) {
	if (sz != s.size()) return 0;
	memset(d, 0, sizeof d);

	for (int i = 1; i < sz; i++)
		d[s[i - 1] - '0'][s[i] - '0'] ++;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			if (c[i][j] ^ d[i][j]) return 0;
	return 1;
}

inline Mint solve(const string &s) {
	if (s.size() < sz) return 0;

#define calc(d) (ways(d[0][0], d[1][0]) * ways(d[1][1], d[0][1] + 1))

	memcpy(d, c, sizeof c);
	Mint res = calc(d);

	// cout << d[0][0] << ' ' << d[1][0] << ' ' << ways(d[0][0], d[1][0]) << '\n';
	// cout << d[1][1] << ' ' << d[0][1] << ' ' << ways(d[1][1], d[0][1] + 1) << '\n';

	if (s.size() > sz) return res;

	for (int i = 1; i < sz; i++) {
		int a = s[i - 1] - '0';
		-- d[a][1];
		if (s[i] == '1') continue ;
		// if s[i] = 0 => sus
		res -= calc(d);
		
		// cout << d[0][0] << ' ' << d[1][0] << ' ' << ways(d[0][0], d[1][0]) << '\n';
		// cout << d[1][1] << ' ' << d[0][1] << ' ' << ways(d[1][1], d[0][1] + 1) << '\n';

		++ d[a][1];
		-- d[a][0];

	}

	return res;

}
void Hollwo_Pelw() {
	cin >> l >> r;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cin >> c[i][j], sz += c[i][j];
	if (c[0][1] - c[1][0] != 0 && c[0][1] - c[1][0] != -1)
		return cout << 0, (void) 0;
	// cout << solve("10");
	cout << solve(r) - solve(l) + okayge(l);
}