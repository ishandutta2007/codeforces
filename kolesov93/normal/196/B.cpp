#include <stdio.h>
#include <algorithm>
#include <queue>
#include <deque>
#include <memory.h>
#include <map>
#include <set>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

#define N 1555
char w[N][N];
int nm[N][N];
int n, m;

struct cell {
	int x, y;
};

void mark(int x, int y, int c) {
	queue<cell> q;
	cell T;
	T.x = x; T.y = y;

	
	q.push(T);
	while (!q.empty()) {
		T = q.front(); q.pop();
		if (T.x < 0 || T.x >= n || T.y < 0 || T.y >= m || w[T.x][T.y] == '#' || nm[T.x][T.y] != 0) continue;
		nm[T.x][T.y] = c;
		
		cell W;
		W.x = T.x; W.y = T.y - 1;
		q.push(W);
		W.x = T.x; W.y = T.y + 1;
		q.push(W);
		W.x = T.x + 1; W.y = T.y;
		q.push(W);
		W.x = T.x - 1; W.y = T.y;
		q.push(W);
	}
}

int kn;
int Sn;

const int M = N*20;
int fir[N*N], tov[M], nxt[M], dx[M], dy[M];
int ke;

void add(int x, int y, int Dx, int Dy) {
	nxt[++ke] = fir[x]; tov[ke] = y; fir[x] = ke; dx[ke] = Dx; dy[ke] = Dy;
	if (ke & 1) add(y, x, -Dx, -Dy);
}

bool u[N*N];
int vx[N*N], vy[N*N];

bool cool = false;

void dfs(int c, int x, int y) {
	if (u[c]) {
		if (vx[c] != x || vy[c] != y) {
			cool = true;
		}
		return;
	}
	u[c] = true;
	vx[c] = x; vy[c] = y;

	for (int t = fir[c]; t; t = nxt[t]) {
		dfs(tov[t], x + dx[t], y + dy[t]);
	}
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	scanf("%d%d", &n, &m);
	cin.ignore();

	for (int i = 0; i < n; ++i) {
		gets(w[i]);
	}
	
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (w[i][j] != '#' && nm[i][j] == 0) {
				mark(i, j, ++kn);		
			}
			if (w[i][j] == 'S') {
				Sn = nm[i][j];
			}
		}

	for (int i = 0; i < n; ++i) {
		if (w[i][0] != '#' && w[i][m - 1] != '#') {
			add(nm[i][0], nm[i][m - 1], -1, 0);
		}
	}

	for (int i = 0; i < m; ++i) {
		if (w[0][i] != '#' && w[n - 1][i] != '#') {
			add(nm[0][i], nm[n - 1][i], 0, -1);
		}
	}

	dfs(Sn, 0, 0);
	if (cool) puts("Yes");
	else puts("No");

	return 0;
}