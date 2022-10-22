#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n, m;
int deg[mxn];
std::vector <int> adj[mxn];
int f[mxn];
std::priority_queue <std::pair <int, int> > pq;

inline void reg(int u, int w) {
	pq.push({-w, u});
}

int main() {
	scanf("%d %d", &n, &m);
	rep(i, m) {
		int u, v;
		scanf("%d %d", &u, &v);
		-- u, -- v;
		adj[v].push_back(u);
		deg[u] += 1;
	}
	rep(i, n) if (i == n - 1) reg(i, 0);
	else if (!deg[i]) reg(i, 1e9 + 7);
	while (!pq.empty()) {
		int u = pq.top().second;
		int w = -pq.top().first;
		pq.pop();
		if (!~deg[u]) continue;
		f[u] = w;
		deg[u] = -1;
		for (int v : adj[u]) {
			if (deg[v] > 0) {
				-- deg[v];
				reg(v, deg[v] + w + 1);
			}
		}
	}
	printf("%d\n", f[0]);
	return 0;
}