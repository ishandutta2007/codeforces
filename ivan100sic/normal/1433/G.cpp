// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k;
vector<pair<int, int>> e[1005];
int d[1005][1005];
int sol[1005], da[1005], db[1005], u[1005], v[1005];

void dj(int s, int* d) {
	fill(d+1, d+n+1, 1e9);
	set<pair<int, int>> pq;
	d[s] = 0;
	pq.insert({d[s], s});
	while (pq.size()) {
		auto [dx, x] = *pq.begin();
		pq.erase(pq.begin());
		for (auto [y, w] : e[x]) {
			if (d[y] > dx + w) {
				pq.erase({d[y], y});
				d[y] = dx + w;
				pq.insert({d[y], y});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		e[x].emplace_back(y, w);
		e[y].emplace_back(x, w);
		u[i] = x;
		v[i] = y;
	}

	for (int j=1; j<=n; j++) {
		dj(j, d[j]);
	}

	for (int i=0; i<k; i++) {
		int a, b;
		cin >> a >> b;

		for (int j=0; j<m; j++) {
			int r = min({d[a][b], d[a][u[j]] + d[v[j]][b], d[a][v[j]] + d[u[j]][b]});
			sol[j] += r;
		}
		cerr << '\n';
	}

	cout << *min_element(sol, sol+m) << '\n';
}