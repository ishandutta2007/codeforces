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
#define y1 _dfdfdfd


const int maxn = 1 << 7;
const int maxm = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int dp[maxn][2 * maxm];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        
        memset(dp, -1, sizeof(dp));
        dp[0][maxm] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2 * maxm; j++) if (dp[i][j] != -1) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[i + 1][j + a[i] - k * b[i]] = max(dp[i + 1][j + a[i] - k * b[i]], dp[i][j] + a[i]);
            }
        }
        int ans = dp[n][maxm];
        if (!ans) ans = -1;
        cout << ans << endl;
    }
    
	return 0;
}