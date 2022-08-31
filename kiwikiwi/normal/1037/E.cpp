#include <bits/stdc++.h>
using namespace std;

const int N = 223456;

int n, m, k, cnt, x[N], y[N], ans[N], deg[N], del[N], q[N];
set<int> e[N];

void deletev(int u) {
	if (deg[u] >= k || del[u]) return;
	queue<int> q;
	q.push(u);
	del[u] = 1;
	cnt--;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : e[u]) {
			--deg[v];
			if (deg[v] < k && !del[v]) {
				q.push(v);
				del[v] = 1;
				cnt--;
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", x + i, y + i);
		deg[x[i]]++;
		deg[y[i]]++;
		e[x[i]].insert(y[i]);
		e[y[i]].insert(x[i]);
	}
	cnt = n;
	for (int i = 1; i <= n; i++)
		deletev(i);
	ans[m] = cnt;
	for (int i = m - 1; i >= 0; i--) {
		if (!del[y[i]])
			--deg[x[i]];
		if (!del[x[i]])
			--deg[y[i]];
		e[x[i]].erase(y[i]);
		e[y[i]].erase(x[i]);
		deletev(x[i]);
		deletev(y[i]);
		ans[i] = cnt;
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans[i]);
	}
}