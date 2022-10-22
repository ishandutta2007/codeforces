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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e5 + 55, mod = 1e9 + 7, M = N * 80;

int dist[N], pre[N], pw[N], nnode, n, m, s, t, minnode, maxnode;
vector<pair<int, int>> adj[N];

#define tm (tl + tr >> 1)
#define left st[id].lc, tl, tm
#define right st[id].rc, tm + 1, tr

struct node {
	int hsh = 0, len = 0, f = -1, lc = 0, rc = 0; // PST only
	node () {}
	node (int _hsh, int _len, int _f, int _lc, int _rc)
		: hsh(_hsh), len(_len), f(_f), lc(_lc), rc(_rc) {}
} st[M];

inline int merge(int lc, int rc) {
	st[++ nnode] = node(
		(1ll * st[rc].hsh * pw[st[lc].len] + st[lc].hsh) % mod,
		st[lc].len + st[rc].len,
		st[rc].f == -1 ? st[lc].f : st[rc].f, lc, rc
	);
	return nnode;
}

inline int newnode(int p, int x) {
	st[++ nnode] = node(x, 1, (x ? -1 : p), 0, 0);
	return nnode;
}

int build(int v, int tl = 0, int tr = N - 1) {
	if (tl == tr)
		return newnode(tl, v);
	int cl = build(v, tl, tm);
	int cr = build(v, tm + 1, tr);
	return merge(cl, cr);
}

int range_copy(int l, int r, int old, int id, int tl = 0, int tr = N - 1) {
	if (l > tr || tl > r) return id;
	if (l <= tl && tr <= r) return old;
	int cl = range_copy(l, r, st[old].lc, left);
	int cr = range_copy(l, r, st[old].rc, right);
	return merge(cl, cr);
}

int first0(int p, int id, int tl = 0, int tr = N - 1) {
	if (tr < p) return -1;
	if (tl == tr) return st[id].f;
	int cl = first0(p, left);
	return (~cl ? cl : first0(p, right));
}

int comp(int oth, int id, int tl = 0, int tr = N - 1) {
	if (oth == id) return 0;
	if (tl == tr)
		return st[id].hsh - st[oth].hsh;
	int cr = comp(st[oth].rc, right);
	return (cr ? cr : comp(st[oth].lc, left));
}

void print(int id, int tl = 0, int tr = N - 1) {
	if (tl == tr)
		return cout << st[id].hsh, (void) 0;
	print(left), print(right);
}

struct dst {
	int u, d;
	dst () {}
	dst (int _u, int _d) 
		: u(_u), d(_d) {}
	bool operator < (const dst &oth) const {
		int v = comp(oth.d, d);
		return v ? v > 0 : u > oth.u;
	}
};

priority_queue<dst> pq;

void dijkstra() {
	for (int i = 1; i <= n; i++)
		dist[i] = maxnode;
	pq.emplace(s, dist[s] = minnode);
	while (!pq.empty()) {
		int u = pq.top().u, d = pq.top().d; pq.pop();
		if (d != dist[u]) continue ;
		
		for (auto vw : adj[u]) {
			int v = vw.first, w = vw.second, x = first0(w, d);
			int nd = range_copy(x, x, maxnode, d);
			nd = range_copy(w, x - 1, minnode, nd);

			if (comp(dist[v], nd) < 0)
				pre[v] = u, pq.emplace(v, dist[v] = nd);
		}
	}

	if (dist[t] == maxnode)
		return cout << -1, (void) 0;

	cout << st[dist[t]].hsh << '\n';

	vector<int> res(1, t);
	while (t != s)
		res.push_back(t = pre[t]);
	reverse(res.begin(), res.end());

	cout << res.size() << '\n';
	for (auto v : res)
		cout << v << ' ';
}

void Hollwo_Pelw() {
	pw[0] = 1;
	for (int i = 1; i < N; i++)
		pw[i] = 2ll * pw[i - 1] % mod;
	cin >> n >> m;
	for (int i = 0, u, v, w; i < m; i++)
		cin >> u >> v >> w, adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	cin >> s >> t;
	minnode = build(0), maxnode = build(1), dijkstra(); //
}