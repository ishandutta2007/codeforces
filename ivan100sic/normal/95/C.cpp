#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, poc, kraj;
basic_string<pair<int, int>> e[1005], f[1005];
int t[1005], c[1005];
ll d[1005][1005];

template<class T>
void dijkstra(T e, ll* d, int x) {
	fill(d+1, d+n+1, 1e18);
	d[x] = 0;
	set<pair<ll, int>> pq;
	pq.insert({0, x});
	while (pq.size()) {
		auto [dd, x] = *pq.begin();
		pq.erase(pq.begin());
		for (auto [y, l] : e[x]) {
			if (d[y] > dd + l) {
				pq.erase({d[y], y});
				d[y] = dd + l;
				pq.insert({d[y], y});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> poc >> kraj;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u] += {v, w};
		e[v] += {u, w};
	}
	for (int i=1; i<=n; i++)
		cin >> t[i] >> c[i];

	for (int i=1; i<=n; i++)
		dijkstra(e, d[i], i);

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (d[i][j] <= t[i]) {
				// cerr << i << " --> " << j << ' ' << c[i] << '\n';
				f[i] += {j, c[i]};
			}

	dijkstra(f, d[1003], poc);
	if (d[1003][kraj] > 1e16)
		cout << "-1\n";
	else
		cout << d[1003][kraj] << '\n';
}