#include <algorithm>
#include <cstdio>
using namespace std;

const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

int n, m;
char s[1010][1010];
bool vis[1010][1010];

bool fail(int x, int y) {
	return x < 1 || y < 1 || x > n || y > m || s[x][y] == '.';
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			bool tag = 0;
			for(int k = 0; k < 8; k ++) {
				int nx = i + dx[k], ny = j + dy[k];
				if(fail(nx, ny)) {
					tag = 1;
					break ;
				}
			}
			if(!tag) {
				for(int k = 0; k < 8; k ++) {
					int nx = i + dx[k], ny = j + dy[k];
					vis[nx][ny] = 1;
				}
			}
		}
	}
	bool tag(1);
	for(int i = 1; i <= n && tag; i ++)
		for(int j = 1; j <= m && tag; j ++)
			if(s[i][j] == '#' && !vis[i][j]) tag = 0;
	puts(tag ? "YES" : "NO");
	return 0;
}