#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 520;

int n, m, k, s, d;
char mp[N][N];
bool vis[N][N];

void dfs(int x, int y) {
	if(!d || x < 1 || x > n || y < 1 || y > m || mp[x][y] == '#' || vis[x][y]) return ;
	vis[x][y] = 1; d --;
	dfs(x - 1, y); dfs(x, y - 1); dfs(x + 1, y); dfs(x, y + 1);
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", mp[i] + 1);
		for(int j = 1; j <= m; j ++) {
			if(mp[i][j] == '.') {
				s ++; mp[i][j] = 'X';
			}
		}
	}
	bool tag = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(mp[i][j] == 'X') {
				d = s - k; dfs(i, j);
				tag = 1; break ;
			}
		}
		if(tag) break ;
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(vis[i][j]) putchar('.');
			else putchar(mp[i][j]);
		}
		putchar('\n');
	}
	return 0;
}