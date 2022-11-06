#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef long long llong;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int sx, sy;
int n, m;
char str[200];
char maze[100][100];

int ans[4];
int mx[4] = { 1, 0, -1, 0 };
int my[4] = { 0, 1, 0, -1 };

bool valid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && maze[x][y] != '#';
}
int check(int d) {
	if (d == 4) {
		int x = sx, y = sy;
		for (char * c = str; *c; ++c) {
			x += mx[ans[*c - '0']];
			y += my[ans[*c - '0']];
			if (!valid(x, y)) return 0;
			if (maze[x][y] == 'E') return 1;
		}
		return 0;
	}
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		int j;
		for (j = 0; j < d; ++j) {
			if (ans[j] == i) break;
		}
		if (j != d) continue;
		ans[d] = i;
		ret += check(d + 1);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> maze[i];
		for (int j = 0; j < m; ++j) {
			if (maze[i][j] == 'S') sx = i, sy = j;
		}
	}
	cin >> str;
	printf("%d\n", check(0));

	return 0;
}