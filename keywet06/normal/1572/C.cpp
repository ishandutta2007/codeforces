#include <bits/stdc++.h>

using namespace std;

const int N = 3005;

int c[N];
int dp[N][N];

vector<int> occ[N];

int solve(int l, int r) {
    if (l >= r) {
        return l == r;
    }
    int &best = dp[l][r];
    if (~best) {
        return best;
    }
    best = solve(l + 1, r) + 1;
    for (int i : occ[c[l]]) {
        if (i > l && i <= r) {
            best = min(best, solve(l + 1, i - 1) + solve(i, r));
        }
    }
    return best;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        occ[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        occ[c[i]].push_back(i);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j] = -1;
        }
    }
    cout << solve(0, n - 1) - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}