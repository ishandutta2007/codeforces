#include <bits/stdc++.h>

using namespace std;

const int maxn = 16;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int> ans(maxn, -1);
    ans[0] = 0;
    for (int i = 1; i < maxn; ++i) {
        for (auto j: vector<int>{4, 6, 9}) {
            if (i >= j && ans[i - j] != -1) {
                ans[i] = max(ans[i], ans[i - j] + 1);
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int n;
        cin >> n;
        if (n < maxn) {
            cout << ans[n] << '\n';
        } else {
            int t = (n - maxn) / 4 + 1;
            cout << t + ans[n - 4 * t] << '\n';
        }
    }
}