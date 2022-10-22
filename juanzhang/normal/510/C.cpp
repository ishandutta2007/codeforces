#include <bits/stdc++.h>
using namespace std;

const int maxn = 30;
char str[110][110];
int n, now, a[maxn], vis[maxn];

vector <int> e[maxn];

bool dfs(int u) {
	if (vis[u]) {
		return vis[u] > 1;
	}
	vis[u] = 1;
	for (int v : e[u]) {
		if (!dfs(v)) {
			return 0;
		}
	}
	a[++now] = u;
	vis[u] = 2;
	return 1;
}

int main() {
	scanf("%d", &n);
	gets(str[0]);
	for (int i = 1; i <= n; i++) {
		gets(str[i]);
	}
	for (int i = 1; i < n; i++) {
		int j = 0, l1 = strlen(str[i]), l2 = strlen(str[i + 1]);
		for (; j < min(l1, l2) && str[i][j] == str[i + 1][j]; j++);
		if (j == l2) {
			return puts("Impossible"), 0;
		}
		if (j < l1) {
		    e[str[i][j] - 'a'].push_back(str[i + 1][j] - 'a');
		}
	}
	for (int i = 0; i < 26; i++) {
		if (!dfs(i)) {
			return puts("Impossible"), 0;
		}
	}
	for (int i = 26; i; i--) {
		putchar(a[i] + 'a');
	}
	return 0;
}