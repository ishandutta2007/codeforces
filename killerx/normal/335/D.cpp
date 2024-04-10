#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e5, mxx = 3000;
int n, x[mxn + 5][2], y[mxn + 5][2], s[mxx + 5][mxx + 5], s0[mxx + 5][mxx + 5][4], ise[mxx + 5][mxx + 5];

bool chk(int lx, int ly, int rx, int ry) {
	if (s0[rx][ry][0] - (lx ? s0[lx - 1][ry][0] : 0) - (ry ? s0[rx][ry - 1][0] : 0) + (lx && ry ? s0[lx - 1][ry - 1][0] : 0) != 0) return 0;
	if (s0[rx][ry][1] - (ly ? s0[rx][ly - 1][1] : 0) - (rx ? s0[rx - 1][ry][1] : 0) + (rx && ly ? s0[rx - 1][ly - 1][1] : 0) != 0) return 0;
	return 1;
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d %d %d %d", &x[i][0], &y[i][0], &x[i][1], &y[i][1]);
	rep(i, n) s[x[i][0]][y[i][0]] ++, s[x[i][0]][y[i][1]] --, s[x[i][1]][y[i][0]] --, s[x[i][1]][y[i][1]] ++, ise[x[i][1] - 1][y[i][1] - 1] = 1;
	rep(i, mxx + 5) rep(j, mxx + 5) s[i][j] += (i ? s[i - 1][j] : 0) + (j ? s[i][j - 1] : 0) - (i && j ? s[i - 1][j - 1] : 0);
	rep(i, mxx + 5) rep(j, mxx + 5) s[i][j] += (i ? s[i - 1][j] : 0) + (j ? s[i][j - 1] : 0) - (i && j ? s[i - 1][j - 1] : 0);
	rep(i, n) {
		s0[x[i][0]][y[i][0]][0] ++, s0[x[i][0]][y[i][1] - 1][0] --, s0[x[i][1]][y[i][0]][0] --, s0[x[i][1]][y[i][1] - 1][0] ++; // right
		s0[x[i][0]][y[i][0]][1] ++, s0[x[i][0]][y[i][1]][1] --, s0[x[i][1] - 1][y[i][0]][1] --, s0[x[i][1] - 1][y[i][1]][1] ++; // down
		s0[x[i][0]][y[i][0] + 1][2] ++, s0[x[i][0]][y[i][1]][2] --, s0[x[i][1]][y[i][0] + 1][2] --, s0[x[i][1]][y[i][1]][2] ++; // left
		s0[x[i][0] + 1][y[i][0]][3] ++, s0[x[i][0] + 1][y[i][1]][3] --, s0[x[i][1]][y[i][0]][3] --, s0[x[i][1]][y[i][1]][3] ++; // up
	}
	rep(i, mxx + 5) rep(j, mxx + 5) rep(d, 4) s0[i][j][d] += (i ? s0[i - 1][j][d] : 0) + (j ? s0[i][j - 1][d] : 0) - (i && j ? s0[i - 1][j - 1][d] : 0);
	rep(i, mxx + 5) rep(j, mxx + 5) rep(d, 4) s0[i][j][d] += (i ? s0[i - 1][j][d] : 0) + (j ? s0[i][j - 1][d] : 0) - (i && j ? s0[i - 1][j - 1][d] : 0);
	rep(i, n) {
		int lx = x[i][0], ly = y[i][0];
		for (int rx = lx; rx <= mxx; ++ rx) {
			int ry = ly + (rx - lx);
			int nw = s[rx][ry] - (lx ? s[lx - 1][ry] : 0) - (ly ? s[rx][ly - 1] : 0) + (lx && ly ? s[lx - 1][ly - 1] : 0);
			int tot = (rx - lx + 1) * (ry - ly + 1);
			if (nw != tot) break;
			if (s0[rx][ly][2] - (lx ? s0[lx - 1][ly][2] : 0) - (ly ? s0[rx][ly - 1][2] : 0) + (lx && ly ? s0[lx - 1][ly - 1][2] : 0) != 0) break;
			if (s0[lx][ry][3] - (lx ? s0[lx - 1][ry][3] : 0) - (ly ? s0[lx][ly - 1][3] : 0) + (lx && ly ? s0[lx - 1][ly - 1][3] : 0) != 0) break;
			if (ise[rx][ry] && chk(lx, ly, rx, ry)) {
				printf("YES ");
				vector <int> ans;
				rep(i, n) if (x[i][0] >= lx && y[i][0] >= ly && x[i][1] - 1 <= rx && y[i][1] - 1 <= ry) ans.pb(i);
				printf("%d\n", (int) ans.size());
				rep(i, ans.size()) printf("%d%c", ans[i] + 1, " \n"[i + 1 == (int) ans.size()]);
				return 0;
			}
		}
	}
	printf("NO\n");
	return 0;
}