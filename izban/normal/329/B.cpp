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
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
string s[maxn];
int d[maxn][maxn];

bool ok(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

void bfs(int i, int j) {
	memset(d, 127, sizeof(d));
	queue<pair<int, int> > q;
	q.push(make_pair(i, j));
	d[i][j] = 0;
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = i + dx[k], ny = j + dy[k];
			if (ok(nx, ny) && s[nx][ny] != 'T' && d[nx][ny] > d[i][j] + 1) {
				d[nx][ny] = d[i][j] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n >> m) {
		for (int i = 0; i < n; i++) cin >> s[i];
		int xe = -1, ye = -1, xs = -1, ys = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == 'E') xe = i, ye = j;
				if (s[i][j] == 'S') xs = i, ys = j;
			}
		}
		bfs(xe, ye);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] >= '0' && s[i][j] <= '9' && d[i][j] <= d[xs][ys]) ans += s[i][j] - '0';
			}
		}
		cout << ans << endl;
	}

	return 0;
}