// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

basic_string<int> e[500005][2];
basic_string<int> f[500005][2];

int n, m;
int d[500005], w[500005][2];
const int inf = 123123123;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		e[u][t] += v;
		f[v][t] += u;
	}

	for (int i=1; i<=n; i++) {
		d[i] = w[i][0] = w[i][1] = inf;
	}

	d[n] = 0;

	set<pair<int, int>> pq;
	pq.insert({d[n], n});

	while (pq.size()) {
		// azuriraj susede
		auto [dx, x] = *pq.begin();
		pq.erase(pq.begin());
		for (int c=0; c<2; c++) {
			for (int y : f[x][c]) {
				w[y][c] = min(w[y][c], dx);

				int dy = max(w[y][0], w[y][1]) + 1;
				if (dy < d[y]) {
					pq.erase({d[y], y});
					d[y] = dy;
					pq.insert({d[y], y});
				}
			}
		}
	}

	cout << (d[1] > inf/2 ? -1 : d[1]) << '\n';
	for (int i=1; i<=n; i++) {
		cout << (w[i][0] < w[i][1]);
	}
}