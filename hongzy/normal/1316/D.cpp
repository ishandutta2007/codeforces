#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 1010;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
const char dc[] = {'D', 'R', 'U', 'L'};
int n;
pii a[N][N];
char s[N][N];
void fail() {
	puts("INVALID");
	exit(0);
}
bool vis[N][N], vis2[N][N];
void suc() {
	puts("VALID");
	for(int i = 1; i <= n; i ++) {
		s[i][n + 1] = 0;
		puts(s[i] + 1);
	}
	exit(0);
}
void dfs(int x, int y, int px, int py) {
	vis[x][y] = 1;
	for(int d = 0; d < 4; d ++) {
		int nx = x + dx[d], ny = y + dy[d];
		if(nx >= 1 && ny >= 1 && nx <= n && ny <= n && !vis[nx][ny] && a[nx][ny] == a[x][y]) {
			dfs(nx, ny, x, y);
		}
		if(pii(nx, ny) == pii(px, py)) {
			s[x][y] = dc[d];
		}
	}
}
void dfs2(int x, int y, int px, int py) {
	vis2[x][y] = 1; int dd = -1;
	for(int d = 0; d < 4; d ++) {
		int nx = x + dx[d], ny = y + dy[d];
		if(nx >= 1 && ny >= 1 && nx <= n && ny <= n && !vis2[nx][ny] && a[nx][ny] == pii(-1, -1)) {
			dd = d;
			dfs2(nx, ny, x, y);
		}
		if(pii(nx, ny) == pii(px, py)) {
			s[x][y] = dc[d];
		}
	}
	if(px < 0) {
		s[x][y] = dc[dd];
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			scanf("%d%d", &a[i][j].fs, &a[i][j].sc);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(a[i][j] == pii(i, j)) {
				s[i][j] = 'X'; dfs(i, j, -233, -233);
			}
		}
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++)
			if(a[i][j] != pii(-1, -1) && !vis[i][j])
				fail();
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(a[i][j] == pii(-1, -1)) {
				bool find = 0;
				for(int d = 0; d < 4; d ++) {
					int nx = i + dx[d], ny = j + dy[d];
					if(nx >= 1 && ny >= 1 && nx <= n && ny <= n && a[nx][ny] == pii(-1, -1)) {
						find = 1; break ;
					}
				}
				if(!find) fail();
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(a[i][j] == pii(-1, -1) && !vis2[i][j]) {
				dfs2(i, j, -23333, -23333);
			}
		}
	}
	suc();
	return 0;
}