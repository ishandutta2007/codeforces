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

const int N = 3e5 + 5, mod = 1e9 + 7;

inline int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

inline int sub(int a, int b) {
	return a - b < 0 ? a - b + mod : a - b;
}

int n, q, tin[N], tout[N], d[N], timer;
vector<int> adj[N];

struct segtree {
#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr
	int st[N << 2], lz[N << 2];
	inline void apply(int id, int tl, int tr, int v) {
		st[id] = add(st[id], mul(tr - tl + 1, v)), lz[id] = add(lz[id], v);
	}
	inline void push(int id, int tl, int tr) {
		if (lz[id])  apply(left, lz[id]), apply(right, lz[id]), lz[id] = 0;
	}

	void update(int l, int r, int v, int id = 1, int tl = 1, int tr = n) {
		if (l > tr || tl > r) return ;
		if (l <= tl && tr <= r) return apply(id, tl, tr, v);
		push(id, tl, tr), update(l, r, v, left), update(l, r, v, right);
		st[id] = add(st[id << 1], st[id << 1 | 1]);
	}

	int query(int l, int r, int id = 1, int tl = 1, int tr = n) {
		if (l > tr || tl > r) return 0;
		if (l <= tl && tr <= r) return st[id];
		return push(id, tl, tr), add(query(l, r, left), query(l, r, right));
	}
#undef tm
#undef left
#undef right
} st1, st2;


void pre_dfs(int u) {
	tin[u] = ++ timer;
	for (auto v : adj[u])
		d[v] = d[u] + 1, pre_dfs(v);
	tout[u] = timer;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 2, p; i <= n; i++)
		cin >> p, adj[p].push_back(i);
	pre_dfs(1);
	cin >> q;
	for (int t, v; q --; ) {
		cin >> t >> v;
		if (t == 1) {
			int x, k;  cin >> x >> k;
			x = add(x, mul(d[v], k));
			st1.update(tin[v], tout[v], x);
			st2.update(tin[v], tout[v], k);
		} else {
			cout << sub(st1.query(tin[v], tin[v]), 
					mul(st2.query(tin[v], tin[v]), d[v])) << '\n';
		}
	}
}