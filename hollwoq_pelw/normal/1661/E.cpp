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
	if (fopen("hollwo_pelw.inp", "r"))
		assert(freopen("hollwo_pelw.inp", "r", stdin)), assert(freopen("hollwo_pelw.out", "w", stdout));
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
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
}

const int N = 5e5 + 5;

int n, q, res[N], ql[N], qr[N], tot[N], par[N * 3];
bool connected[N][3][3];
char a[N][3];

inline int comp(int i, int j) { return i * 3 + j; } 
inline int find(int u) { return par[u] == u ? u : par[u] = find(par[u]); }
inline bool merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return 0;
	return par[u] = v, 1;
}
 
void solve(int l, int r, vector<int> &ids) {
	if (l > r || ids.empty()) return ;

	int m = (l + r) >> 1;

	if (l == r) {

		int val = 0;
		for (int j = 0; j < 3; j++) val += a[m][j] == '1';
		for (int j = 0; j < 2; j++) 
			val -= (a[m][j] == '1' && a[m][j + 1] == '1');

		for (int i : ids) res[i] = val;

		return ;
	}

	vector<int> lids, rids;

	for (int i = m, cur = 0; i >= l; i--) {
		par[comp(i, 0)] = comp(i, 0);
		par[comp(i, 1)] = comp(i, 1);
		par[comp(i, 2)] = comp(i, 2);

		for (int j = 0; j < 3; j++) if (a[i][j] == '1') {
			cur ++;
			if (i < m && a[i + 1][j] == '1')
				cur -= merge(comp(i, j), comp(i + 1, j));
		}

		for (int j = 0; j < 2; j++) {
			if (a[i][j] == '1' && a[i][j + 1] == '1')
				cur -= merge(comp(i, j), comp(i, j + 1));
		}

		tot[i] = cur;
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < j; k++)
				connected[i][j][k] = find(comp(m, j)) == find(comp(m, k));
	}

	for (int i = m + 1, cur = 0; i <= r; i++) {
		par[comp(i, 0)] = comp(i, 0);
		par[comp(i, 1)] = comp(i, 1);
		par[comp(i, 2)] = comp(i, 2);

		for (int j = 0; j < 3; j++) if (a[i][j] == '1') {
			cur ++;
			if (i > m + 1 && a[i - 1][j] == '1')
				cur -= merge(comp(i, j), comp(i - 1, j));
		}

		for (int j = 0; j < 2; j++) {
			if (a[i][j] == '1' && a[i][j + 1] == '1')
				cur -= merge(comp(i, j), comp(i, j + 1));
		}

		tot[i] = cur;
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < j; k++)
				connected[i][j][k] = find(comp(m + 1, j)) == find(comp(m + 1, k));
	}

	// cout << "SOLVE " << m << '\n';

	for (int i : ids) {
		if (ql[i] >  m) { rids.push_back(i); continue ; }
		if (qr[i] <= m) { lids.push_back(i); continue ; }

		// cout << ql[i] << ' ' << qr[i] << '\n';

		res[i] = tot[ql[i]] + tot[qr[i]];
		for (int j = 0; j < 3; j++) {
			par[comp(m, j)] = comp(m, j);
			par[comp(m + 1, j)] = comp(m + 1, j);
		}

		for (int j = 0; j < 3; j++)
			for (int k = 0; k < j; k++) {
				if (connected[ql[i]][j][k])
					merge(comp(m, j), comp(m, k));
				if (connected[qr[i]][j][k])
					merge(comp(m + 1, j), comp(m + 1, k));
			}

		for (int j = 0; j < 3; j++)
			if (a[m][j] == '1' && a[m + 1][j] == '1')
				res[i] -= merge(comp(m, j), comp(m + 1, j));
	}

	solve(l, m, lids);
	solve(m + 1, r, rids);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < 3; i++)
		for (int j = 1; j <= n; j++)
			cin >> a[j][i];

	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> ql[i] >> qr[i];
	}

	vector<int> ids(q);
	iota(ids.begin(), ids.end(), 1);

	solve(1, n, ids);
	for (int i = 1; i <= q; i++)
		cout << res[i] << '\n';
}