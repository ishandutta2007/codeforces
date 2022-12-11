#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

#define fs first
#define sc second

typedef pair<int, int> pii;

int n, k;
char s[4][110];
bool vis[4][110];
queue<pii> q;

int main() {
	int test;
	scanf("%d", &test);
	while(test --) {
		scanf("%d%d", &n, &k);
		pii st;
		for(int i = 1; i <= 3; i ++) {
			scanf("%s", s[i] + 1);
			for(int j = 1; j <= n; j ++) {
				if(s[i][j] == 's') {
					st = pii(i, j);
				}
				vis[i][j] = 0;
			}
		}
		q.push(st); vis[st.fs][st.sc] = 1;
		bool suc = 0;
		while(q.size()) {
			pii now = q.front(); q.pop();
//			printf("(%d, %d) is ok!\n", now.fs, now.sc);
			if(now.sc == n || (now.sc == n - 1 && s[now.fs][n] == '.') 
			|| (now.sc == n - 2 && s[now.fs][n - 1] == '.' && s[now.fs][n] == '.')) {
				suc = 1; break ;
			}
			if(s[now.fs][now.sc + 1] != '.') continue ;
			for(int i = -1; i <= 1; i ++) {
				if(now.fs + i >= 1 && now.fs + i <= 3 && now.sc + 3 <= n
				 && s[now.fs + i][now.sc + 1] == '.' && s[now.fs + i][now.sc + 2] == '.' && s[now.fs + i][now.sc + 3] == '.') {
					pii nxt(now.fs + i, now.sc + 3);
					if(!vis[nxt.fs][nxt.sc]) {
						vis[nxt.fs][nxt.sc] = 1;
						q.push(nxt);
					}
				}
			}
		}
		while(q.size()) q.pop();
		puts(suc ? "YES" : "NO");
	}
	return 0;
}