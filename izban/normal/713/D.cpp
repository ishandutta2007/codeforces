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

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = 10;
const int MAXN = 1 << MAXK;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

int n, m;
int a[MAXN][MAXN];
int s[MAXN][MAXN];
int r[MAXN][MAXN][MAXK][MAXK];
int mx[MAXN][MAXN];

int sum(int lx, int ly, int rx, int ry) {
	int ans = 0;
	ans += s[rx][ry];
	ans -= s[rx][ly - 1];
	ans -= s[lx - 1][ry];
	ans += s[lx - 1][ly - 1];
	return ans;
}

int lg[MAXN];

int getMax(int lx, int ly, int rx, int ry) {
	int lgx = lg[rx - lx + 1];
	int lgy = lg[ry - ly + 1];
	int ans = -1;
	ans = max(ans, r[lx][ly][lgx][lgy]);
	ans = max(ans, r[rx - (1 << lgx) + 1][ly][lgx][lgy]);
	ans = max(ans, r[lx][ry - (1 << lgy) + 1][lgx][lgy]);
	ans = max(ans, r[rx - (1 << lgx) + 1][ry - (1 << lgy) + 1][lgx][lgy]);
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	lg[0] = -1;
	for (int i = 1; i < MAXN; i++) lg[i] = lg[i >> 1] + 1;

	const int SUBMIT = 1;
	if (SUBMIT) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
	}
	else {
		n = m = 1000;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) a[i][j] = rand() % 2;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int R = min(m - j + 1, n - i + 1) + 1;
			int L = 0;
			while (R - L > 1) {
				int M = (L + R) / 2;
				if (sum(i, j, i + M - 1, j + M - 1) == M * M) L = M;
				else R = M;
			}
			mx[i][j] = L;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			r[i][j][0][0] = mx[i][j];
		}
	}

	for (int jj = 1; jj < MAXK; jj++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j + (1 << jj) <= m + 1) {
					r[i][j][0][jj] = max(r[i][j][0][jj - 1], r[i][j + (1 << (jj - 1))][0][jj - 1]);
				}
			}
		}
	}

	for (int ii = 1; ii < MAXK; ii++) {
		for (int jj = 0; jj < MAXK; jj++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (i + (1 << ii) <= n + 1 && j + (1 << jj) <= m + 1) {
						r[i][j][ii][jj] = max(r[i][j][ii - 1][jj], r[i + (1 << (ii - 1))][j][ii - 1][jj]);
					}
				}
			}
		}
	}

	//cerr << clock() / (double)CLOCKS_PER_SEC << endl;
	int q;
	if (SUBMIT) {
		scanf("%d", &q);
	}
	else {
		q = 1e6;
	}
	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;
		if (SUBMIT) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		}
		else {
			x1 = rand() % n + 1;
			x2 = rand() % n + 1;
			y1 = rand() % m + 1;
			y2 = rand() % m + 1;
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
		}
		int L = 0, R = min(x2 - x1 + 1, y2 - y1 + 1) + 1;
		while (R - L > 1) {
			int M = (L + R) / 2;
			if (getMax(x1, y1, x2 - M + 1, y2 - M + 1) >= M) L = M;
			else R = M;
		}
		if (SUBMIT) printf("%d\n", L);
	}

	//cerr << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}