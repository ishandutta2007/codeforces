#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 3e5 + 1;
const long long inf = 4e18 + 1;

int top;
int a[N], c[N];
int dp[5002][5002];

int f(int l, int r) {
    if (dp[l][r] == -1) {
        if (l > 1 && r < top && c[l - 1] == c[r + 1])
            dp[l][r] = f(l - 1, r + 1) + 1;
        else {
            dp[l][r] = 1e9;
            if (l > 1)
                dp[l][r] = min(dp[l][r], f(l - 1, r) + 1);
            if (r < top)
                dp[l][r] = min(dp[l][r], f(l, r + 1) + 1);
        }
    }
    return dp[l][r];
}

int main() {
    int i, j, m, k, n;
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    i = 1;
    while (i <= n) {
        ++top;
        c[top] = a[i];
        while (i <= n && a[i + 1] == a[i])
            ++i;
        ++i;
    }
    for (i = 1; i <= top; ++i)
    for (j = 1; j <= top; ++j)
        dp[i][j] = -1, dp[i][j] = -1;
    dp[1][top] = 0;
    dp[1][top] = 0;
    int ans = 1e9;
    for (i = 1; i <= top; ++i)
        ans = min(ans, f(i, i));
    cout << ans;
}