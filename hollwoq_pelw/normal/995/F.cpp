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
	friend mod_int operator -- (mod_int& a, int) { mod_int r = a; --a; return r; }
	mod_int& operator ++ () { ++ v; if (v == mod()) v = 0; return *this; }
	friend mod_int operator ++ (mod_int& a, int) { mod_int r = a; ++a; return r; }
	
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

struct modular { static constexpr int mod = static_cast<int>(1e9 + 7); };

// struct modular { static int mod; };
// int modular::mod;

using Mint = mod_int<modular>;

// -> calc f(n) with f(0) .. f(k) (f is polynomial degree k)
template <class T>
inline T interpolate(int n, int k, const vector<T> &f) {
	vector<T> pre(k + 1), suf(k + 1), inv(k + 1, 1);
	
	for (int i = 0; i <= k; i++)
		pre[i] = (i == 0 ? 1 : pre[i - 1]) * (n - i);
	for (int i = k; i >= 0; i--)
		suf[i] = (i == k ? 1 : suf[i + 1]) * (n - i);

	for (int i = 1; i <= k; i++)
		inv[i] = inv[i - 1] / i;

	T res = 0;

	for (int i = 0; i <= k; i++) {
		T val = f[i] * inv[i] * inv[k - i] * 
			(i == 0 ? 1 : pre[i - 1]) * (i == k ? 1 : suf[i + 1]);
		((i ^ k) & 1 ? res -= val : res += val);
	}

	return res;
}

const int N = 3005;

Mint f[N][N];
int n, d, par[N];

void Hollwo_Pelw(){
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		fill(f[i] + 1, f[i] + n + 1, 1);
	for (int i = 2; i <= n; i++)
		cin >> par[i];

	for (int u = n; u; u--) {
		for (int i = 1; i <= n; i++)
			f[u][i] += f[u][i - 1];

		if (int p = par[u]) {
			for (int i = 0; i <= n; i++)
				f[p][i] *= f[u][i];
		}
	}

	cout << interpolate(d, n, vector<Mint>(f[1], f[1] + n + 1)) << '\n';
}