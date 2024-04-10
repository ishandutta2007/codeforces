#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

bool connected[100][100][4];
int w, h, n;

bool been[100][100];

int dfs(int x, int y, bool pass) {
	if (!pass)
		return 0;
	if (been[x][y])
		return 0;
	been[x][y] = true;
	return 1 + dfs(x + 1, y, connected[x][y][1]) + dfs(x - 1, y, connected[x][y][0]) + dfs(x, y - 1, connected[x][y][2]) + dfs(x, y + 1, connected[x][y][3]);
}

int main(void) {
	scanf("%d%d%d", &w, &h, &n);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			connected[i][j][0] = (i != 0);
			connected[i][j][1] = (i != w - 1);
			connected[i][j][2] = (j != 0);
			connected[i][j][3] = (j != h - 1);
		}
	}
	memset(been, 0, sizeof(been));
	for (int i = 0; i < n; i++) {
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		if (x1 != x2) {
			int y = y1;
			for (int x = x1; x < x2; x++) {
				if (y != 0)
					connected[x][y-1][3] = false;
				if (y != h)
					connected[x][y][2] = false;
			}
		} else {
			int x = x1;
			for (int y = y1; y < y2; y++) {
				if (x != 0)
					connected[x-1][y][1] = false;
				if (x != w)
					connected[x][y][0] = false;
			}
		}
	}
	vector<int> res;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			res.push_back(dfs(i, j, true));
		}
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < (int)res.size(); i++) {
		if (res[i] != 0)
			printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}