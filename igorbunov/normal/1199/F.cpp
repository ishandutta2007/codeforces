#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

int dp[50][50][50][50];

signed main() {
	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			arr[i][j] = (c == '#');
		}
	}

	vector<vector<int>> pref(n, vector<int>(n));


	for (int a = 0; a < 50; a++) {
		for (int b = 0; b < 50; b++) {
			for (int c = 0; c < 50; c++) {
				for (int d = 0; d < 50; d++) {
					dp[a][b][c][d] = 1000000000;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pref[i][j] = arr[i][j];

			if (i > 0) {
				pref[i][j] += pref[i - 1][j];
			}

			if (j > 0) {
				pref[i][j] += pref[i][j - 1];
			}

			if (i * j > 0) {
				pref[i][j] -= pref[i - 1][j - 1];
			}
		}
	}

	for (int x1 = n - 1; x1 >= 0; x1--) {
        for (int y1 = n - 1; y1 >= 0; y1--) {
            for (int x2 = x1; x2 < n; x2++) {
                for (int y2 = y1; y2 < n; y2++) {

                	int now = pref[x2][y2];

                	if (x1 > 0) {
                		now -= pref[x1 - 1][y2];
                	}

                	if (y1 > 0) {
                		now -= pref[x2][y1 - 1];
                	}

                	if (x1 * y1 > 0) {
                		now += pref[x1 - 1][y1 - 1];
                	}

                    if (now == 0) {
                        dp[x1][y1][x2][y2] = 0;
                        continue;
                    }

                    if (y2 - y1 + 1 == x2 - x1 + 1) {
                        dp[x1][y1][x2][y2] = y2 - y1 + 1;
                    }

                    for (int k = x1; k < x2; k++) {
                        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dp[x1][y1][k][y2] + dp[k + 1][y1][x2][y2]);
                    }

                    for (int k = y1; k < y2; k++) {
                        dp[x1][y1][x2][y2] = min(dp[x1][y1][x2][y2], dp[x1][k + 1][x2][y2] + dp[x1][y1][x2][k]);
                    }
                }
            }
        }
    }

    cout << dp[0][0][n - 1][n - 1];
}