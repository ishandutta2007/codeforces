#include <bits/stdc++.h>
using namespace std;

const int maxN = 1234;

int T, n, u, v, w, k1, k2, a[maxN], b[maxN];
bool markA[maxN], markB[maxN];
vector<int> e[maxN];
int askA(int v) {
	int u;
	printf("A %d\n", v);
	fflush(stdout);
	scanf("%d", &u);
	return u;
}
int askB(int v) {
	int u;
	printf("B %d\n", v);
	fflush(stdout);
	scanf("%d", &u);
	return u;
}
void dfs(int u, int par) {
	if (markA[u] && w == -1) {
		w = u;
	}
	for (auto v : e[u]) {
		if (v == par) continue;
		dfs(v, u);
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			e[i].clear();
			markA[i] = 0;
			markB[i] = 0;
		}
		for (int i = 1; i < n; i++) {
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		scanf("%d", &k1);
		for (int i = 0; i < k1; i++) {
			scanf("%d", &a[i]);
			markA[a[i]] = 1;
		}
		scanf("%d", &k2);
		for (int i = 0; i < k2; i++) {
			scanf("%d", &b[i]);
			markB[b[i]] = 1;
		}
		int u = askB(b[0]);
		w = -1;
		dfs(u, 0);
		u = askA(w);
		if (markB[u]) {
			printf("C %d\n", w);
			fflush(stdout);
		} else {
			printf("C %d\n", -1);
			fflush(stdout);
		}
	}
}