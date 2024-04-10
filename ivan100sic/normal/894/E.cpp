#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> e[1000005];
int komp[1000005], kk;

bool instek[1000005];
vector<int> stek;
int idx[1000005], lo[1000005], t;

void scc(int x) {
	t++;
	idx[x] = t;
	lo[x] = t;
	instek[x] = true;
	stek.push_back(x);

	for (auto ee : e[x]) {
		int y = ee.first;
		if (instek[y]) {
			lo[x] = min(lo[x], idx[y]);
		} else if (idx[y] == 0) {
			scc(y);
			lo[x] = min(lo[x], lo[y]);
		} else {}
	}

	if (idx[x] == lo[x]) {
		kk++;
		while (1) {
			int y = stek.back();
			stek.pop_back();
			instek[y] = false;
			komp[y] = kk;
			if (y == x) {
				break;
			}
		}
	}
}

long long budzi(int x) {
	int l = 1, r = 15000, o = 0;
	while (l <= r) {
		int m = (l+r) / 2;
		if (m*(m-1) / 2 <= x) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	return 1ll * x * o - o * 1ll * (o+1) * (o-1) / 6;
}


vector<pair<int, int>> g[1000005];
long long unutar[1000005];

/*

vector<int> toporder;
bool topvis[1000005];
void topdfs(int x) {
	topvis[x] = true;
	for (auto ee : g[x]) {
		int y = ee.first;
		if (!topvis[y]) {
			topdfs(y);
		}
	}
	toporder.push_back(x);
}
*/

long long dp[1000005];

int s0;

long long solve(int x) {
	if (dp[x] != -1) {
		return dp[x];
	}

	dp[x] = unutar[x];

	for (auto ee : g[x]) {
		int y = ee.first;
		int w = ee.second;
		dp[x] = max(dp[x], unutar[x] + w + solve(y));
	}

	return dp[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<=10; i++) {
		cerr << budzi(i) << '\n';
	}

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
	}
	cin >> s0;

	for (int i=1; i<=n; i++) {
		if (!idx[i]) {
			scc(i);
		}
	}

	for (int x=1; x<=n; x++) {
		for (auto ee : e[x]) {
			int y = ee.first;
			int w = ee.second;

			if (komp[x] == komp[y]) {
				unutar[komp[x]] += budzi(w);
			} else {
				g[komp[x]].push_back({komp[y], w});
			}
		}
	}

	cerr << kk << '\n';

	// toposort
	/*
	for (int i=1; i<=kk; i++) {
		if (!topvis[i]) {
			topdfs(i);
		}
	}

	reverse(toporder.begin(), toporder.end());
	long long sol = 0;

	for (int x : toporder) {
		dp[x] += unutar[x];
		sol = max(sol, dp[x]);
		for (auto ee : g[x]) {
			int y = ee.first;
			int w = ee.second;
			dp[y] = max(dp[y], dp[x] + w);
		}
	}
	*/

	fill(dp+1, dp+kk+1, -1);
	cout << solve(komp[s0]);

}