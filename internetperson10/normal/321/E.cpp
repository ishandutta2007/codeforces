#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

char c[4001][4001];
int dp[801][4001];
int ans[801][4001];
int pref[4001][4001];

int u;

void solve(int l, int r, int lx, int rx) {
    int x = (l + r) >> 1;
    int best = 1000000007;
    for(int i = max(lx, ans[u-1][x]); i < min(x, rx); i++) {
        int cost = pref[x][x] - (pref[x][i] << 1) + pref[i][i] + dp[u-1][i];
        if(cost < best) {
            ans[u][x] = i;
            best = cost;
        }
    }
    dp[u][x] = best;
    if(l != x) solve(l, x, lx, ans[u][x] + 1);
    if(x+1 != r) solve(x+1, r, ans[u][x], rx);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] = (c[i][j] - '0') + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }
    dp[1][0] = 0;
    for(int i = 1; i <= n; i++) {
        dp[1][i] = pref[i][i];
    }
    for(int i = 2; i <= k; i++) {
        u = i;
        solve(1, n+1, 0, n);
    }
    cout << dp[k][n] / 2 << '\n';
}