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

using ll = long long;

const int maxn = 21;

int n;
ll a[maxn];

void read() {
    int len;
    cin >> len;
    for (int i = 0; i < len; ++i) {
        ll x;
        cin >> x;
        if (x != 0) {
            a[n++] = x;
        }
    }
}

ll sum[1 << maxn];
int dp[1 << maxn];
bool can[1 << maxn];

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    read();
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum[mask] = sum[mask ^ (1 << i)] + a[i];
                break;
            }
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        int len = __builtin_popcount(mask);
        if (len <= 1) {
            can[mask] = true;
            continue;
        }
        if ((sum[mask] + len - 1) % 2 != 0) {
            can[mask] = false;
            continue;
        }
        int itermask = mask & (mask - 1); // faster
        for (int submask = itermask; submask > 0; submask = (submask - 1) & itermask) {
            if (abs(sum[submask] - sum[mask ^ submask]) < len) {
                can[mask] = true;
                break;
            }
        }
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (can[mask]) {
            int len = __builtin_popcount(mask);
            if (len <= 1) dp[mask] = len;
            else dp[mask] = len - 1;
        } else {
            dp[mask] = 100500;
        }
        int itermask = mask & (mask - 1);
        for (int submask = itermask; submask > 0; submask = (submask - 1) & itermask) {
            dp[mask] = min(dp[mask], dp[submask] + dp[mask ^ submask]);
        }
    }
    //for (int mask = 0; mask < (1 << n); ++mask) {
    //    cout << bitset<3>(mask) << ' ' << can[mask] << ' ' << dp[mask] << endl;
    //}
    cout << dp[(1 << n) - 1] << '\n';
}