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

const int N = 3e5 + 5, M = 20, mod = 998244353;

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

Mint fac[N], ifac[N];

struct __init__ {
	__init__() {
		fac[0] = ifac[0] = fac[1] = ifac[1] = 1;
		for (int i = 2; i < N; i++)
			fac[i] = fac[i - 1] * i, ifac[i] = fac[i].inv();
	}
} __init__;

inline Mint C(int n, int k) {
	return n < k || k < 0 ? 0 : fac[n] * ifac[n - k] * ifac[k];
}

int n, m, l[N], r[N], a[M], b[M], cnt[N];
bool used[N];

Mint pre[45][N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> l[i] >> r[i];
	for (int i = 0; i < m; i++)
		cin >> a[i] >> b[i];
	
	for (int i = 1; i <= n; i++)
		cnt[l[i]] ++, cnt[r[i] + 1] --;
	for (int i = 1; i <= n; i++)
		cnt[i] += cnt[i - 1];

	for (int i = 0; i <= 2 * m; i++) {
		for (int j = 1; j <= n; j++)
			pre[i][j] = pre[i][j - 1] + C(cnt[j] - i, j - i);
	}

	Mint res = 0;
	for (int mask = 0; mask < 1 << m; mask++) {
		int s = 1, L = 1, R = n, k = 0;
#define add(v) ++ k, used[v] = 1, L = max(L, l[v]), R = min(R, r[v])
		for (int i = 0; i < m; i++) if (mask >> i & 1) {
			s = -s;
			if (used[a[i]] == 0) add(a[i]);
			if (used[b[i]] == 0) add(b[i]);
		}
		for (int i = 0; i < m; i++) if (mask >> i & 1)
			used[a[i]] = used[b[i]] = 0;
		if (R < L) continue ;
		res += Mint(s) * (pre[k][R] - pre[k][L - 1]);
	}

	cout << res;
}