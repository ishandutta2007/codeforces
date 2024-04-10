#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 3 * (1 << 7);
const int inf = 1000000007;
const int mod = 1000000007;

int n, v, m, cnt;
int a[maxn], b[maxn], p[maxn], tm[maxn];
vector<int> e[maxn];
vector<pair<pair<int, int>, int> > ans;

bool bfs(int v) {
	queue<int> q;
	tm[v] = ++cnt;
	q.push(v);
	ll suma = 0, sumb = 0;
	while (!q.empty()) {
		v = q.front();
		suma += a[v];
		sumb += b[v];
		q.pop();
		for (int i = 0; i < e[v].size(); i++) {
			int to = e[v][i];
			if (tm[to] != cnt) {
				p[to] = v;
				tm[to] = cnt;
				q.push(to);
			}
		}
	}
	return suma == sumb;
}

void doitagain(int from, int to, int flow) {
	if (!flow || from == to) return;
	ans.push_back(make_pair(make_pair(from, to), flow));
	a[from] -= flow;
	a[to] += flow;
}

void doit(int from, int to, int flow) {
	if (from == to) return;
	int prev = p[to];
	int o = min(a[prev], flow);
	doitagain(prev, to, min(a[prev], flow));
	doit(from, prev, flow);
	doitagain(prev, to, flow - o);
}

bool solve(int v) {
	if (!bfs(v)) return 0;
	while (1) {
		bool ok = 0;
		for (int i = 1; i <= n; i++) if (a[i] > b[i] && tm[i] == cnt) {
			bfs(i);
			for (int j = 1; j <= n; j++) if (a[j] < b[j] && tm[j] == cnt) {
				doit(i, j, min(a[i] - b[i], b[j] - a[j]));
				ok = 1;
				break;
			}
			if (ok) break;
		}
		if (!ok) break;
	}
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	while (cin >> n >> v >> m) {
		for (int i = 1; i <= n; i++) e[i].clear();
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) random_shuffle(e[i].begin(), e[i].end());

		ans.clear(); bool ok = 1;
		for (int i = 1; i <= n; i++) if (a[i] != b[i]) if (!solve(i)) { printf("NO\n"); ok = 0; break;} if (!ok) continue;
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
	}

	return 0;
}