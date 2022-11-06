#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 1000;
int main() {
	int n, m;
	int edges[500][500];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			edges[i][j] = false;
	for (int i = 0; i < m; ++i) {
		int x, y;
		scanf("%d %d", &x, &y);
		--x;
		--y;
		edges[x][y] = true;
		edges[y][x] = true;
	}
	vector<int> dist(n);
	for (int i = 1; i < n; ++i) dist[i] = INF;
	dist[0] = 0;
	vector<int> now = {0}, prev;
	while(now.size()) {
		prev.swap(now);
		now.clear();
		for (int from : prev)
			for (int to = 0; to < n; ++to)
				if (edges[from][to] != edges[0][n - 1]) {
					if (dist[to] > dist[from] + 1) {
						now.push_back(to);
						dist[to] = dist[from] + 1;
					}
				}
		//for (int i : now) printf("%d ", i);
		//printf("\n");

	}
	if (dist[n - 1] == INF) printf("-1\n");
	else printf("%d\n", dist[n - 1]);
}