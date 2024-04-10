#include <bits/stdc++.h>
using namespace std;

const int N = 223456;

int n, m, a[N], b[N], c[N], vis[N];
vector<int> e[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		b[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		sort(e[i].begin(), e[i].end(), [&](int x, int y) {
			return b[x] < b[y];
		});
	}
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		c[++m] = u;
		for (auto v : e[u])
			if (!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
	}
	for (int i = 1; i <= n; i++) if (a[i] != c[i]) {
			puts("No");
			return 0;
		}
	puts("Yes");
}