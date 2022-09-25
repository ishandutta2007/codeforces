#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = 2048;
const int inf = 1e9;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char dc[4] = {'v', '^', '>', '<'};

int n, m;
char a[maxn][maxn];
int o[maxn][maxn];

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d\n", &n, &m) == 2) {
		for (int i = 0; i < n; i++) {
			gets(a[i]);
		}

		queue<pair<int, pair<int, int> > > q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '.') {
					o[i][j] = 0;
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k], ny = j + dy[k];
						if (ok(nx, ny) && a[nx][ny] == '.') {
							o[i][j]++;
						}
					}
					if (o[i][j] == 1) q.push(make_pair(o[i][j], make_pair(i, j)));
				}
			}
		}

		while (!q.empty()) {
			pair<int, int> cur = q.front().second;
			q.pop();
			int i = cur.first, j = cur.second;
			if (a[i][j] != '.') continue;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (ok(nx, ny) && a[nx][ny] == '.') {
					o[i][j] = 0;
					o[nx][ny] = 0;
					a[i][j] = dc[k ^ 1];
					a[nx][ny] = dc[k];

					for (int nk = 0; nk < 4; nk++) {
						int nnx = nx + dx[nk], nny = ny + dy[nk];
						if (ok(nnx, nny) && a[nnx][nny] == '.') {
							o[nnx][nny]--;
							if (o[nnx][nny] == 1) q.push(make_pair(o[nnx][nny], make_pair(nnx, nny)));
						}
					}
					break;
				}
			}
		}
		bool ok = 1;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] == '.') ok = 0;
		if (!ok) {
			printf("Not unique\n");
			continue;
		}
		for (int i = 0; i < n; i++) puts(a[i]);
	}

	return 0;
}