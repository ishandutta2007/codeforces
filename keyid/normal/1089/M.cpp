#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
typedef pair<int, int> pii;
int n;
char con[20][1010];

int col[10], bel[10], ee[10][10], e[10][10];
void dfs(int rt, int u){
	col[u] = rt;
	e[rt][u] = 1;
	rep(i, 1, n) if (col[i] != rt && e[u][i]) dfs(rt, i);
}

int q[10], head, tail;
int deg[10], use[10][100];

int xz[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, yz[8] = {-1, 0, 1, 1, -1, -1, 0, 1};
void init(){
	scanf("%d", &n);
	rep(i, 1, n) rep(j, 1, n) scanf("%d", &e[i][j]);
	rep(i, 1, n) dfs(i, i);
	rep(i, 1, n) col[i] = 0, e[i][i] = 1;
	int m = 0;
	rep(i, 1, n) if (!col[i]){
		m++;
		rep(j, 1, n) if (!col[j] && e[j][i] && e[i][j]){
			col[j] = 1;
			bel[j] = m;
		}
	}
	rep(i, 1, n) rep(j, 1, n) if (bel[i] != bel[j] && e[i][j]){
		ee[bel[i]][bel[j]] = 1;
	}
	rep(i, 1, m) deg[i] = col[i] = 0;
	rep(i, 1, m) rep(j, 1, m) if (ee[i][j]) deg[j]++;
	head = tail = 1;
	rep(i, 1, m)
		if (deg[i] == 0){
			col[i] = 1;
			q[tail++] = i;
		}
	while (head < tail){
		int u = q[head++];
		rep(v, 1, n) if (ee[u][v]){
			deg[v]--;
			if (deg[v] == 0)
				q[tail++] = v;
		}
	}
	printf("%d %d %d\n", 500, 4, m * 2);
	int cnt = 0;
	rep(i, 1, m){
		const int debug = 500;
		int u = q[i];
		rep(j, 1, 4) rep(k, 1, debug) con[j][k] = '.';
		int tmp = 0;
		rep(j, 1, n) if (bel[j] == u){
			con[4][++tmp] = j + '0';
		}
		rep(j, 1, cnt) if (use[i][j]){
			int x = 2, y = (j - 1) * 3 + 2;
			rep(t, 0, 7){
				int xx = x + xz[t], yy = y + yz[t];
                con[xx][yy] = '#';
			}
		}
		rep(i, 1, 4) {
			rep(j, 1, debug){
				printf("%c", con[i][j]);
				con[i][j] = '#';
			}
			printf("\n");
		}
		printf("\n");

		rep(v, 1, n) if (ee[u][v]){
			cnt++;
			for (int j = i; j <= m && q[j] != v; j++){
				use[j][cnt] = 1;
			}
		}


		rep(j, 1, cnt)
			if (use[i][j])
				con[2][(j - 1) * 3 + 2] = '.';
		rep(i, 1, 4) {
			rep(j, 1, debug){
				printf("%c", con[i][j]);
			}
			printf("\n");
		}
		if (i != m) printf("\n");

	}

}
int main(){
#ifdef local
	freopen("read.txt", "r", stdin);
#endif // local
	init();
    return 0;
}