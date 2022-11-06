#include <iostream>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 105;

int dp[maxn][maxn][maxn][2];
int a[maxn];

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            for (int k = 0; k < maxn; ++k) {
                dp[i][j][k][0] = dp[i][j][k][1] = maxn;
            }
        }
    }
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] != 0) {
            a[i] %= 2;
        } else {
            a[i] = -1;
        }
    }
    dp[0][0][0][0] = 0;
    dp[0][0][0][1] = 0;
    for (int k = 0; k < n; ++k) {
        vector<int> vec;
        if (a[k] != 1) vec.push_back(0);
        if (a[k] != 0) vec.push_back(1);
        for (int odd = 0; odd <= k; ++odd) {
            for (int even = 0; even <= k; ++even) {
                for (int prev = 0; prev <= 1; ++prev) {
                    for (auto next: vec) {
                        int add = (prev == next) ? 0: 1;
                        int nodd = (next == 0) ? odd: odd + 1;
                        int neven = (next == 1) ? even: even + 1;
                        dp[k + 1][nodd][neven][next] = min(
                            dp[k + 1][nodd][neven][next],
                            dp[k][odd][even][prev] + add
                        );
                    }
                }
            }
        }
    }
    cout << min(
        dp[n][(n + 1) / 2][n / 2][0],
        dp[n][(n + 1) / 2][n / 2][1]
    );
    
}