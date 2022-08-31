#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL work(int n, int m) {
    LL dp[2][2][2] = {};
    int c = 0;
    dp[c][0][0] = 1;
    for (int i = 30; i >= 0; --i) {
        c ^= 1;
        dp[c][0][0] = dp[c][0][1] = dp[c][1][0] = dp[c][1][1] = 0;
        for (int ln = 0; ln <= 1; ++ln)
            for (int lm = 0; lm <= 1; ++lm)
                for (int x = 0; x <= 1; ++x)
                    for (int y = 0; x + y <= 1; ++y)
                        if ((ln || x <= (n >> i & 1)) && (lm || y <= (m >> i & 1)))
                            dp[c][ln | (x < (n >> i & 1))][lm | (y < (m >> i & 1))] += dp[c ^ 1][ln][lm];
    }
    return dp[c][1][1];
}
void solve() {
    int l, r;
    cin >> l >> r;
    cout << work(r + 1, r + 1) - 2 * work(l, r + 1) + work(l, l) << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}