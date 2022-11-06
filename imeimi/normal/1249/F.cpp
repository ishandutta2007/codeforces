#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

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

int n, k;
int A[201];
vector<int> edge[201];
int dp[201][201];
int sum[201][201];
int mx[201][201];

void dfs(int x, int p) {
    for (int i : edge[x]) {
        if (i == p) continue;
        dfs(i, x);
    }
    for (int j = 1; j <= k; ++j) for (int l = j; l <= k; ++l)
        sum[j][l] = 0, mx[j][l] = 0;
    dp[x][0] = A[x];
    for (int i : edge[x]) {
        if (i == p) continue;
        dp[x][0] += dp[i][k];
        for (int j = 1; j <= k; ++j) {
            for (int l = j; l <= k; ++l) {
                int s = max(max(k + 2 >> 1, k - l + 1), j);
                sum[j][l] += dp[i][s - 1];
                mx[j][l] = max(mx[j][l], dp[i][l - 1] - dp[i][s - 1]);
            }
        }
    }
    for (int j = 1; j <= k; ++j) for (int l = j; l <= k; ++l) {
        dp[x][j] = max(dp[x][j], sum[j][l] + mx[j][l]);
    }
    for (int j = k; j > 0; --j) {
        dp[x][j - 1] = max(dp[x][j - 1], dp[x][j]);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans = max(ans, dp[1][i]);
    }
    printf("%d\n", ans);
    return 0;
}