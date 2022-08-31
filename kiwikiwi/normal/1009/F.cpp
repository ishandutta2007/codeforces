#include <bits/stdc++.h>
using namespace std;

const int N = 1010000;
int n, u, v;
int dep[N], pre[N];
vector<int> e[N], d[N];
pair<int, int> ans[N];

void dfs(int u, int f) {
	dep[u] = 0;
	for (auto v : e[u]) if (v != f) {
			dfs(v, u);
			dep[u] = max(dep[u], dep[v]);
		}
	dep[u] += 1;
	int s = -1;
	ans[u] = make_pair(1, dep[u] - 1);
	for (auto v : e[u]) if (v != f) {
			if (dep[v] + 1 == dep[u]) {
				s = v;
				pre[u] = pre[v];
				ans[u] = make_pair(ans[v].first, ans[v].second);
				break;
			}
		}
	if (s == -1) {
		pre[u] = u;
		d[u].push_back(1);
		ans[u] = make_pair(1, 0);
	} else {
		ans[u] = max(ans[u], make_pair(1, dep[u] - 1));
		d[pre[u]].push_back(1);
		for (auto v : e[u]) if (v != f && v != s) {
				for (int i = 0; i < dep[v]; i++) {
					d[pre[u]][dep[u] - 2 - i] += d[pre[v]][dep[v] - 1 - i];
					ans[u] = max(ans[u], make_pair(d[pre[u]][dep[u] - 2 - i], dep[u] - 2 - i));
				}
			}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) printf("%d\n", dep[i] - ans[i].second - 1);
}