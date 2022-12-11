#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stack>
#include <queue>
#include <ctime>
#include <set>
using namespace std;

#define fs first
#define sc second
#define pb push_back 
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 40 + 4;
const int M = 1004;
const int mo = 1e9 + 7;
const int INF = 1e8 + 10;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, k, q, a[M][M], G[N][N], d[M][M][N]; //G[x][y] : xy 
vector<pii> vec[N];
void bfs(int col) {
	queue<pii> q;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			d[i][j][col] = -1;
	for(pii u : vec[col]) {
		q.push(u); d[u.fs][u.sc][col] = 0;
	}
	while(q.size()) {
		pii u = q.front(); q.pop();
		int t = a[u.fs][u.sc];
		G[t][col] = G[col][t] = min(G[col][t], d[u.fs][u.sc][col]);
		for(int i = 0; i < 4; i ++) {
			pii v = mp(u.fs + dx[i], u.sc + dy[i]);
			if(v.fs < 1 || v.fs > n || v.sc < 1 || v.sc > m) continue ;
			if(-1 == d[v.fs][v.sc][col]) {
				d[v.fs][v.sc][col] = d[u.fs][u.sc][col] + 1;
				q.push(v);
			}
		}
	}
}
int myabs(int x) {
	return x > 0 ? x : -x;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= k; i ++)
		fill(G[i] + 1, G[i] + k + 1, INF), G[i][i] = 0;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]);
			vec[a[i][j]].pb(mp(i, j));
			if(i != 1 && a[i - 1][j] != a[i][j]) {
				int u = a[i - 1][j], v = a[i][j];
				G[u][v] = G[v][u] = 1;
			}
			if(j != 1 && a[i][j - 1] != a[i][j]) {
				int u = a[i][j - 1], v = a[i][j];
				G[u][v] = G[v][u] = 1;
			}
		}
	}
	for(int i = 1; i <= k; i ++) bfs(i);
	for(int w = 1; w <= k; w ++)
		for(int u = 1; u <= k; u ++)
			for(int v = 1; v <= k; v ++)
				G[u][v] = min(G[u][v], G[u][w] + G[w][v] + 1);
	scanf("%d", &q);
	for(int i = 1; i <= q; i ++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans = myabs(x1 - x2) + myabs(y1 - y2);
		for(int x = 1; x <= k; x ++) {
			for(int y = 1; y <= k; y ++) {
				ans = min(ans, d[x1][y1][x] + d[x2][y2][y] + G[x][y] + 1 + (x != y));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}