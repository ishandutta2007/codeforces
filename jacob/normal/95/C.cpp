#include <cstdio>
#include <queue>
#include <numeric>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, ll> pii;

typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

const ll INF = ll(1e+18);

void dijkstra(const vvpii& edges, int s, vector<ll>& dist) {
	int n = edges.size();
	dist.assign(n, INF);
	dist[s] = 0;
	vector<char> final(n);
	priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > q;
	q.push(make_pair(ll(0), s));
	while (!q.empty()) {
		pair<ll, int> cur = q.top();
		q.pop();
		if (final[cur.second]) continue;
		final[cur.second] = true;
		for (int i = 0; i < int(edges[cur.second].size()); i++) {
			int nv = edges[cur.second][i].first;
			ll nd = edges[cur.second][i].second + cur.first;
			if (dist[nv] > nd) {
				dist[nv] = nd;
				q.push(make_pair(nd, nv));
			}
		}
	}
}

int main(void) {
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	vvpii edges1(n+1);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges1[u].push_back(pii(v, w));
		edges1[v].push_back(pii(u, w));
	}
	vvpii edges2(n+1);
	vector<ll> distances;
	for (int i = 1; i <= n; i++) {
		int t, c;
		cin >> t >> c;
		dijkstra(edges1, i, distances);
		for (int j = 1; j<= n; j++) {
			if (distances[j] <= t) edges2[i].push_back(pii(j, c));
		}
	}
	dijkstra(edges2, x, distances);
	if (distances[y] == INF)
		cout << -1 << endl;
	else
		cout << distances[y] << endl;
	return 0;
}