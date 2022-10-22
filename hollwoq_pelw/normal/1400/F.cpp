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

const int N = 1005, M = 5e3;

int tr[M][10], fail[M], endp[M], nnode;
string s;

int n, X, a[25], dp[N][M];

void backtrack(int n, int s) {
	if (s == X) {
		for (int i = 0; i < n; i++) {
			int s = 0;
			for (int j = i; j < n; j++) {
				s += a[j];
				if (X % s == 0 && s < X) return ;
			}
		}

		int p = 0;
		for (int i = 0; i < n; i++) {
			if (!tr[p][a[i]])
				tr[p][a[i]] = ++ nnode;
			p = tr[p][a[i]];
		}
		endp[p] = 1;
	}
	for (int i = 1; i < 10 && s + i <= X; i++)
		a[n] = i, backtrack(n + 1, s + i);
}

void Hollwo_Pelw() {
	cin >> s >> X, n = s.size();
	{
		backtrack(0, 0);

		queue<int> q;
		for (int i = 1; i < 10; i++)
			if (tr[0][i]) q.push(tr[0][i]);

		while (!q.empty()) {
			int u = q.front(); q.pop();

			endp[u] |= endp[fail[u]];
			for (int i = 1; i < 10; i++) {
				if (int v = tr[u][i]) {
					fail[v] = tr[fail[u]][i];
					q.push(v);
				} else {
					tr[u][i] = tr[fail[u]][i];
				}
			}
		}
	}

	for (int i = 0; i <= nnode; i++)
		tr[i][0] = i; // ignore zero

	memset(dp, 0x3f, sizeof dp);

	dp[0][0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0, k; j <= nnode; j++) if (dp[i][j] <= 1e9) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
			if (!endp[k = tr[j][s[i] - '0']])
				dp[i + 1][k] = min(dp[i + 1][k], dp[i][j]);
		}
	}

	cout << *min_element(dp[n], dp[n] + nnode + 1);
}