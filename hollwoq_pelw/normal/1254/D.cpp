/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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
	FAST_IO(".inp", ".out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 15e4 + 5, mod = 998244353;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void sadd(int &a, int b) { a = a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline void ssub(int &a, int b) { a = a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return 1ll * a * b % mod; }

inline int binpow(int a, int b) {
	int r = 1;
	while (b) {
		if (b&1) r = mul(r, a);
		b >>= 1; a = mul(a, a);
	}
	return r;
}

int n, q, sz[N], upval[N], bit[N], inv;

inline void upd(int x, int v) {
	for (; x <= n; x += x & -x)
		sadd(bit[x], v);
}

inline void upd(int l, int r, int v) {
	upd(l, v), upd(r + 1, sub(0, v));
}

inline int query(int x) {
	int r = 0;
	for (; x; x -= x & -x)
		sadd(r, bit[x]);
	return r;
}

int tin[N], tout[N], nxt[N], par[N], timer;
vector<int> adj[N];

void __pre_dfs__(int u, int p) {
	sz[u] = 1, nxt[u] = u, par[u] = p;
	for (auto &v : adj[u]) {
		if (v == p) swap(v, adj[u].back());
		if (v == p) continue ;

		__pre_dfs__(v, u);
		sz[u] += sz[v];

		if (sz[v] > sz[adj[u][0]])
			swap(v, adj[u][0]);
	}
	if (!adj[u].empty() && adj[u].back() == p) adj[u].pop_back();
}

void __dfs_hld__(int u) {
	tin[u] = ++ timer;

	for (auto &v : adj[u]) {
		if (v == adj[u][0])
			nxt[v] = nxt[u];
		__dfs_hld__(v);
	}

	tout[u] = timer;
}

inline void __build_hld__() {
	__pre_dfs__(1, 0), __dfs_hld__(1);
}

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1, u, v; i < n; i++)
		cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);

	inv = binpow(n, mod - 2);
	__build_hld__();

	for (int _ = 0, t, v, d; _ < q; _++) {
		cin >> t >> v;
		if (t == 1) {
			cin >> d;
			sadd(upval[v], d);
			
			int inc = mul(d, sz[v]);
			
			upd(tin[1], tout[1], add(0, inc));
			upd(tin[v], tout[v], sub(0, inc));
			
			if (!adj[v].empty()) {
				v = adj[v][0];
				upd(tin[v], tout[v], mul(d, n - sz[v]));
			}

		} else {
			d = add(query(tin[v]), mul(upval[v], n));
			while (v) {
				v = nxt[v];
				if (par[v])
					sadd(d, mul(upval[par[v]], n - sz[v]));
				v = par[v];
			}
			cout << mul(d, inv) << '\n';
		}
	}
}