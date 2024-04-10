#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
int cnt[3][3][MAXN];

main() {
    int n, q;
    string s;
    cin >> n >> q >> s;
    for (int i = 0; i < n; ++i) {
        for (int t = 0; t < 3; ++t) {
            cnt[i % 3][t][i / 3 + 1] = cnt[i % 3][t][i / 3];
        }
        cnt[i % 3][s[i] - 'a'][i / 3 + 1]++;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int res = 1e9;
        for (int t = 0; t < 3; ++t) {
            for (int p = 0; p < 3; ++p) {
                if (p == t) continue;
                int ans = r - l + 1;
                ans -= cnt[0][t][r / 3 + 1] - cnt[0][t][(l + 2) / 3];
                /// cout << ans << " ";
                ans -= cnt[1][p][(r + 2) / 3] - cnt[1][p][(l + 1) / 3];
                /// cout << ans << " ";
                ans -= cnt[2][3 - t - p][(r + 1) / 3] - cnt[2][3 - t - p][l / 3];
                /// cout << ans << " ";
                res = min(res, ans);
            }
        }
        cout << res << "\n";
    }
    return 0;
}