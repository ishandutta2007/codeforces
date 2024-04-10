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

struct node_t {
	struct line_t {
		long long a, b;
		line_t (long long _a = 0, long long _b = 0) : a(_a), b(_b) {}

		long long eval(long long x) {
			return a * x + b;
		}
	} ln;

	node_t *l = 0, *r = 0;
	int tl, tr;

	node_t() {}
	node_t(int _tl, int _tr)
		: tl(_tl), tr(_tr) { ln = line_t(0, 1e12); }

	inline void clear() {
		if (l) l -> clear();
		if (r) r -> clear();
		free(this);
	}

	void add(long long a, long long b) {
		add(line_t(a, b));
	}

	void add(line_t new_ln) {
		int tm = (tl + tr) >> 1;

		bool md = new_ln.eval(tm) < ln.eval(tm),
			 lf = new_ln.eval(tl) < ln.eval(tl);

		if (md) swap(new_ln, ln);

		if (tl == tr) return ;

		if (md != lf) {
			if (!l)
				l = new node_t(tl, tm);
			l -> add(new_ln);
		} else {
			if (!r)
				r = new node_t(tm + 1, tr);
			r -> add(new_ln);
		}
	}

	long long query(long long x) {
		int tm = (tl + tr) >> 1;
		long long res = ln.eval(x);

		if (x <= tm) {
			if (l) res = min(l -> query(x), res);
		} else {
			if (r) res = min(r -> query(x), res);
		}

		return res;
	}

} * root;

const int N = 1e5 + 5;
int n, a[N], b[N];
long long dp[N];

vector<int> adj[N];
int siz[N], tin[N], tout[N], timer, pos[N];

void pre_dfs(int u, int p) {
	siz[u] = 1;
	
	tin[u] = ++ timer;
	pos[timer] = u;

	for (int v : adj[u])
		if (v != p) pre_dfs(v, u), siz[u] += siz[v];

	tout[u] = timer;
}

void dfs(int u, int p, bool keep) {

	int mx = -1, big = -1, leaf = 1;
	for (auto v : adj[u]) if (v != p) {
		if (siz[v] > mx) big = v, mx = siz[v];
		leaf = 0;
	}
 
	for (auto v : adj[u]) if (v != p) {
		if (v != big) dfs(v, u, 0);
	}
 
	if (big != -1)
		dfs(big, u, 1);

	for (auto v : adj[u]) if (v != p) {
		if (v != big) {
			for (int t = tin[v], w; t <= tout[v]; t++) {
				w = pos[t]; root -> add(b[w], dp[w]);
			}
		}
	}
 
	dp[u] = leaf ? 0 : root -> query(a[u]);
	
	root -> add(b[u], dp[u]);

	if (!keep) root = new node_t(-1e5, 1e5);
}

void Hollwo_Pelw() {
	root = new node_t(-1e5, 1e5);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);

	pre_dfs(1, 1), dfs(1, 1, 0);
	
	for (int i = 1; i <= n; i++) 
		cout << dp[i] << ' ';
}