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
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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

template<typename T, int N>
struct array_2d {
	array<array<T, N>, N> a;
	array<T, N>& operator [] (int x) { return a[x]; }
	const array<T, N>& operator [] (int x) const { return a[x]; }

#define forN(i) for (int i = 0; i < N; i++)
#define defop(type, op) \
	inline type& operator op##= (const type &a) { return *this = (*this op a); } \
	friend inline type operator op (const type &a, const type &b)

	array_2d(int v = 0) { forN(i) forN(j) a[i][j] = i == j ? v : 0; }
	
	defop(array_2d, *) { array_2d res(0); forN(i) forN(j) forN(k) res[i][j] += a[i][k] * b[k][j]; return res; }
	defop(array_2d, +) { array_2d res(0); forN(i) forN(j) res[i][j] = a[i][j] + b[i][j]; return res; }
	defop(array_2d, -) { array_2d res(0); forN(i) forN(j) res[i][j] = a[i][j] - b[i][j]; return res; }

#undef forN
#undef defop
	array_2d pow(long long b) const {
		array_2d a = *this, r = 1;
		for (; b; b >>= 1, a *= a)
			if (b & 1) r *= a;
		return r;
	}
};

using matrix = array_2d<Mint, 4>;

const int N = 1e5 + 5;

namespace BIT {

int bit[N];

inline void add(int p, int x) {
	for (; p < N; p += p & -p)
		bit[p] += x;
}

inline int query(int p) {
	int r = 0;
	for (; p > 0; p -= p & -p)
		r += bit[p];
	return r;
}

} // namespace BIT

int n, a[N], pre_small[N], suf_small[N], pos[N];
matrix base[N];

vector<int> ids[N];
Mint result;

struct segment_tree {
	vector<matrix> st;
	int sz;

	segment_tree() {}
	segment_tree(const vector<int> &ids) {
		for (sz = 1; sz < (int) ids.size(); sz <<= 1);
		st.assign(sz * 2, 1);

		for (int p = 0; p < (int) ids.size(); p++)
			st[p + sz] = base[ids[p]];
		for (int p = sz - 1; p; p --)
			st[p] = st[p << 1] * st[p << 1 | 1];
		
		result += st[1][0][3];
	}

	inline void update(int p, int x) {
		result -= st[1][0][3];

		for (st[p += sz] = base[x]; p >>= 1; )
			st[p] = st[p << 1] * st[p << 1 | 1];

		result += st[1][0][3];
	}
} st[N];

inline void toggle(int t, int x) {
	st[a[x]].update(pos[x], t == 2 ? x : 0);
}

void Hollwo_Pelw(){	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	{
		vector<int> v(a, a + n + 1);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		for (int i = 1; i <= n; i++)
			a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
	}

	memset(BIT::bit, 0, sizeof BIT::bit);
	for (int i = 1; i <= n; i++)
		pre_small[i] = BIT::query(a[i]), BIT::add(a[i], 1);

	memset(BIT::bit, 0, sizeof BIT::bit);
	for (int i = n; i >= 1; i--)
		suf_small[i] = BIT::query(a[i]), BIT::add(a[i], 1);

	base[0] = matrix(1);
	
	for (int i = 1; i <= n; i++) {
		base[i] = matrix(1);
		base[i][0][1] = pre_small[i];
		base[i][1][2] = 1;
		base[i][2][3] = suf_small[i];

		pos[i] = ids[a[i]].size();
		ids[a[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		st[i] = segment_tree(ids[i]);

	int q; cin >> q;
	for (int t, x; q --; ) {
		cin >> t >> x;
		toggle(t, x);
		cout << result << '\n';
	}
}