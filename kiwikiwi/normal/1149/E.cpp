#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define maxN 223456

int n, m, h[maxN], xors[maxN], sg[maxN], tag[maxN];
int u, v, t, deg[maxN], q[maxN];
vector<int> e[maxN];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		++deg[v];
	}
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0)
			q[++t] = i;
	for (int i = 1; i <= t; i++) {
		int u = q[i];
		for (auto v : e[u]) {
			--deg[v];
			if (deg[v] == 0)
				q[++t] = v;
		}
	}
	int maxL = 0;
	for (int i = n; i >= 1; i--) {
		int u = q[i];
		for (auto v : e[u])
			tag[sg[v]] = i;
		while (tag[sg[u]] == i)
			++sg[u];
		maxL = max(maxL, sg[u]);
		xors[sg[u]] ^= h[u];
	}
	int lev = -1;
	for (int i = 0; i <= maxL; i++)
		if (xors[i] != 0) {
			lev = i;
		}
	if (lev == -1) {
		puts("LOSE");
		return 0;
	}
	puts("WIN");
	for (int u = 1; u <= n; u++) {
		if (sg[u] == lev && (h[u] ^ xors[lev]) < h[u]) {
			h[u] = h[u] ^ xors[lev];
			for (auto v : e[u]) {
				h[v] ^= xors[sg[v]];
				xors[sg[v]] = 0;
			}
			break;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", h[i]);
	puts("");
}