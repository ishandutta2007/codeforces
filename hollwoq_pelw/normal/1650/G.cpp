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
	if (fopen("hollwo_pelw.inp", "r")){
		freopen("hollwo_pelw.inp", "r", stdin);
		freopen("hollwo_pelw.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
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

const int N = 2e5 + 5;

int n, m, s, t, d[N];
vector<int> adj[N];
Mint cnt[N][2];

void Hollwo_Pelw() {
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++) {
		adj[i].clear(), d[i] = -1;
		cnt[i][0] = cnt[i][1] = 0;
	}

	for (int u, v; m --; ) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cnt[s][0] = 1;
	
	queue<int> q;
	q.push(s), d[s] = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();

		for (int v : adj[u])
			if (d[v] == -1) {
				q.push(v), d[v] = d[u] + 1;
			}
	}

	vector<int> ord(2 * n);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [](const int &x, const int &y){
		return d[x / 2 + 1] + x % 2 < d[y / 2 + 1] + y % 2;
	});

	for (auto TMP : ord) {
		int u = TMP / 2 + 1, s = TMP % 2;

		for (int v : adj[u]) {
			if (d[v] + 0 == d[u] + s + 1)
				cnt[v][0] += cnt[u][s];
			if (d[v] + 1 == d[u] + s + 1)
				cnt[v][1] += cnt[u][s]; 
		}
	}

	cout << cnt[t][0] + cnt[t][1] << '\n';
}