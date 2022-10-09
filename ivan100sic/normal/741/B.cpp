#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, wmax;
int b[1005], w[1005];
vector<int> e[1005];
int dp[1005][1005];
int vis[1005], brka;
vector<int> komps[1005];

void dfs(int x, int k) {
	vis[x] = k;
	komps[k].push_back(x);
	for (int y : e[x]) {
		if (!vis[y]) {
			dfs(y, k);
		}
	}
}

int main() {
	cin >> n >> m >> wmax;
	for (int i=1; i<=n; i++) {
		cin >> w[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	
	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			brka++;
			dfs(i, brka);
		}
	}

	for (int i=1; i<=brka; i++) {
		// sve
		int w_gr = 0;
		int b_gr = 0;
		for (int x : komps[i]) {
			w_gr += w[x];
			b_gr += b[x];
		}

		cerr << "Grupa tezine " << w_gr << " i lepote " << b_gr << '\n';

		for (int w_it=w_gr; w_it<=wmax; w_it++) {
			dp[i][w_it] = max(dp[i][w_it], 
				dp[i-1][w_it-w_gr] + b_gr);
		}

		// svaki pojedinacno

		for (int x : komps[i]) {
			for (int w_it = w[x]; w_it <= wmax; w_it++) {
				dp[i][w_it] = max(dp[i][w_it],
					dp[i-1][w_it - w[x]] + b[x]);
			}
		}

		// nijedan

		for (int w_it=0; w_it <= wmax; w_it++) {
			dp[i][w_it] = max(dp[i][w_it],
				dp[i-1][w_it]);
		}
	}

	int sol = 0;

	for (int w_it=0; w_it<=wmax; w_it++) {
		sol = max(sol, dp[brka][w_it]);
	}

	cout << sol;


}