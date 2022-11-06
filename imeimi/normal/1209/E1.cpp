#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <string>
#include <cstring>
#include <functional>
#define fs first
#define se second

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, m;
int A[13][2001];
int dp[1 << 12];
int tp[1 << 12];
int mx[1 << 12];

int solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        cin >> A[i][j];
    }
    for (int i = 0; i < (1 << n); ++i) dp[i] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < (1 << n); ++j) mx[j] = dp[j];
        for (int s = 0; s < n; ++s) {
            for (int j = 0; j < (1 << n); ++j) tp[j] = dp[j];
            for (int j = 1; j <= n; ++j) {
                for (int k = 0; k < (1 << n); ++k) {
                    if ((k >> (j + s) % n) & 1) continue;
                    int nxt = k | (1 << (j + s) % n);
                    tp[nxt] = max(tp[nxt], tp[k] + A[j][i]);
                }
            }
            for (int j = 0; j < (1 << n); ++j) mx[j] = max(mx[j], tp[j]);
        }
        for (int j = 0; j < (1 << n); ++j) dp[j] = mx[j];
    }
    return dp[(1 << n) - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}