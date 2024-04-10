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
	FAST_IO("204D.inp", "204D.out");
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

const int N = 1e6 + 5, mod = 1e9 + 7;

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

int n, k, cx[N], cw[N], cb[N];
char s[N];

inline int get(char c, int l, int r) {
	if (c == 'B')
		return cb[r] - cb[l];
	if (c == 'W')
		return cw[r] - cw[l];
	return cx[r] - cx[l];
}

Mint pre[2][N], suf[2][N], pw2[N];

void Hollwo_Pelw() {
	cin >> n >> k >> (s + 1);

	if (k * 2 > n)
		return cout << 0, (void) 0;

	pw2[0] = 1;
	for (int i = 1; i <= n; i++)
		pw2[i] = pw2[i - 1] * 2;

	for (int i = 1; i <= n; i++) {
		cx[i] = cx[i - 1] + (s[i] == 'X');
		cw[i] = cw[i - 1] + (s[i] == 'W');
		cb[i] = cb[i - 1] + (s[i] == 'B');
	}

	{ // calc prefix (contains 'B' or not)
		Mint cur = 0;
		for (int i = 0; i <= n; i++) {
			if (i - 0 >= k) {
				if (s[i] == 'X') cur *= 2;
				if (get('W', i - k, i) == 0 && (i - k <= 0 || s[i - k] != 'B')) {
					pre[1][i] = i - k <= 0 ? 1 : pre[0][i - k - 1], cur += pre[1][i];
				}
			}
			pre[0][i] = pw2[get('X', 0, i)] - cur;
		}
	}

	Mint res = 0;
	
	{ // calc suffix (contains 'W' or not)
		Mint cur = 0;
		for (int i = n; i >= 0; i--) {
			if (n - i >= k) {
				if (s[i + 1] == 'X') cur *= 2;
				if (get('B', i, i + k) == 0 && (i + k >= n || s[i + k + 1] != 'W')) {
					suf[1][i] = i + k >= n ? 1 : suf[0][i + k + 1], cur += suf[1][i];
				}
			}
			suf[0][i] = pw2[get('X', i, n)] - cur;
			
			if (i >= k && get('W', i - k, i) == 0)
				res += pre[1][i] * cur;
		}
	}
	
	cout << res;
}