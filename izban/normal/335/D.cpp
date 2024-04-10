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
#define y0 lal
#define y1 shatal
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int maxk = 3 * 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];
int a[maxk][maxk], sum[maxk][maxk], lu[maxk][maxk], rd[maxk][maxk], p[maxk][maxk];
int len[maxk][maxk][4];

bool ok(int x, int y) {
	return (x >= 0 && x < maxk && y >= 0 && y < maxk);
}

int get(int x, int y, int k) {
	int X = x, Y = y;
	if (!ok(x, y) || p[x][y] == -1) return 0;
	if (len[x][y][k] != -1) return len[x][y][k];
	int o = p[x][y];
	if ((x == x1[o] || x + 1 == x2[o]) + (y == y1[o] || y + 1 == y2[o]) < 2) return 0;
	if (ok(x + dx[k ^ 2], y + dy[k ^ 2]) && p[x][y] == p[x + dx[k ^ 2]][y + dy[k ^ 2]]) return 0;

	int res = 0;
	while (ok(x, y) && p[x][y] == o) {
		x += dx[k];
		y += dy[k];
		res++;
	}
	return len[X][Y][k] = res + get(x, y, k);
}

int Sum(int x1, int y1, int x2, int y2) {
	return sum[x1][y1] - (x2 ? sum[x2 - 1][y1] : 0) - (y2 ? sum[x1][y2 - 1] : 0) + (x2 && y2 ? sum[x2 - 1][y2 - 1] : 0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> n) {
		memset(lu, 0, sizeof(lu));
		memset(rd, 0, sizeof(rd));
		memset(len, -1, sizeof(len));
		memset(p, -1, sizeof(p));
		memset(a, 0, sizeof(a));

		for (int i = 0; i < n; i++) {
			scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
			for (int x = x1[i]; x < x2[i]; x++) for (int y = y1[i]; y < y2[i]; y++) a[x][y] = 1, p[x][y] = i;
			lu[x1[i]][y2[i] - 1] = 1;
			rd[x2[i] - 1][y1[i]] = 1;
		}
		bool found = 0;
		for (int i = 0; i < n; i++) if (x2[i] - x1[i] == y2[i] - y1[i]) {
			cout << "YES 1\n" << i + 1 << endl;
			found = 1;
			break;
		}
		if (found) continue;
		for (int i = 0; i < maxk; i++) for (int j = 0; j < maxk; j++) sum[i][j] = (i ? sum[i - 1][j] : 0) + (j ? sum[i][j - 1] : 0) - (i && j ? sum[i - 1][j - 1] : 0) + a[i][j];

		for (int cur = 0; cur < 2 * maxk; cur++) {
			vector<int> v;
			for (int i = 0; i < maxk; i++) {
				int j = cur - i;
				if (!(i >= 0 && i < maxk && j >= 0 && j < maxk)) continue;
				
				if (rd[i][j]) {
					while (1) {
						if (v.empty()) break;
						int oi = v.back();
						int oj = cur - oi;
						if (oi + min(get(oi, oj, 0), get(oi, oj, 3)) <= i) v.pop_back();
						else break;
					}

					if (!v.empty()) {
						int oi = v.back();
						int oj = cur - oi;
						if (min(get(i, j, 1), get(i, j, 2)) > i - oi && Sum(i, oj, oi, j) == (i - oi + 1) * (oj - j + 1)) {
							vector<int> ans;
							for (int o = 0; o < n; o++) if (x1[o] >= oi && x1[o] <= i && y1[o] >= j && y1[o] <= oj) ans.push_back(o + 1);
							cout << "YES " << ans.size() << endl;
							for (int i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i + 1 == ans.size()];
							found = 1;
							break;
						}
					}
				}
				if (lu[i][j]) v.push_back(i);
			}
			if (found) break;
		}
		if (!found) {
			cout << "NO" << endl;
		}
	}

	return 0;
}