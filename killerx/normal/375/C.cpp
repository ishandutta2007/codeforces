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

int n, m;
char s[25][25];
int wei[8], cnt;
int px[8], py[8];
int que[1000000][3], lb, rb;
int dis[25][25][256];

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
	n = read(), m = read();
	rep(i, n) scanf("%s", s[i]);
	int sx = -1, sy = -1;
	rep(i, n) rep(j, m) {
		if (s[i][j] == 'S') sx = i, sy = j;
		else if (s[i][j] >= '1' && s[i][j] <= '8') {
			px[s[i][j] - '1'] = i, py[s[i][j] - '1'] = j;
			cnt = max(cnt, s[i][j] - '0');
		}
	}
	rep(i, cnt) wei[i] = read();
	rep(i, n) rep(j, m) {
		if (s[i][j] == 'B') {
			px[cnt] = i, py[cnt] = j;
			wei[cnt ++] = -0x3f3f3f;
		}
	}
	memset(dis, -1, sizeof(dis));
	que[rb][0] = sx, que[rb][1] = sy, que[rb ++][2] = 0;
	dis[sx][sy][0] = 0;
	while (lb < rb) {
		int x = que[lb][0], y = que[lb][1], msk = que[lb ++][2];
//		printf("dis[%d][%d][%d] = %d\n", x, y, msk, dis[x][y][msk]);
		rep(d, 4) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (s[nx][ny] != '.' && s[nx][ny] != 'S') continue;
			int nmsk = msk;
			if (d == 2) rep(i, cnt) if (px[i] == x && py[i] < y) nmsk ^= 1 << i;
			if (d == 3) rep(i, cnt) if (px[i] == nx && py[i] < ny) nmsk ^= 1 << i;
			if (!~dis[nx][ny][nmsk]) {
				dis[nx][ny][nmsk] = dis[x][y][msk] + 1;
				que[rb][0] = nx, que[rb][1] = ny, que[rb ++][2] = nmsk;
			}
		}
	}
	int ans = 0;
	rep(msk, 1 << cnt) {
		if (!~dis[sx][sy][msk]) continue;
		int sum = -dis[sx][sy][msk];
		rep(i, cnt) if (msk >> i & 1) sum += wei[i];
		if (sum > ans) ans = sum;
	}
	printf("%d\n", ans);
	return 0;
}

/*
7 7
.......
.1###2.
.#...#.
.#.B.#.
.3...4.
..##...
......S
100
100
100
100

7 8
........
........
....1B..
.S......
....2...
3.......
........
100
-100
100

*/