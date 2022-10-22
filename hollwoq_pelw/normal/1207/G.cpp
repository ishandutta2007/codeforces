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

const int N = 4e5 + 5;

vector<int> adj_link[N];
vector<pair<int, int>> adj[N], qry[N];

int nnode, link[N], nxt[N][26], go[N][26];
int n, m, res[N];

inline int add_string(const string& s) {
	int p = 0;
	for (auto ch : s) {
		int c = ch - 'a';
		if (!nxt[p][c])
			nxt[p][c] = ++ nnode;
		p = nxt[p][c];
	}
	return p;
}

inline void build() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int c = 0; c < 26; c++) {
			go[u][c] = go[link[u]][c];
			if (int v = nxt[u][c]) {
				link[v] = go[u][c];
				go[u][c] = v;
				q.push(v);
			}
		}
	}

	for (int i = 1; i <= nnode; i++) {
		adj_link[link[i]].push_back(i);
	}
}

int tin[N], tout[N], timer, bit[N];

void pre_dfs(int u) {
	tin[u] = ++ timer;
	for (auto v : adj_link[u])
		pre_dfs(v);
	tout[u] = timer;
}

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

inline int query(int l, int r) {
	return query(r) - query(l - 1);
}

void solve(int u, int p) {
	add(tin[p], +1);
	for (auto [v, id] : qry[u])
		res[id] = query(tin[v], tout[v]);

	for (auto [v, c] : adj[u])
		solve(v, go[p][c]);
	add(tin[p], -1);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, p, tp; i <= n; i++) {
		cin >> tp; if (tp == 1) p = 0; else cin >> p;
		char c; cin >> c, adj[p].emplace_back(i, c - 'a');
	}

	cin >> m;
	for (int i = 1, p; i <= m; i++) {
		string s; cin >> p >> s;
		qry[p].emplace_back(add_string(s), i);
	}
	build();
	pre_dfs(0);
	solve(0, 0);
	for (int i = 1; i <= m; i++)
		cout << res[i] << '\n';
}