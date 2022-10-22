#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 205;

int r, g, b, R[MN], G[MN], B[MN], dp[MN][MN][MN];

int rec(int i, int j, int k) {
    int cnt = 0;
    if (i <= 0) cnt++;
    if (j <= 0) cnt++;
    if (k <= 0) cnt++;
    if (cnt > 1) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (i > 0 && j > 0) dp[i][j][k] = max(dp[i][j][k], rec(i - 1, j - 1, k) + R[i] * G[j]);
    if (i > 0 && k > 0) dp[i][j][k] = max(dp[i][j][k], rec(i - 1, j, k - 1) + R[i] * B[k]);
    if (j > 0 && k > 0) dp[i][j][k] = max(dp[i][j][k], rec(i, j - 1, k - 1) + G[j] * B[k]);
    return dp[i][j][k];
}

int32_t main() {
    boost();

    memset(dp, -1, sizeof(dp));
    cin >> r >> g >> b;
    for (int i = 1; i <= r; i++) cin >> R[i];
    for (int i = 1; i <= g; i++) cin >> G[i];
    for (int i = 1; i <= b; i++) cin >> B[i];
    sort(R + 1, R + r + 1);
    sort(G + 1, G + g + 1);
    sort(B + 1, B + b + 1);
    printf("%lld\n", rec(r, g, b));

    return 0;
}