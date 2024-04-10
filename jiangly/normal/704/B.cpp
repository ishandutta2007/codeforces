#include <bits/stdc++.h>
using namespace std;
template<typename T>
void cmin(T &x, T y) {
    if (y < x)
        x = y;
}
using LL = long long;
constexpr LL INF = 1E18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, e;
    cin >> n >> s >> e;
    --s;
    --e;
    vector<int> x(n), a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i)
        cin >> d[i];
    vector<vector<LL>> dp(2);
    for (int i = 0; i < 2; ++i)
        dp[i].assign(n, INF);
    dp[0][0] = 0;
    int cur = 0, pre = 1, delta = 0;
    for (int i = 0; i < n; ++i) {
        swap(cur, pre);
        dp[cur].assign(n, INF);
        int dis = i == 0 ? 0 : x[i] - x[i - 1];
        for (int j = 0; j < n; ++j) {
            if (dp[pre][j] == INF)
                continue;
            int k = j + delta;
            if (i != 0 && j == 0 && k == 0)
                continue;
            LL cost = dp[pre][j] + 1LL * (j + k) * dis;
            if (i == s) {
                if (k > 0)
                    cmin(dp[cur][j], cost + c[i]);
                cmin(dp[cur][j + 1], cost + d[i]);
            } else if (i == e) {
                if (j > 0)
                    cmin(dp[cur][j - 1], cost + a[i]);
                cmin(dp[cur][j], cost + b[i]);
            } else {
                if (j > 0 && k > 0)
                    cmin(dp[cur][j - 1], cost + a[i] + c[i]);
                if (j > 0)
                    cmin(dp[cur][j], cost + a[i] + d[i]);
                if (k > 0)
                    cmin(dp[cur][j], cost + b[i] + c[i]);
                cmin(dp[cur][j + 1], cost + b[i] + d[i]);
            }
        }
        if (i == s)
            --delta;
        if (i == e)
            ++delta;
    }
    cout << dp[cur][0] << endl;
    return 0;
}