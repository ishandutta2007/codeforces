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
	FAST_IO("C.inp", "C.out");
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

const int N = 2e5 + 5, K1 = 51, K2 = 52, K = 55;

Mint a[N], pre[N];
Mint pre1[N], coef1[N][K];
Mint pre2[N], coef2[N][K];
Mint C[K][K], pw[N][K];

int n, q;

inline void __prep__() {
	C[0][0] = 1;
	for (int i = 1; i < K; i++) {
		C[i][i] = C[i][0] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
	}

	for (int i = 0; i <= n; i++) {
		pw[i][0] = 1;
		for (int j = 1; j < K; j++)
			pw[i][j] = pw[i][j - 1] * i;
	}
}

void __init__(Mint coef[][K], int k) {
	for (int i = 0; i < n; i++) {
		// (a0 + i) ^ k
		for (int j = 0; j <= k; j++) {
			// a0^j * C(j,k) * i^(k-j)
			coef[i + 1][j] = coef[i][j] + C[k][j] * pw[i][k - j];
		}
	}
}

Mint calc1(Mint a, int len) {
	Mint res = 0, p = 1;
	for (int i = 0; i <= K1; i++, p *= a) {
		res += p * coef1[len][i];
	}
	return res;
}

Mint calc2(Mint a, int len) {
	Mint res = 0, p = 1;
	for (int i = 0; i <= K2; i++, p *= a) {
		res += p * coef2[len][i];
	}
	return res;
}

void Hollwo_Pelw() {
	cin >> n >> q;

	__prep__();
	__init__(coef1, K1);
	__init__(coef2, K2);

	for (int i = 1; i <= n; i++) {
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
		pre1[i] = pre1[i - 1] + a[i].pow(K1);
		pre2[i] = pre2[i - 1] + a[i].pow(K2); 
	}

	// cout << pw[1][K1] + pw[2][K1] + pw[3][K1] << '\n';

	for (int i = 1, l, r, d; i <= q; i++) {
		cin >> l >> r >> d;
		Mint sum = pre[r] - pre[l - 1];
		// a0 + (a0 + d) + (a0 + 2 * d) + ... + (a0 + (r - l) * d)
		// (r - l + 1) * a0 + (r - l + 1) * (r - l) / 2 * d = sum
		Mint a0 = (sum - Mint(1ll * (r - l + 1) * (r - l) / 2) * d) / Mint(r - l + 1);
		// hash
		// a0 ^ k + (a0 + d) ^ k + (a0 + 2 * d) ^ k + ... => prep coef 
		a0 /= Mint(d);
		// a0 ^ k + (a0 + 1) ^ k + ...
		// cout << a0 << '\n';

		bool ok = 1;
		ok &= (pre1[r] - pre1[l - 1]) == calc1(a0, r - l + 1) * Mint(d).pow(K1);
		ok &= (pre2[r] - pre2[l - 1]) == calc2(a0, r - l + 1) * Mint(d).pow(K2);
		
		cout << (ok ? "Yes\n" : "No\n");
	}

}