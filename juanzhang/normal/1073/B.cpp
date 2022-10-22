#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int n, top, st[maxn], pos[maxn]; bool vis[maxn];

int main() {
	scanf("%d", &n), top = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", st + i);
	}
	reverse(st + 1, st + n + 1);
	for (int i = 1; i <= n; i++) {
		pos[st[i]] = i;
	}
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		if (vis[x]) {
			printf("%d ", 0);
		} else {
			printf("%d ", top - pos[x] + 1);
			while (pos[x] <= top) vis[st[top--]] = 1;
		}
	}
	return 0;
}