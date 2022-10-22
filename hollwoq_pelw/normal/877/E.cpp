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

const int N = 2e5 + 5;

int n, q, tin[N], tout[N], timer;
int t[N], st[N << 2], lz[N << 2];
vector<int> adj[N];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

inline void apply(int id, int tl, int tr) {
	st[id] = tr - tl + 1 - st[id], lz[id] ^= 1;
}

inline void push(int id, int tl, int tr) {
	if (lz[id]) apply(left), apply(right), lz[id] = 0;
}

void update(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) return apply(id, tl, tr);
	push(id, tl, tr), update(l, r, left), update(l, r, right);
	st[id] = st[id << 1] + st[id << 1 | 1];
}

int query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return 0;
	if(l <= tl && tr <= r) return st[id];
	return push(id, tl, tr), query(l, r, left) + query(l, r, right);
}

void pre_dfs(int u) {
	tin[u] = ++ timer;
	if (t[u]) 
		update(tin[u], tin[u]);
	for (auto v : adj[u])
		pre_dfs(v);
	tout[u] = timer;
}

char s[10];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 2, p; i <= n; i++)
		cin >> p, adj[p].push_back(i);
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	pre_dfs(1);
	cin >> q;
	for (int v; q --; ) {
		cin >> s >> v;
		if (s[0] == 'g')
			cout << query(tin[v], tout[v]) << '\n';
		else
			update(tin[v], tout[v]);
	}
}