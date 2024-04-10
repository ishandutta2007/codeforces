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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

// 2 * 3 * 5 * 7 * 11 * 13 * 17 > 5e5
// => max ans = 7 + 1 = 8 ?

const int N = 1e6 + 5, S = 1005, inf = 1e9;

int nor[N], p[N], n, d[N], t[N], res = inf;
vector<int> adj[N], vis;

inline void add_edge(int u, int v) {
	adj[u].push_back(v), adj[v].push_back(u);
}

inline void solve(int s) {
	if (adj[s].empty()) return ;
	
#define do_push(x) q.push(x), vis.push_back(x);
	queue<int> q;

	t[s] = -1, d[s] = 1, do_push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (d[u] > res) break ;
		for (auto v : adj[u]) {
			if (d[v] > d[u] + 1) {
				t[v] = u, d[v] = d[u] + 1, do_push(v);
			} else if (v != t[u]) {
				res = min(res, d[u] + d[v] - 1);
			}
		}
	}
	for (auto v : vis)
		d[v] = inf;
	vis.clear();
}

void Hollwo_Pelw() {
	iota(p, p + N, 0), iota(nor, nor + N, 0);
	for (int i = 2; i < N; i++) if (p[i])
		for (int j = 2 * i; j < N; j += i) p[j] = i;
	for (int i = 2; i < S; i++)
		for (int j = 1; j * i * i < N; j++)
			nor[j * i * i] = nor[j];
	cin >> n;
	
	set<int> okok; okok.insert(1);
	for (int x; n --; ) {
		cin >> x, x = nor[x];
		if (okok.count(x))
			res = min(res, x == 1 ? 1 : 2);
		okok.insert(x);
		add_edge(x / p[x], p[x]);
	}
	if (res <= 2)
		return cout << res, (void) 0;

	fill(d, d + N, inf);
	for (int i = 1; i < S; i++) 
		if (p[i] == i) solve(i);
	cout << (res == inf ? -1 : res);
}