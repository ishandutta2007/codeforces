/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2,avx,fma")

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

const int N = 606, inf = 1e9 + 123;

struct edge {
	int u, v, w;
} edges[N * N >> 1];

int n, m, q, res, d[N][N], mx[N][N];

#define for1(i, n) for (int i = 1; i <= n; i++)

void Hollwo_Pelw() {
	cin >> n >> m;
	
	for1(i, n) for1(j, n)
		d[i][j] = inf, mx[i][j] = -inf;

	for (int i = 1, u, v, w; i <= m; i++)
		cin >> u >> v >> w, edges[i] = {u, v, w}, d[u][v] = d[v][u] = w;

	cin >> q;
	for (int i = 1, u, v, w; i <= q; i++)
		cin >> u >> v >> w, mx[u][v] = mx[v][u] = w;

	for1(k, n) for1(i, n) for1(j, n)
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

	for1(k, n) for1(i, n) for1(j, n) {
		mx[k][j] = max(mx[k][j], mx[i][j] - d[i][k]);
		mx[i][k] = max(mx[i][k], mx[i][j] - d[k][j]);
	}

	for1(i, m) if (mx[edges[i].u][edges[i].v] >= edges[i].w) res ++;

	cout << res;
}