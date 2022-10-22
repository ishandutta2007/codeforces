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
	if (fopen("G.inp", "r"))
		assert(freopen("G.inp", "r", stdin)), assert(freopen("G.out", "w", stdout));
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

const int N = 205, K = 505;

inline void read(vector<int> &a) {
	int len; cin >> len;
	a.resize(len);
	for (int &x : a) cin >> x;
}

// trie + aho
int n, m, max_K;
int nnode, tr[N][20], endp[N], fail[N];

inline void sub1(vector<int> &a) {
	reverse(a.begin(), a.end());
	a[0] --;
	for (int i = 0; i < (int) a.size(); i++)
		if (a[i] < 0) a[i] += m, a[i + 1] --;
	if (!a.back()) a.pop_back();
	reverse(a.begin(), a.end());
}

void add_string(const vector<int> &a, int v) {
	int p = 0;
	for (auto x : a) {
		if (!tr[p][x])
			tr[p][x] = ++ nnode;
		p = tr[p][x];
	}
	endp[p] += v;
}

void build() {
	queue<int> q;
	for (int i = 0; i < m; i++)
		if (tr[0][i]) q.push(tr[0][i]);

	while (!q.empty()) {
		int u = q.front(); q.pop();

		for (int i = 0; i < m; i++) {
			int v = tr[u][i];
			if (v) {
				q.push(v);
				fail[v] = tr[fail[u]][i];
				endp[v] += endp[fail[v]];
			} else {
				tr[u][i] = tr[fail[u]][i];
			}
		}
	}
}

vector<int> L, R;

Mint f[2][K][N], g[2][K][N];
// len, nnode, cnt

Mint solve(vector<int> &s) {
	memset(f, 0, sizeof f);
	
	int ii = 0;

	for (int w : s) {
		memset(g, 0, sizeof g);

		for (int s = 0; s < 2; s++) for (int i = 0; i <= max_K; i++)
			for (int j = 0; j <= nnode; j++) if (Mint v = f[s][i][j]) {
				for (int x = 0; x <= (s ? w : m - 1); x++) {
					int to = tr[j][x], val = i + endp[to];
					if (val <= max_K)
						g[s && x == w][val][to] += v;
				}
			}

		for (int x = 1; x <= (ii == 0 ? w : m - 1); x++) {
			int to = tr[0][x], val = endp[to];
			if (val <= max_K)
				g[ii == 0 && x == w][val][to] ++;
		}

		memcpy(f, g, sizeof f), ++ ii;
	}

	Mint res = 0;
	for (int s = 0; s < 2; s++)
		for (int i = 0; i <= max_K; i++)
			for (int j = 0; j <= nnode; j++)
				res += f[s][i][j];
	return res;
}

void Hollwo_Pelw(){
	cin >> n >> m >> max_K;
	read(L), sub1(L), read(R);
	
	for (int i = 0, v; i < n; i++) {
		vector<int> s;
		read(s);
		cin >> v;
		add_string(s, v);
	}

	build();

	cout << solve(R) - solve(L);
}