#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 11;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};


int n, m;
int a[maxn][maxn], b[maxn][maxn], d[maxn][maxn];
int c[maxn][maxn], f[maxn][maxn], cnt;
int ans[maxn * maxn];

void bfs1(int i, int j) {
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	c[i][j] = ++cnt;
	while (!q.empty()) {
		i = q.front().first, j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k], ny = j + dy[k];
			if (a[nx][ny] && !c[nx][ny]) {
				c[nx][ny] = cnt;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void bfs2(int i, int j) {
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	ans[c[i][j]]++;
	f[i][j] = 1;
	while (!q.empty()) {
		i = q.front().first, j = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = i + dx[k], ny = j + dy[k];
			if (a[nx][ny] && !b[nx][ny] && !f[nx][ny]) {
				f[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

void foo() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = 1;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				d[i][j] &= b[nx][ny] == 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) b[i][j] = d[i][j];
}

void bar() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			d[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				d[i][j] |= b[nx][ny] == 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) b[i][j] = d[i][j];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] && !c[i][j]) bfs1(i, j);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) b[i][j] = a[i][j];
	for (int i = 0; i < 3; i++) foo();
	for (int i = 0; i < 8; i++) bar();
	//for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cout << (a[i][j] && !b[i][j] ? "*" : " ") << (j == m ? "\n" : "");

	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) if (a[i][j] && !b[i][j] && !f[i][j]) bfs2(i, j);

	sort(ans + 1, ans + 1 + cnt);
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++) cout << ans[i] << " \n"[i == cnt];

	return 0;
}