#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <cmath>
#define sz(v) ((int)(v).size())
using namespace std;
typedef pair <int, int> pii;

const int N = 25;
const int M = 405;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};

int n;
int s[N][M];
int c[N][M];

int vis[N][M];

int main () {
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(s, 0, sizeof s);
		memset(c, 0, sizeof c);
		memset(vis, 0, sizeof vis);
		
		scanf("%d", &n);
		for (int i = 1;i <= n;++i) {
			char op;
			scanf("\n%c", &op);
			if (op == 'S') {
				int r1, r2, theta;
				scanf("%d%d%d", &r1, &r2, &theta);
				for (int r = r1;r < r2;++r) {
					s[r][theta] = 1;
				}
			}
			if (op == 'C') {
				int r, theta1, theta2;
				scanf("%d%d%d", &r, &theta1, &theta2);
				for (int theta = theta1;theta != theta2;theta = (theta + 1) % 360) {
					c[r][theta] = 1;
				}
			}
		}
		
		queue <pii> q;
		for (int i = 0;i < 360;++i) {
			q.push({0, i});
			vis[0][i] = 1;
		}
		while (sz(q)) {
			pii u = q.front(); q.pop();
			auto [x, y] = u;
			for (int d = 0;d <= 4 - 1;++d) {
				if (d == 0) if (s[x][y] == 1) continue;
				if (d == 1) if (s[x][(y + 1) % 360] == 1) continue;
				if (d == 2) if (c[x + 1][y] == 1) continue;
				if (d == 3) if (c[x][y] == 1) continue;
				int xt = x + dx[d];
				int yt = (y + dy[d] + 360) % 360;
				if ((0 > xt) || (xt > 20)) continue;
				if (vis[xt][yt]) continue;
				q.push({xt, yt});
				vis[xt][yt] = 1;
			}
		}
		
		// for (int i = 0;i <= 20;++i) {for (int j = 0;j < 360;++j) cout << vis[i][j]; cout << endl;}
		cout << (vis[20][0] ? "YES" : "NO") << endl;
	}
}