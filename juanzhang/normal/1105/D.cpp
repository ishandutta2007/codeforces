#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
const int maxn = 1010, dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int n, m, k, a[10], cnt[10]; char s[maxn][maxn]; bool vis[maxn][maxn];
struct node {
	int x, y, d;
};
queue <node> q;
vector <pii> f[10];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; j++) {
			vis[i][j] = s[i][j] != '.';
			if (s[i][j] > 47 && s[i][j] < 58) {
				f[s[i][j] - 48].push_back(pii(i, j)), cnt[s[i][j] - 48]++;
			}
		}
	}
	while (1) {
		bool flg = 0;
		for (int st = 1; st <= k; st++) {
			for (pii p : f[st]) {
				q.push(node{p.first, p.second, 0});
			}
			f[st].clear();
			while (!q.empty()) {
				node p = q.front(); q.pop();
				if (p.d == a[st]) {
					f[st].push_back(pii(p.x, p.y));
					continue;
				}
				for (int i = 0; i < 4; i++) {
					int tx = p.x + dx[i], ty = p.y + dy[i];
					if (tx < 1 || ty < 1 || tx > n || ty > m || vis[tx][ty]) {
						continue;
					}
					vis[tx][ty] = 1, cnt[st]++, q.push(node{tx, ty, p.d + 1}), flg = 1;
				}
			}
		}
		if (!flg) break;
	}
	for (int i = 1; i <= k; i++) {
		printf("%d ", cnt[i]);
	}
	return 0;
}

/*
4 7 2
13 1
....###
.#..1..
.#.###.
2#.....
*/