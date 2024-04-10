#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

const int N = 210;
const int M = 210;

struct Edge {
	int v, nxt;
} e[M];
int hd[N], p, d[N];
void add(int x, int y) {
	e[p] = (Edge) {y, hd[x]}; hd[x] = p ++; d[y] ++;
}
void clr() {
	fill(hd + 1, hd + N, -1); p = 0;
}
char s[N][N], ans[N];
int len[N];

int main() {
	clr(); int t, fail = 0;
	scanf("%d", &t);
	for(int i = 1; i <= t; i ++) {
		scanf("%s", s[i] + 1);
		len[i] = strlen(s[i] + 1);
		if(i > 1) {
			int m = min(len[i], len[i - 1]);
			bool cmp = 0;
			for(int j = 1; j <= m; j ++) {
				if(s[i][j] != s[i - 1][j]) {
					add(s[i - 1][j], s[i][j]);
					cmp = 1; break ;
				}
			}
			if(!cmp && len[i - 1] > len[i]) {
				fail = 1;
			}
		}
	}
	if(!fail) {
		queue<int> q;
		for(int i = 'a'; i <= 'z'; i ++) {
			if(!d[i]) {
				q.push(i);
			}
		}
		int cnt = 0;
		while(!q.empty()) {
			int u = q.front(); q.pop();
			ans[++ cnt] = u;
			for(int i = hd[u]; ~ i; i = e[i].nxt) {
				int v = e[i].v;
				if(! -- d[v]) {
					q.push(v);
				}
			}
		}
		if(cnt < 26) {
			fail = 1;
		}
	}
	if(fail) {
		puts("Impossible");
	} else {
		for(int i = 1; i <= 26; i ++)
			putchar(ans[i]);
	}
	return 0;
}