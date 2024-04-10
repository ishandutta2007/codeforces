#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
const int INF = 0x7fffffff;
const int maxlen = 1e7 + 10;
bool vis[maxn << 1];
int n, m, l, r, q[maxlen], dis[maxn << 1];

vector <int> e[maxn << 1];

int main() {
	char buf[maxn];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		gets(buf);
		for (int j = 1; j <= m; j++) {
			if (getchar() == '#') {
				e[i].push_back(n + j);
				e[n + j].push_back(i);
			}
		}
	}
	l = 1, r = 0;
	dis[1] = 0;
	vis[1] = 1;
	q[++r] = 1;
	for (; l <= r; ) {
		int u = q[l++];
		for (int v : e[u]) {
			if (!vis[v]) {
				dis[v] = dis[u] + 1;
				q[++r] = v;
				vis[v] = 1;
			}
		}
	}
	if (!vis[n]) {
		puts("-1");
	} else {
		printf("%d", dis[n]);
	}
	return 0;
}