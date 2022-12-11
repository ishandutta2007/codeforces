#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int N = 520;
const int M = N * N * 12;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, hd[N], p, sx, sy, tx, ty, lim[N][N];
char s[N][N];

void dfs(int x, int y) {
	lim[x][y] --;
	if(!lim[x][y]) {
		if(x == tx && y == ty) {
			puts("YES"); exit(0);
		}
	} else {
		for(int i = 0; i < 4; i ++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(nx >= 1 && nx <= n && ny >= 1 && ny <= m && lim[nx][ny] >= 1) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			lim[i][j] = s[i][j] == 'X' ? 1 : 2;
			if(i == sx && j == sy) lim[i][j] = 2;
		}
	}
	dfs(sx, sy);
	puts("NO");
	return 0;
}