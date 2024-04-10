#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <random>
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

#define int long long
using namespace std;

const int MOD = 1000000007;
const int obr = 500000004;


int dp[3000][3000];
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == j) {
				dp[i][j] = (i * k) % MOD;
				continue;
			}
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) * obr;
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][m] << endl;
}

signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
    	solve();
    }
}