#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 400050;
int b[700], n, m, k;
int a[500], f[N];
int pos[500], g[4005000];
int cost[500][500];
inline int to(int x) {
	return 1 << x;
}
queue<int> q;

	int cnt = 1;
void bfs(int s) {
	memset(f, 0x3f, sizeof(f));
	f[s] = 0; q.push(s);
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = 1;i <= m; i++) {
			int y = x + b[i];
			if (y <= n + 1 && f[y] > n) {
				f[y] = f[x] + 1;
				q.push(y);
			}
			y = x - b[i];
			if (y > 0 && f[y] > n) {
				f[y] = f[x] + 1;
				q.push(y);
			}
		}
	}
}
int main() {
	cin >> n >> k >> m;
	for (int i = 1;i <= k; i++) 
		cin >> a[i];
	sort(a + 1,a + k + 1);
	pos[1] = a[1];
	for (int i = 2;i <= k; i++) 
	if (a[i] != a[i-1] + 1) {
		pos[++cnt] = a[i-1]+1;
		pos[++cnt] = a[i];
	}
	pos[++cnt] = a[k]+1;
	for (int i = 1;i <= m; i++) cin >> b[i];
	for (int i = 1;i <= cnt; i++) {
		bfs(pos[i]);
		for (int j = 1;j <= cnt; j++) 
			cost[i][j] = f[pos[j]];
	}
				
	memset(g, 0x3f, sizeof(g));
	g[0] = 0;
	for (int i = 1;i < 1 << cnt; i++) {
		int tmp = 0;
		for (int j = 1;j <= cnt; j++) 
			if (i & to(j-1)) tmp++;
		if (tmp & 1) continue;
		for (int j = 1;j <= cnt; j++) 
			if (i & to(j-1))
			for (int k = j + 1;k <= cnt; k++) 
				if (i & to(k-1)) 
					g[i] = min(g[i], g[i^to(k-1)^to(j-1)] + cost[k][j]);
	}
	if (g[(1<<cnt)-1] >= 1000000) cout << -1 << endl;
	else cout << g[(1 << cnt) - 1] << endl;
	return 0;
}