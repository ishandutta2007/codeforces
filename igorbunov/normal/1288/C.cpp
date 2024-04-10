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
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

int MOD = 1000000007LL;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = 0;
            for (int l = 1; l <= j; l++) {
                dp[i][j] += 1LL * (j - l + 1) * dp[i - 1][l] % MOD;
                if (dp[i][j] >= MOD)
                    dp[i][j] -= MOD;
            }
        }
    }
    int ans = 0;
    for (int l = 1; l <= n; l++) {
        ans += 1LL * dp[m][l] * (n - l + 1) % MOD;
        if (ans >= MOD) {
            ans -= MOD;
        }
    }
    cout << ans;
}