#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

#define fs first
#define sc second
typedef pair<int, int> pii;

const int N = 1010;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int n, m, k, d[N][N];
bool vis[N][N];
char s[N][N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= m; j ++) {
			if(s[i][j] == '#') {
				vis[i][j] = 1;
			}
		}
	}
	queue<pii> q; pii st, ed;
	scanf("%d%d%d%d", &st.fs, &st.sc, &ed.fs, &ed.sc);
	q.push(st); d[st.fs][st.sc] = 0; vis[st.fs][st.sc] = 1;
	while(q.size()) {
		pii now = q.front(); q.pop();
		if(now == ed) {
			printf("%d\n", d[now.fs][now.sc]);
			return 0;
		}
		for(int j = 0; j < 4; j ++) {
			for(int i = 1; i <= k; i ++) {
				pii nxt(now.fs + i * dx[j], now.sc + i * dy[j]);
				if(nxt.fs >= 1 && nxt.fs <= n && nxt.sc >= 1 && nxt.sc <= m && !vis[nxt.fs][nxt.sc]) {
					vis[nxt.fs][nxt.sc] = 1;
					d[nxt.fs][nxt.sc] = d[now.fs][now.sc] + 1;
					q.push(nxt);
				} else break ;
			}
		}
	}
	puts("-1");
	return 0;
}