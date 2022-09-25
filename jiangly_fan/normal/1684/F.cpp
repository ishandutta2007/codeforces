#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1), fR(n + 1), fL(n + 2, n + 1);
        map<int, vector<int>> mp;
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            mp[a[i]].push_back(i);
        }
        for (int j = 0, l, r; j < m; j += 1) {
            cin >> l >> r;
            fR[l] = max(fR[l], r);
            fL[r] = min(fL[r], l);
        }
        for (int i = 1; i <= n; i += 1)
            if (fR[i - 1] >= i)
                fR[i] = max(fR[i], fR[i - 1]);
        for (int i = n; i >= 1; i -= 1)
            if (fL[i + 1] <= i)
                fL[i] = min(fL[i], fL[i + 1]);
        vector<pair<int, int>> vp;
        for (auto& [x, p] : mp) {
            for (int i : p) {
                if (fL[i] <= n) {
                    auto it = ranges::lower_bound(p, fL[i]);
                    if (*it != i) vp.emplace_back(*it, i);
                }
                if (fR[i]) {
                    auto it = prev(ranges::upper_bound(p, fR[i]));
                    if (*it != i) vp.emplace_back(i, *it);
                }
            }
        }
        if (vp.empty()) cout << "0\n";
        else {
            int R = n, ans = n;
            vector<vector<int>> v(n + 1);
            for (auto [x, y] : vp) {;
                R = min(R, y);
                v[1].push_back(x);
                v[x + 1].push_back(-x);
                v[x + 1].push_back(y);
            }
            multiset<int> ms;
            for (int i = 1; i <= R; i += 1) {
                for (int x : v[i])
                    if (x > 0) ms.insert(x);
                    else ms.erase(ms.find(-x));
                ans = min(ans, *ms.rbegin() - i + 1);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}