#include <bits/stdc++.h>
using namespace std;

#define fir first
#define sec second

typedef pair <int, int> pii;
typedef pair <pii, int> ppi;
const int maxn = 1010;
const int maxlen = 1e7 + 10;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
ppi q[maxlen];
bool to[4][1 << 8];
char a[4][maxn][maxn];
int n, m, l, r, sx, sy, tx, ty, to_next[4], nxt[1 << 8], dp[4][maxn][maxn];

void make(char ch, bool b1, bool b2, bool b3, bool b4) {
	to[0][ch] = b1, to[1][ch] = b2, to[2][ch] = b3, to[3][ch] = b4;
}

void init() {
	to_next[0] = 1;
	to_next[1] = 0;
	to_next[2] = 3;
	to_next[3] = 2;
	nxt['+'] = '+';
	nxt['-'] = '|';
	nxt['|'] = '-';
	nxt['^'] = '>';
	nxt['>'] = 'v';
	nxt['<'] = '^';
	nxt['v'] = '<';
	nxt['L'] = 'U';
	nxt['R'] = 'D';
	nxt['U'] = 'R';
	nxt['D'] = 'L';
	nxt['*'] = '*';
	make('+', 1, 1, 1, 1);
	make('-', 0, 0, 1, 1);
	make('|', 1, 1, 0, 0);
	make('^', 1, 0, 0, 0);
	make('>', 0, 0, 0, 1);
	make('<', 0, 0, 1, 0);
	make('v', 0, 1, 0, 0);
	make('L', 1, 1, 0, 1);
	make('R', 1, 1, 1, 0);
	make('U', 0, 1, 1, 1);
	make('D', 1, 0, 1, 1);
	make('*', 0, 0, 0, 0);
}

bool pd(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= m;
}

int main() {
	init();
	char buf[maxn];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		gets(buf);
		for (int j = 1; j <= m; j++) {
			a[0][i][j] = getchar();
			for (int k = 1; k < 4; k++) {
				a[k][i][j] = nxt[a[k - 1][i][j]];
			}
		}
	}
	scanf("%d %d %d %d", &sx, &sy, &tx, &ty);
	if (sx == tx && sy == ty) {
		return puts("0"), 0;
	}
	dp[0][sx][sy] = 1;
	q[++r] = make_pair(make_pair(sx, sy), 0);
	for (; l <= r; ) {
		ppi u = q[l++];
		int px = u.fir.fir, py = u.fir.sec;
		if (!dp[(u.sec + 1) % 4][px][py]) {
			dp[(u.sec + 1) % 4][px][py] = dp[u.sec][px][py] + 1;
			q[++r] = make_pair(u.fir, (u.sec + 1) % 4);
		}
		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i], ny = py + dy[i];
			if (pd(nx, ny) && to[i][a[u.sec][px][py]] && to[to_next[i]][a[u.sec][nx][ny]]) {
				if (nx == tx && ny == ty) {
					printf("%d", dp[u.sec][px][py]);
					return 0;
				}
				if (!dp[u.sec][nx][ny]) {
					dp[u.sec][nx][ny] = dp[u.sec][px][py] + 1;
					q[++r] = make_pair(make_pair(nx, ny), u.sec);
				}
			}
		}
	}
	puts("-1");
	return 0;
}