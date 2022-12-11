#include <algorithm>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 23;
const int M = 1 << 8;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int n, m, sx, sy, b, c;
int bid[N][N], w[N], val[M], dp[N][N][M][M], s1[N][N], s2[N][N];
bool Map[N][N];
char s[N][N]; //dp[x][y][S1][S2] : (x, y) S1,S2T, B, 1, 0 
struct node {
	int x, y, S1, S2; int t;
	int &val() { return dp[x][y][S1][S2]; }
};
queue<node> q;
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(s[i][j] == 'S') { sx = i; sy = j; }
			if(s[i][j] == 'B') bid[i][j] = b ++;
			if(isdigit(s[i][j])) c ++;
			Map[i][j] = s[i][j] == 'S' || s[i][j] == '.';
		}
	}
	for(int i = 0; i < c; i ++) scanf("%d", w + i);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			s1[i][j] = s1[i][j - 1]; s2[i][j] = s2[i][j - 1];
			if(s[i][j] == 'B') s2[i][j] ^= 1 << bid[i][j];
			if(isdigit(s[i][j])) s1[i][j] ^= 1 << (s[i][j] - '1');
		}
	}
	memset(dp, -1, sizeof dp);
	q.push({sx, sy, 0, 0, 0}); dp[sx][sy][0][0] = 0;
	while(!q.empty()) {
		node u = q.front(); q.pop();
		for(int i = 0; i < 4; i ++) {
			node v = {u.x + dx[i], u.y + dy[i], u.S1, u.S2, dy[i] == 0};
			if(v.x < 1 || v.x > n || v.y < 1 || v.y > m || !Map[v.x][v.y]) continue ;
			if(dy[i] == 0) {
				if(dx[i] < 0) {
					v.S1 ^= s1[v.x][v.y];
					v.S2 ^= s2[v.x][v.y];
				} else {
					v.S1 ^= s1[u.x][u.y];
					v.S2 ^= s2[u.x][u.y];
				}
			}
			if(v.val() == -1) { q.push(v); v.val() = u.val() + 1; }
		}
	}
	int ans = 0;
	for(int i = 0; i < (1 << c); i ++) if(~ dp[sx][sy][i][0]) {
		int val = 0; 
		for(int j = 0; j < c; j ++) if(i >> j & 1) val += w[j];
		ans = max(ans, val - dp[sx][sy][i][0]);
	} 
	printf("%d\n", ans);
	return 0;
}