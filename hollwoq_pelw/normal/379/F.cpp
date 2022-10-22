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

const int N = 1e6 + 5;

int n = 4, q, par[N][20], r1 = 1, r2 = 2;

int h[N] = {0, 1, 1, 1};

inline int lca(int u, int v) {
	if (h[u] > h[v]) swap(u, v);
	for (int i = 19; ~i; i--)
		if (h[v] - h[u] >> i & 1)
			v = par[v][i];
	if (u == v) return u;
	for (int i = 19; ~i; i--)
		if (par[u][i] ^ par[v][i])
			u = par[u][i], v = par[v][i];
	return par[u][0];
}

inline int dist(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

inline void add(int p, int u) {
	h[u] = h[par[u][0] = p] + 1;
	for (int i = 1; i <= 19; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	if (dist(r1, r2) < dist(u, r2)) r1 = u;
	if (dist(r1, r2) < dist(r1, u)) r2 = u;
}

void Hollwo_Pelw() {
	cin >> q;
	for (int i = 1, v; i <= q; i++) {
		cin >> v, --v;
		add(v, n ++), add(v, n ++);
		cout << dist(r1, r2) << '\n';
	}
}