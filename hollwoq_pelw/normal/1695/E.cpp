#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 3e5 + 5;

int n, eu[N], ev[N], vis[N * 2], vise[N], f[2][N];
char a[2][N], b[2][N];
vector<int> adj[N * 2], ord;

void dfs_solve(int u) {
	ord.push_back(u);
	if (vis[u]) return;
	vis[u] = 1;
	for (int i : adj[u]) if (!vise[i]) {
		int v = u ^ eu[i] ^ ev[i];
		vise[i] = 1;
		dfs_solve(v);
		ord.push_back(u);
	}
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> eu[i] >> ev[i];
		adj[eu[i]].push_back(i);
		adj[ev[i]].push_back(i);
	}

	for (int i = 0; i < n; i++)
		a[0][i] = b[0][i] = 'U', a[1][i] = b[1][i] = 'D';

	for (int i = 1, p = 0; i <= n * 2; i++) if (!vis[i]) {
		ord.clear(), dfs_solve(i);
		int nDominoes = ord.size() / 2;

		if (nDominoes == 1)
			return cout << "-1\n", (void) 0;

		for (int j = 0; j < nDominoes; j++) {
			f[0][p + j] = ord[j];
			f[1][p + j] = ord[j + nDominoes];
		}

		reverse(f[1] + p, f[1] + p + nDominoes);

		for (int j = 0; j + 1 < nDominoes; j += 2) {
			a[0][p + j] = 'L', a[0][p + j + 1] = 'R';
			a[1][p + j] = 'L', a[1][p + j + 1] = 'R';
		}
		for (int j = 1; j + 1 < nDominoes; j += 2) {
			b[0][p + j] = 'L', b[0][p + j + 1] = 'R';
			b[1][p + j] = 'L', b[1][p + j + 1] = 'R';
		}

		p += nDominoes;
	}
	cout << 2 << ' ' << n << '\n';
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cout << f[i][j] << " \n"[j == n - 1];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j];
		cout << "\n";
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++)
			cout << b[i][j];
		cout << "\n";
	}
}