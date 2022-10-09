#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

const int MAXN = 131072;
const int DESTINATION = 2*MAXN;

long long d[4*MAXN];
vector<pair<int, int>> e[4*MAXN];

set<pair<long long, int>> pq;

void find_cover(int l, int r, vector<int>& a, int node=1, int nl=1, int nr=MAXN) {
	if (r < nl || nr < l) {
		return;
	}

	if (l <= nl && nr <= r) {
		a.push_back(node);
		return;
	}

	int nm = (nl + nr) >> 1;

	find_cover(l, r, a, 2*node, nl, nm);
	find_cover(l, r, a, 2*node+1, nm+1, nr);
}

int n, q, s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q >> s;

	s += MAXN - 1;

	while (q--) {
		int t, l, r, v, u, w;
		cin >> t;
		if (t == 1) {
			cin >> v >> u >> w;
			v += MAXN - 1;
			u += MAXN - 1;
			e[v].push_back({u + DESTINATION, w});
		} else if (t == 2) {
			cin >> v >> l >> r >> w;
			v += MAXN - 1;
			vector<int> a;
			find_cover(l, r, a);
			for (int u : a) {
				e[v].push_back({u + DESTINATION, w});
			}
		} else {
			cin >> v >> l >> r >> w;
			v += MAXN - 1;
			vector<int> a;
			find_cover(l, r, a);
			for (int u : a) {
				e[u].push_back({v + DESTINATION, w});
			}
		}
	}
	// grane na dole su u destination
	for (int i=2*MAXN-1; i>1; i--) {
		int j = i >> 1;
		e[j+DESTINATION].push_back({i+DESTINATION, 0});
	}
	// grane na gore su u origin
	for (int i=2*MAXN-1; i>1; i--) {
		int j = i >> 1;
		e[i].push_back({j, 0});
	}

	// sve grane od destination do origin
	for (int i=1; i<2*MAXN; i++) {
		e[i+DESTINATION].push_back({i, 0});
	}

	// dijkstra
	for (int i=1; i<2*MAXN; i++) {
		d[i] = 123'123'123'123'123'123ll;
		d[i + DESTINATION] = 123'123'123'123'123'123ll;
	}

	d[s] = 0;
	pq.insert({0, s});

	while (!pq.empty()) {
		auto p = *pq.begin();
		pq.erase(pq.begin());

		int x = p.second;
		long long d0 = p.first;

		for (auto edz : e[x]) {
			int y = edz.first;
			int l = edz.second;

			long long d1 = d0 + l;

			if (d1 < d[y]) {
				pq.erase({d[y], y});
				pq.insert({d1, y});
				d[y] = d1;
			}
		}
	}

	for (int i=1; i<=n; i++) {
		long long x = d[i + MAXN - 1];
		if (x == 123'123'123'123'123'123ll) {
			x = -1;
		}
		cout << x << ' ';
	}



}