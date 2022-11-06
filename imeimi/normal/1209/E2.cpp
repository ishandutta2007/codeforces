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

const int N = 2005;
const int inf = 1e5;
int n, m;
int A[2001][13];
int dp[1 << 12];

int rotate(int x, int b) {
    return (x >> 1) | ((x & 1) << b - 1);
}

vector<int> rot[1 << 12];
int solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
        cin >> A[j][i];
        A[j][i] = inf - A[j][i];
    }
    vector<pii> sr;
    for (int i = 1; i <= m; ++i) {
        int mn = inf;
        for (int j = 1; j <= n; ++j) {
            mn = min(mn, A[i][j]);
        }
        sr.emplace_back(pii(mn, i));
    }
    sort(sr.begin(), sr.end());
    for (int i = 0; i < (1 << n); ++i) {
        dp[i] = inf * N;
        rot[i].clear();
        rot[i].push_back(i);
        for (int j = rotate(i, n); j != i; j = rotate(j, n)) {
            if (j < i) {
                rot[i].clear();
                break;
            }
            rot[i].push_back(j);
        }
    }
    dp[0] = 0;
    for (int it = 0; it < min(m, n + 5); ++it) {
        for (int j = 0; j < (1 << n); ++j) {
            for (int i = 1; i <= n; ++i) {
                dp[j | (1 << i - 1)] = min(dp[j | (1 << i - 1)], dp[j] + A[sr[it].se][i]);
            }
        }
        for (int i = 0; i < (1 << n); ++i) {
            int mn = inf * N;
            for (int j : rot[i]) mn = min(mn, dp[j]);
            for (int j : rot[i]) dp[j] = mn;
        }
    }
    return inf * n - dp[(1 << n) - 1];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) printf("%d\n", solve());
    return 0;
}