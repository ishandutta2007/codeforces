#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
using namespace std;

/*
6 7 5 4
5 5 2 2 5
1 3 3
1 5 2
1 6 5
2 5 4
2 6 7
3 4 11
3 5 3

*/

const int INF = 1'000'000'000;

int n, m, v, k;
int a[205];

int d[205][605];
vector<pair<int, int>> e[605];

void dijkstra(int x, int* d) {
	set<pair<int, int>> pq;
	fill(d, d + n + 1, INF);

	d[x] = 0;
	pq.insert({ 0, x });
	while (!pq.empty()) {
		auto p = *pq.begin();
		pq.erase(pq.begin());

		int u = p.second;
		int du = p.first;

		for (auto ee : e[u]) {
			int v = ee.first;
			int w = ee.second;

			if (du + w < d[v]) {
				pq.erase({ d[v], v });
				d[v] = du + w;
				pq.insert({ d[v], v });
			}
		}
	}
}

namespace flow {
	struct edge {
		int u, v, capacity, flow, twin;
	};

	int vertices;
	vector<edge> e[1005];

	void add_edge(int u, int v, int capacity) {
		edge e1 = { u, v, capacity, 0, e[v].size() };
		edge e2 = { v, u, 0, 0, e[u].size() };

		e[u].push_back(e1);
		e[v].push_back(e2);
	}

	void reset() {
		for (int i = 0; i < vertices; i++) {
			e[i].clear();
		}
	}

	int maxflow(int source, int sink) {
		int flow = 0;

		while (1) {
			vector<int> dist(vertices, -1);
			vector<int> pre(vertices, -1);
			vector<int> pre_edge(vertices, -1);
			queue<int> q;

			dist[source] = 0;
			q.push(source);

			while (!q.empty()) {
				int x = q.front();
				q.pop();
				for (int i = 0; i < e[x].size(); i++) {
					auto ee = e[x][i];
					int y = ee.v;
					if (ee.flow < ee.capacity && dist[y] == -1) {
						dist[y] = dist[x] + 1;
						q.push(y);
						pre[y] = x;
						pre_edge[y] = i;
					}
				}
			}

			if (dist[sink] == -1) {
				return flow;
			}

			int add_flow = INF;
			{
				int y = sink;
				while (y != source) {
					int x = pre[y];
					auto ee = e[x][pre_edge[y]];
					add_flow = min(add_flow, ee.capacity - ee.flow);
					y = x;
				}
			}

			flow += add_flow;

			{
				int y = sink;
				while (y != source) {
					int x = pre[y];
					auto& ee = e[x][pre_edge[y]];
					auto& ree = e[y][ee.twin];
					ee.flow += add_flow;
					ree.flow -= add_flow;
					y = x;
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &v, &k);
	for (int i = 1; i <= v; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back({ v, w });
		e[v].push_back({ u, w });
	}

	for (int i = 1; i <= v; i++) {
		dijkstra(a[i], d[i]);
	}

	int l = 0, r = 1731311, o = 1731312;
	while (l <= r) {
		int m = (l + r) / 2;
		flow::reset();
		flow::vertices = v + n + 2;
		for (int i = 1; i <= v; i++) {
			flow::add_edge(0, i, 1);
			for (int j = 1; j <= n; j++) {
				if (d[i][j] <= m) {
					flow::add_edge(i, j + v, 1);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			flow::add_edge(j + v, n + v + 1, 1);
		}
		if (flow::maxflow(0, n + v + 1) >= k) {
			o = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	if (o == 1731312) {
		o = -1;
	}
	printf("%d\n", o);

	{
		int _;
		scanf("%d", &_);
	}
}