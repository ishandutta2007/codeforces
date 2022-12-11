#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define MP make_pair
using namespace std;
const int N = 55;
int dis[N][N], vis[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
deque<pair<int, int> > q;


int n, m;
bool col[N][N];
char s[N];

inline bool check(int x,int y) {
	if (x < 1 || x > n || y < 1 || y > m) return true;
	return false;
}

void bfs(int s,int t) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	while (q.size()) q.pop_back();
	q.push_back(MP(s, t)); dis[s][t] = 0;
	while (q.size()) {
		int x = q.front().first, y = q.front().second; q.pop_front();
		if (vis[x][y]) continue; vis[x][y] = 1; 
		for (int i = 0;i < 4; i++) {
			int xx = dx[i] + x, yy = dy[i] + y;
			if (check(xx, yy)) continue;
			int z = col[x][y] ^ col[xx][yy];
			if (dis[x][y] + z >= dis[xx][yy]) continue;
			dis[xx][yy] = dis[x][y] + z;
			if (!vis[xx][yy]) {
				if (z) q.push_back(MP(xx,  yy));
				else q.push_front(MP(xx, yy));
			}
		}
	}
}

int ans = 0x7ffffff, tmp;
int main() {
	cin >> n >> m;
	for (int i = 1;i <= n; i++) {
		scanf ("%s", s + 1);
		for (int j = 1;j <= m; j++) 
			if (s[j] == 'B') col[i][j] = 1;
	}
	for (int i = 1;i <= n; i++) {
		for (int j = 1;j <= m; j++) {
			bfs(i, j); tmp = 0;
			for (int i = 1;i <= n; i++) {
				for (int j = 1;j <= m; j++) {
					int res = dis[i][j];
					if (col[i][j]) res++;
					tmp = max(tmp, res);
				}
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}