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
using namespace std;
  
#define int long long
#define endl '\n'
typedef long double ld;

const int MAXN = 33;
const int MAXK = 53;
const int INF = 1e14 + 239;

int dp[MAXN][MAXN][MAXK];

int calc(int n, int m, int k) {
	if (dp[n][m][k] == -1) {
		dp[n][m][k] = INF;
		for (int i = 1; i < n; i++) {
			for (int nk = 0; nk <= k; nk++) {
				dp[n][m][k] = min(dp[n][m][k], calc(i, m, nk) + calc(n - i, m, k - nk) + m * m);			
			}
		}
		for (int i = 1; i < m; i++) {
			for (int nk = 0; nk <= k; nk++) {
				dp[n][m][k] = min(dp[n][m][k], calc(n, i, nk) + calc(n, m - i, k - nk) + n * n);
			}
		}
		//assert(dp[n][m][k] <= INF);
	}
	return dp[n][m][k];
}

void init() {
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			for (int k = 0; k < MAXK; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			dp[i][j][0] = 0;
			if (i * j < MAXK) {
				dp[i][j][i * j] = 0;
			}
		}    
	}
}

int32_t main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();

    int q;
    cin >> q;
    while (q--) {
    	int n, m, k;
    	cin >> n >> m >> k;
    	cout << calc(n, m, k) << '\n';
    }
}