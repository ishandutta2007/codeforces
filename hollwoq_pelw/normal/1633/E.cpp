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

const int N = 55, M = 305, Q = 1e8 + 5;

struct edge_t {
	int u, v, w;
} edges[M];

bitset<Q> query, change;

int n, m, par[N], siz[N];

inline int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

inline bool merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return 0;
	return siz[par[u] = v] += siz[u], 1;
}

long long A, B;

inline void recalc(int x) {
	iota(par + 1, par + n + 1, 1);
	fill(siz + 1, siz + n + 1, 1);

	sort(edges, edges + m, [&](const edge_t &a, const edge_t &b){
		return abs(a.w - x) == abs(b.w - x) ?
			a.w > b.w : abs(a.w - x) < abs(b.w - x);
	});
	A = B = 0;

	for (int i = 0; i < m; i++) {
		int u = edges[i].u, v = edges[i].v, w = edges[i].w;
		if (merge(u, v)) {
			if (w <= x) A ++, B -= w;
			else		A --, B += w;
		}
	}
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 0, u, v, w; i < m; i++)
		cin >> u >> v >> w, edges[i] = {u, v, w};

	for (int i = 0; i < m; i++) for (int j = i; j < m; j++) {
		change.set(edges[i].w + edges[j].w + 1 >> 1);
	}

	change.set(0);

	int p, k, a, b, c;
	cin >> p >> k >> a >> b >> c;
	for (int i = 0, x = 0; i < k; i++) {
		if (i < p)
			cin >> x;
		else
			x = (1ll * a * x + b) % c;
		query.flip(x);
	}

	long long res = 0;
	for (int x = 0; x < Q; x++) {
		if (change[x]) recalc(x);
		if (query[x])
			res ^= A * x + B;
	}

	cout << res;
}