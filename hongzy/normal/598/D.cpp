#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1010;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, k, bel[N][N], cnt, ans[N * N];
char mp[N][N];

void dfs(int x, int y) {
	bel[x][y] = cnt;
	for(int i = 0; i < 4; i ++) {
		int a = x + dx[i], b = y + dy[i];
		if(mp[a][b] == '*') ans[cnt] ++;
		else if(!bel[a][b]) dfs(a, b);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", mp[i] + 1);
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) if(mp[i][j] == '.' && !bel[i][j]) {
			cnt ++;
			dfs(i, j);
		}
	}
	while(k --) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", ans[bel[u][v]]);
	}
	return 0;
}