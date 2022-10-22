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

struct modular { static constexpr int mod = static_cast<int>(998244353); };

// struct modular { static int mod; };
// int modular::mod;

using Mint = mod_int<modular>;

const int N = 1.5e5 + 5, L = 30, M = N * L;

Mint pw[N];

inline Mint solve_until(const vector<int> &a, const vector<int> &b, int bt, int x) {
	if (a.empty() || b.empty() || bt < 0)
		return pw[a.size() + b.size()] - 1;
	vector<int> na[2], nb[2];
	for (int v : a)
		na[v >> bt & 1].push_back(v);
	for (int v : b)
		nb[v >> bt & 1].push_back(v);
	if (x >> bt & 1) {
		x ^= 1 << bt;
		return (solve_until(na[0], nb[1], bt - 1, x) + 1)
			 * (solve_until(na[1], nb[0], bt - 1, x) + 1) - 1;
	}
	return solve_until(na[0], nb[0], bt - 1, x)
		 + solve_until(na[1], nb[1], bt - 1, x)
		 + (pw[na[0].size()] - 1) * (pw[na[1].size()] - 1)
		 + (pw[nb[0].size()] - 1) * (pw[nb[1].size()] - 1);
}

inline Mint solve(const vector<int> &a, int bt, int x) {
	if (a.empty() || bt < 0)
		return pw[a.size()] - 1;
	vector<int> na[2];
	for (int v : a)
		na[v >> bt & 1].push_back(v);
	if (x >> bt & 1) {
		return solve_until(na[0], na[1], bt - 1, x);
	}
	return solve(na[0], bt - 1, x) + solve(na[1], bt - 1, x);
}

void Hollwo_Pelw() {
	int n, x; cin >> n >> x;
	pw[0] = 1;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pw[i + 1] = pw[i] * 2;
	}
	sort(a.begin(), a.end());

	cout << solve(a, 29, x);
}