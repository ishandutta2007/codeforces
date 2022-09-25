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

string s;
int m;
int dp[1001][21][10];
int p[1001][21][10];

void rec(int i, int j, int k) {
	if (i) {
		if (j > 10) rec(i - 1, j - k - 1, p[i][j][k]);
		else rec(i - 1, j + k + 1, p[i][j][k]);
	}
	if (i) cout << k + 1 << " \n"[i == m];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	while (cin >> s >> m) {
		memset(dp, 0, sizeof(dp));
		memset(p, -1, sizeof(p));

		dp[0][10][0] = 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 21; j++) {
				for (int k = 0; k < 10; k++) if (dp[i][j][k]) {
					for (int n = 0; n < 10; n++) if ((k != n || j == 10) && s[n] == '1') {
						if (j <= 10) {
							if (!(j + n + 1 > 10)) continue;
							dp[i + 1][j + n + 1][n] = 1;
							p[i + 1][j + n + 1][n] = k;
						}
						if (j > 10) {
							if (!(j - n - 1< 10)) continue;
							dp[i + 1][j - n - 1][n] = 1;
							p[i + 1][j - n - 1][n] = k;
						}
					}
				}
			}
		}

		bool ok = false;
		for (int j = 0; j < 21; j++) {
			for (int k = 0; k < 10; k++) {
				if (dp[m][j][k]) {
					cout << "YES" << endl;
					rec(m, j, k);
					ok = true;
				}
				if (ok) break;
			}
			if (ok) break;
		}
		if (!ok) cout << "NO" << endl;
	}

	return 0;
}