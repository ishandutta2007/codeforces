#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> e[100005];

long long d[100005];
int p[100005];

vector<int> sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}

	set<pair<long long, int>> pq;

	fill(d+1, d+n+1, 1e18);
	d[1] = 0;

	pq.insert({0, 1});

	while (!pq.empty()) {
		auto p = *pq.begin();
		pq.erase(pq.begin());

		int x = p.second;

		for (auto ee : e[x]) {
			int y = ee.first;
			int l = ee.second;

			if (d[x] + l < d[y]) {
				pq.erase({d[y], y});
				d[y] = d[x] + l;
				::p[y] = x;
				pq.insert({d[y], y});
			}
		}
	}

	if (p[n] == 0) {
		cout << -1;
		return 0;
	}

	for (int x=n; x; x=p[x]) {
		sol.push_back(x);
	}

	reverse(sol.begin(), sol.end());
	for (int x : sol) {
		cout << x << ' ';
	}

}