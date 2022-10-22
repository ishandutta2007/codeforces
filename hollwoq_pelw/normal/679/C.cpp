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
	FAST_IO("679C.inp", "679C.out");
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

const int N = 505;

int n, k, pre[N][N], par[N * N], siz[N * N], cnt[N * N], res, cur;
char s[N][N];

inline int find(int u) {
	return par[u] = (par[u] == u ? u : find(par[u]));
}

inline void merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return ;
	if (siz[u] > siz[v]) swap(u, v);
	par[u] = v, siz[v] += siz[u];
}

inline int comp(int x, int y) {
	return (x - 1) * n + y;
}

inline int get(int x, int y) {
	return pre[x][y] - pre[x][y - k] - pre[x - k][y] + pre[x - k][y - k];
}

inline void add(int x, int y) {
	if (x > n || x < 1 || y > n || y < 1 || s[x][y] == 'X') return ;
	int t = find(comp(x, y)); if (!cnt[t]) cur += siz[t]; cnt[t] ++;

}

inline void del(int x, int y) {
	if (x > n || x < 1 || y > n || y < 1 || s[x][y] == 'X') return ;
	int t = find(comp(x, y)); cnt[t] --; if (!cnt[t]) cur -= siz[t];
}


void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> (s[i] + 1);

	iota(par + 1, par + n * n + 1, 1);
	fill(siz + 1, siz + n * n + 1, 1);

	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (s[i][j] == 'X');

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) if (s[i][j] == '.') {
			if (i < n && s[i + 1][j] == '.') merge(comp(i, j), comp(i + 1, j));
			if (j < n && s[i][j + 1] == '.') merge(comp(i, j), comp(i, j + 1));
		} else {
			siz[comp(i, j)] = 0;
		}

	for (int u = 1, d = k; d <= n; u++, d++) {
		memset(cnt, 0, sizeof cnt);
		cur = 0;
		for (int i = u - 1; i <= d + 1; i++)
			for (int j = 1; j <= k; j++) add(i, j);

		for (int i = u; i <= d; i++)
			for (int j = 0; j <= k + 1; j++) add(i, j);

		for (int l = 1, r = k; r <= n; l++, r++) {
			// choose 
			res = max(res, cur + get(d, r));

			for (int i = u - 1; i <= d + 1; i++)
				add(i, r + 1), del(i, l);
			for (int i = u; i <= d; i++) 
				add(i, r + 2), del(i, l - 1);
		}
	}

	cout << res;
}