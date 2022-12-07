#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 1005;
const int dir[4][2] = {1, 0, 0, -1, 0, 1, -1, 0};
const char c[5] = "DLRU";
int n, m, K, d[N][N];
char g[N][N];
queue<pii> Q;
vector<char> ans;

int main() {
	scanf("%d%d%d", &n, &m, &K);
	for (int i = 0; i < n; i++) scanf("%s", g[i]);
	if (K % 2) printf("IMPOSSIBLE\n");
	else {
		int sx, sy;
		memset(d, -1, sizeof(d));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (g[i][j] == 'X') Q.push(mp(i, j)), d[i][j] = 0, sx = i, sy = j;
		while (!Q.empty()) {
			pii u = Q.front(); Q.pop();
			for (int i = 0; i < 4; i++) {
				int x = u.fi + dir[i][0];
				int y = u.se + dir[i][1];
				if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '*' || d[x][y] != -1) continue;
				d[x][y] = d[u.fi][u.se] + 1;
				Q.push(mp(x, y));
			}
		}

		for (int i = 0; i < K; i++) {
			int f = 0;
			for (int j = 0; j < 4; j++) {
				int x = sx + dir[j][0];
				int y = sy + dir[j][1];
				if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '*' || d[x][y] > K - i) continue;
				ans.pb(c[j]);
				f = 1;
				sx = x; sy = y;
				break;
			}
			if (!f) {
				printf("IMPOSSIBLE\n");
				return 0;
			}
		}
		for (int i = 0; i < sz(ans); i++) printf("%c", ans[i]); printf("\n");
	}
	return 0;
}