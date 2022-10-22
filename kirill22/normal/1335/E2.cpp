#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n, ans = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) a[i]--;
        unordered_map<int, int> cnt;
        vector<vector<int>> g(200);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
            g[a[i]].push_back(i);
        }
        for (auto el : cnt) ans = max(ans, el.second);
        for (int k = 0; k < 200; k++) {
            int s = g[k].size();
            int l = 0, r = s - 1;
            while (l < r) {
                int _l = g[k][l] + 1;
                int _r = g[k][r] - 1;
                int x = 2 * (l + 1);
                int ans2 = 0;
                for (int j = 0; j < 200 && _l <= _r; j++) {
                    if (g[j].size() == 0) continue;
                    auto it = lower_bound(g[j].begin(), g[j].end(), _l);
                    auto it2 = upper_bound(g[j].begin(), g[j].end(), _r);
                    ans2 = max(ans2, (int) (it2 - it));
                }
                ans = max(ans, x + ans2);
                l++;
                r--;
            }
        }
        cout << ans << '\n';
    }
}