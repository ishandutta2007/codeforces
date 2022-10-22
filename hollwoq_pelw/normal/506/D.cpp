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

const int N = 1e5 + 5, MAGIC = 450;

vector<pair<int, int>> eds[N];

vector<vector<int>> comp;
vector<int> temp[N], appear[N];
int n, m, q, par[N], used[N];
int big[N], cnt_big, ans[MAGIC][N];

inline int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

inline void merge(int u, int v) {
	par[find(u)] = find(v);
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1, u, v, c; i <= m; i++)
		cin >> u >> v >> c, eds[c].emplace_back(u, v);
	iota(par + 1, par + n + 1, 1);

	for (int i = 1; i <= m; i++) {

		for (auto [u, v] : eds[i])
			merge(u, v);
		for (auto [u, v] : eds[i]) {

			if (!used[u]) temp[find(u)].push_back(u), used[u] = 1;
			if (!used[v]) temp[find(v)].push_back(v), used[v] = 1;

		}

		for (auto [u, v] : eds[i]) {

			if (!temp[u].empty()) comp.push_back(temp[u]), temp[u].clear();
			if (!temp[v].empty()) comp.push_back(temp[v]), temp[v].clear();

			used[u] = 0, par[u] = u;
			used[v] = 0, par[v] = v;
		}
	}

	for (int i = 0; i < comp.size(); i++) {
		for (auto j : comp[i])
			appear[j].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		if (appear[i].size() >= MAGIC) {
			big[i] = ++ cnt_big;

			for (int j : appear[i])
				for (int k : comp[j])
					ans[cnt_big][k] ++;

		}
	}

	cin >> q;
	for (int u, v; q --; ) {
		cin >> u >> v;
		if (!big[u]) swap(u, v);

		if (big[u]) {
			cout << ans[big[u]][v] << '\n';
		} else {
			int res = 0;
			for (int i = 0, j = 0; i < appear[u].size() && j < appear[v].size(); ) {
				if (appear[u][i] == appear[v][j])
					res ++, i ++, j ++;
				else if (appear[u][i] < appear[v][j])
					i ++;
				else if (appear[u][i] > appear[v][j])
					j ++;
			}
			cout << res << '\n';
		}
	}
}