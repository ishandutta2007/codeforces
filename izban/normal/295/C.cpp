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

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;


int n, k, a[64], m1, m2;
int dp[64][64][2];
int cnt[64][64][2];
int C[64][64];

void add(int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

void precalc() {
	C[0][0] = 1;
	for (int i = 0; i < 63 - 1; i++) {
		for (int j = 0; j <= i; j++) {
			add(C[i + 1][j], C[i][j]);
			add(C[i + 1][j + 1], C[i][j]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	precalc();

	while (cin >> n >> k) {
		m1 = m2 = 0;
		for (int i = 0; i < n; i++) cin >> a[i], m1 += a[i] == 50, m2 += a[i] == 100;
		memset(dp, 127, sizeof(dp));
		memset(cnt, 0, sizeof(cnt));
		dp[0][0][0] = 0;
		cnt[0][0][0] = 1;
		queue<pair<pair<int, int>, int> > q;
		q.push(make_pair(make_pair(0, 0), 0));
		while (!q.empty()) {
			int a = q.front().first.first, b = q.front().first.second, c = q.front().second;
			q.pop();
			int alla = c? a : m1 - a, allb = c? b : m2 - b;
			for (int i = 0; i <= alla; i++) {
				for (int j = 0; j <= allb; j++) if (i + j && 50 * i + 100 * j <= k) {
					int na = a + (c? -1 : 1) * i, nb = b + (c? -1 : 1) * j, nc = c ^ 1;
					if (dp[na][nb][nc] > dp[a][b][c] + 1) {
						dp[na][nb][nc] = dp[a][b][c] + 1;
						q.push(make_pair(make_pair(na, nb), nc));
					}
					if (dp[na][nb][nc] == dp[a][b][c] + 1) {
						add(cnt[na][nb][nc], 1LL * C[alla][i] * C[allb][j] % mod * cnt[a][b][c] % mod);
					}
				}
			}
		}
		if (dp[m1][m2][1] >= inf) dp[m1][m2][1] = -1;
		cout << dp[m1][m2][1] << endl << cnt[m1][m2][1] << endl;
	}

	return 0;
}