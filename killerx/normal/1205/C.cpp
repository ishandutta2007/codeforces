#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n;
int col[55][55];

int ask(int x0, int y0, int x1, int y1) {
	printf("? %d %d %d %d\n", x0 + 1, y0 + 1, x1 + 1, y1 + 1);
	fflush(stdout);
	int ans; scanf("%d", &ans);
	return !ans;
}

struct Dsu {
	int fa[15];
	Dsu() {rep(i, 15) fa[i] = i;}
	int Fa(int x) {return x == fa[x] ? x : fa[x] = Fa(fa[x]);}
	void merge(int x, int y) {fa[Fa(x)] = Fa(y);}
} dsu;

int X[] = {0, 1, 1, 2};
int Y[] = {1, 0, 2, 1};
const int dx[] = {0, 0, -2, 2};
const int dy[] = {-2, 2, 0, 0};

int que[1000000][2], lb, rb;
void bfs() {
	lb = rb = 0;
	rep(i, 4) que[rb][0] = X[i], que[rb ++][1] = Y[i];
	while (lb < rb) {
		int x = que[lb][0], y = que[lb ++][1];
		rep(i, 4) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || ~col[nx][ny]) continue;
			col[nx][ny] = ask(min(x, nx), min(y, ny), max(x, nx), max(y, ny)) ^ col[x][y];
			que[rb][0] = nx, que[rb ++][1] = ny;
		}
	}
}

int main() {
	scanf("%d", &n);
	memset(col, -1, sizeof col);
	col[0][0] = 1; col[n - 1][n - 1] = 0;
	for (int i = 0; i + 2 < n; i += 2) col[0][i + 2] = col[0][i] ^ ask(0, i, 0, i + 2);
	for (int i = 0; i + 2 < n; i += 2) col[i + 2][0] = col[i][0] ^ ask(i, 0, i + 2, 0);
	for (int i = 0; i + 1 < n; ++ i) {
		for (int j = i & 1; j + 1 < n && !(i + 1 == n - 1 && j + 1 == n - 1); j += 2) {
			col[i + 1][j + 1] = col[i][j] ^ ask(i, j, i + 1, j + 1);
		}
	}
	bool fnd = 0;
	rep(x, n - 2) rep(y, n - 2) if (!fnd && col[x][y] != col[x + 2][y + 2]) {
		rep(i, 4) X[i] += x, Y[i] += y;
		rep(i, 4) rep(j, 4) if (i != j && X[i] + Y[i] + 2 <= X[j] + Y[j] && X[i] <= X[j] && Y[i] <= Y[j]) {
			if (!ask(X[i], Y[i], X[j], Y[j])) dsu.merge(i, j);
		}
		if (dsu.Fa(0) == 0 && dsu.Fa(1) == 1 && dsu.Fa(2) == 2 && dsu.Fa(3) == 3) {
			dsu.merge(0, 1); dsu.merge(2, 3);
		}
		vi v[2], rt;
		rep(i, 4) if (dsu.Fa(i) == i) rt.pb(i);
		rep(i, 4) v[rt[0] != dsu.Fa(i)].pb(i);
		vi group(4);
		rep(i, rt.size()) rep(j, v[i].size()) group[v[i][j]] = i;
		if (col[x][y + 2] != col[x + 1][y + 1] || col[x + 1][y + 1] != col[x + 2][y]) {
			if (col[x][y + 2] != col[x + 1][y + 1]) {
				col[x][y + 1] = ask(x, y + 1, x + 2, y + 2) ^ col[x + 2][y + 2];
			} else {
				col[x + 1][y] = ask(x + 1, y, x + 2, y + 2) ^ col[x + 2][y + 2];
			}
		} else {
			if (group[2] == group[3]) {
				if (group[0] == group[2]) {
					if (col[x][y + 2] != col[x + 2][y + 2]) {
						col[x + 1][y + 2] = ask(x, y, x + 1, y + 2) ^ col[x][y];
					} else {
						col[x][y + 1] = ask(x, y + 1, x + 2, y + 2) ^ col[x + 2][y + 2];
					}
				} else {
					if (col[x][y + 2] != col[x + 2][y + 2]) {
						col[x][y + 1] = ask(x, y + 1, x + 2, y + 2) ^ col[x + 2][y + 2];
					} else {
						col[x + 1][y + 2] = ask(x, y, x + 1, y + 2) ^ col[x][y];
					}
				}
			} else {
				col[x][y + 1] = ask(x, y + 1, x + 2, y + 2) ^ col[x + 2][y + 2];
			}
		}
		vi coll(2, -1);
		rep(i, 4) if (~col[X[i]][Y[i]]) coll[group[i]] = col[X[i]][Y[i]];
		if (coll.size() == 2) {
			if (~coll[0]) coll[1] = 1 ^ coll[0];
			else coll[0] = 1 ^ coll[1];
		}
		rep(i, 4) col[X[i]][Y[i]] = coll[group[i]];
		fnd = 1; break;
	}
	bfs();
	puts("!");
	rep(i, n) {
		rep(j, n) putchar(col[i][j] + '0');
		puts("");
	}
	fflush(stdout);
	return 0;
}