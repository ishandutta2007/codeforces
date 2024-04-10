#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 3010;
const int M = 60010;

struct Edge {
	int v, nxt;
} e[M];
int n, m, hd[N], p;
void clr() {
	fill(hd + 1, hd + n + 1, -1); p = 0;
}
void add(int u, int v) {
	e[p] = (Edge) {v, hd[u]}; hd[u] = p ++;
}
bool ins[N];
int cnt[N];
long long ans;
void dfs(int u, int d) {
	if(ins[u]) return ;
	if(d == 2) {
		ans += cnt[u] ++;
		return ;
	}
	ins[u] = 1;
	for(int i = hd[u]; ~ i; i = e[i].nxt)
		dfs(e[i].v, d + 1);
	ins[u] = 0;
}
void solve(int u) {
	fill(cnt + 1, cnt + n + 1, 0);
	dfs(u, 0);
}
int main() {
	scanf("%d%d", &n, &m); clr();
	for(int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	for(int u = 1; u <= n; u ++) {
		solve(u);
	}
	printf("%I64d\n", ans);
	return 0;
}