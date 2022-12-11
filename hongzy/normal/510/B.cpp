#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 110;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
char s[N][N];
bool vis[N][N], ins[N][N];

bool dfs(int x, int y, int lx = -1, int ly = -1) {
	ins[x][y] = 1;
	for(int k = 0; k < 4; k ++) {
		int nx = x + dx[k], ny = y + dy[k];
		if(nx < 1 || ny < 1 || nx > n || ny > m) continue ;
		if(s[nx][ny] != s[x][y]) continue ;
		if(nx == lx && ly == ny) continue ;
		if(ins[nx][ny]) {
			return 1;
		}
		if(!vis[nx][ny]) {
			if(dfs(nx, ny, x, y)) {
				return 1;
			}
		}
	}
	ins[x][y] = 0;
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	bool tag = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(!vis[i][j]) {
				vis[i][j] = 1;
				if(dfs(i, j)) {
					tag = 1;
					break ;
				}
			}
		}
	}
	puts(tag ? "Yes" : "No");
	return 0;
}