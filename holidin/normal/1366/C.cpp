#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 12;
const int inf = 2e9;
const int mod = 1e9 + 7;

int cnt[2][N];
void run() {
    int n, x, m;
    cin >> n >> m;
    for (int i = 0; i <= n + m; ++i)
        cnt[0][i] = cnt[1][i] = 0;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
        cin >> x;
        if (i + j < (n + m) / 2)
            ++cnt[x][i + j];
        else
            ++cnt[x][n + m - i - j - 2];
    }
    int ans = 0;
    for (int i = 0; i < n + m; ++i)
    if (2 * (i + 1) != n + m) {
        ans += min(cnt[0][i], cnt[1][i]);
    }
    cout << ans << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--)
        run();
}