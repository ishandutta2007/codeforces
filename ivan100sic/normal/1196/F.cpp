#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
vector<tuple<int, int, int>> edges;
vector<pair<int, int>> e[200005];

ll d[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.emplace_back(w, u, v);
	}
	sort(edges.begin(), edges.end());

	vector<int> nodes;

	for (int i=0; i<min(k, m); i++) {
		auto [w, u, v] = edges[i];
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
		nodes.push_back(u);
		nodes.push_back(v);
	}

	sort(nodes.begin(), nodes.end());
	nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());

	vector<ll> dists;

	for (int x : nodes) {
		for (int y : nodes)
			d[y] = 123123123123123123ll;
		d[x] = 0;
		set<pair<ll, int>> pq;
		pq.insert({0, x});
		while (pq.size()) {
			int x = pq.begin()->second;
			pq.erase(pq.begin());
			for (auto [y, w] : e[x]) {
				if (d[y] > d[x] + w) {
					pq.erase({d[y], y});
					d[y] = d[x] + w;
					pq.insert({d[y], y});
				}
			}
		}
		for (int y : nodes)
			if (y < x)
				dists.push_back(d[y]);
	}
	nth_element(dists.begin(), dists.begin()+k-1, dists.end());
	cout << dists[k-1] << '\n';
}