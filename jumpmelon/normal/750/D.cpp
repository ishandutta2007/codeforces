#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300 + 10;
const int D[][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int n;
int t[40];
bool mp[MAXN][MAXN];
bool vis[MAXN][MAXN][8][6][32];

void dfs(int x, int y, int dir, int step, int cnt) {
	if (vis[x][y][dir][step][cnt] || cnt > n) return;
	vis[x][y][dir][step][cnt] = 1;
	mp[x][y] = 1;
	if (step) {
		dfs(x+D[dir][0], y+D[dir][1], dir, step-1, cnt);
	} else {
		dfs(x, y, (dir-1+8)%8, t[cnt+1], cnt+1);
		dfs(x, y, (dir+1)%8, t[cnt+1], cnt+1);
	}
}

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; ++i) scanf("%d", t+i);
	dfs(150, 150, 0, t[1]-1, 1);
	int ans = 0;
	for (int i=0; i<=300; ++i) {
		for (int j=0; j<=300; ++j) {
			if (mp[i][j]) {
				++ ans;
			}
		}
	}
	printf("%d", ans);
}