#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N = 100000;

int n;
int a[N];
int size[N];
vector <int> edge[N];
vector <int> cost[N];

LL dist[N];

int dfs(int u) {
	int ret = 1;
	for (int i=0; i<edge[u].size(); i++) {
		ret += dfs(edge[u][i]);
	}
	return size[u] = ret;
}

int main() {
	scanf ("%d", &n);
	
	for (int i=0; i<n; i++) {
		scanf ("%d", a + i);
	}
	
	int v, w;
	for (int i=1; i<n; i++) {
		scanf ("%d %d", &v, &w);
		v--;
		edge[v].push_back(i);
		cost[v].push_back(w);
	}
	
	dfs(0);
	
	queue <int> q;
	q.push(0);
	
	int ans = 0;
	while (q.size()) {
		int u = q.front();
		q.pop();
		
		if (dist[u] > a[u]) {
			ans += size[u];
			continue;
		}
		
		for (int i=0; i<edge[u].size(); i++) {
			int v = edge[u][i];
			int w = cost[u][i];
			
			dist[v] = max(0LL, dist[u] + w);
			q.push(v);
		}
	}
	
	printf ("%d\n", ans);
	
	return 0;
}