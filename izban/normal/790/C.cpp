#include <unordered_map>
#include <unordered_set>
#include <functional>
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

const int MAXK = -1;
const int MAXN = 80;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

int dp[MAXN][MAXN][MAXN][3];

void upd(int &a, int b) {
	a = min(a, b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int nn;
	string s;
	while (cin >> nn >> s) {
		vector<int> a(nn, -1);
		for (int i = 0; i < nn; i++) {
			if (s[i] == 'V') a[i] = 0;
			else if (s[i] == 'K') a[i] = 1;
			else a[i] = 2;
		}
		if (0) {
			nn = 75;
			a.resize(nn);
			for (int i = 0; i < nn; i++) a[i] = rand() % 3;
		}
		vector<vector<int> > pos(3);
		for (int i = 0; i < nn; i++) pos[a[i]].push_back(i);

		vector<int> n(3);
		for (int i = 0; i < 3; i++) n[i] = pos[i].size();

		vector<vector<vector<int> > > beh(3);
		for (int i = 0; i < 3; i++) {
			beh[i].assign(n[i] + 1, vector<int>(nn));
			for (int j = 0; j <= n[i]; j++) {
				for (int k = 0; k < nn; k++) {
					for (int l = 0; l < j; l++) beh[i][j][k] += pos[i][l] < k;
				}
			}
		}

		memset(dp, 63, sizeof(dp));
		dp[0][0][0][2] = 0;
		vector<int> i(3);
		for (int ssum = 0; ssum < nn; ssum++) {
			for (i[0] = 0; i[0] <= n[0] && i[0] <= ssum; i[0]++) {
				for (i[1] = 0; i[1] <= n[1] && i[0] + i[1] <= ssum; i[1]++) {
					//for (i[2] = 0; i[2] <= n[2] && i[0] + i[1] + i[2] <= ssum; i[2]++) {
					i[2] = ssum - i[0] - i[1]; if (i[2] >= 0 && i[2] <= n[2]) {
						int sum = 0;
						for (int j = 0; j < 3; j++) sum += i[j];
						for (int j = 0; j < 3; j++) if (i[j] < n[j]) {
							vector<int> ni = i;
							ni[j]++;
							int cost = sum;
							for (int l = 0; l < 3; l++) cost -= beh[l][i[l]][pos[j][i[j]]];
							for (int last = 0; last < 3; last++) if (dp[i[0]][i[1]][i[2]][last] < 1e9) {
								if (last != 0 || j != 1) {
									int ndp = dp[i[0]][i[1]][i[2]][last] + cost;
									upd(dp[ni[0]][ni[1]][ni[2]][j], ndp);
								}
							}
						}
					}
				}
			}
		}
		int ans = 1e9;
		for (int i = 0; i < 3; i++) upd(ans, dp[n[0]][n[1]][n[2]][i]);
		printf("%d\n", ans);
	}

	return 0;
}