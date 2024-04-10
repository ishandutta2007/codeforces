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

const int maxn = 10010;
const int inf = 1000000007;
const int mod = 1000000007;

int a[maxn];
int dp[2 * maxn][2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            dp[maxn][0]++;
            if (dp[maxn][0] == mod) dp[maxn][0] -= mod;
            for (int j = 0; j < 2 * maxn; j++) if (dp[j][0]) {
                dp[j + a[i]][1] += dp[j][0]; if (dp[j + a[i]][1] >= mod) dp[j + a[i]][1] -= mod;
                dp[j - a[i]][1] += dp[j][0]; if (dp[j - a[i]][1] >= mod) dp[j - a[i]][1] -= mod;
            }
            for (int j = 0; j < 2 * maxn; j++) {
                dp[j][0] = dp[j][1];
                dp[j][1] = 0;
            }
            ans += dp[maxn][0];
            if (ans >= mod) ans -= mod;
        }
        cout << ans << endl;
    }

    return 0;
}