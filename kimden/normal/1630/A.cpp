#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<pii> ans;
        if (k == 0) {
            for (int i = 0; i < n; ++i) {
                if (i < (i ^ (n - 1))) {
                    ans.emplace_back(i, (i ^ (n - 1)));
                }
            }
            for (int i = 0; i < n / 2; ++i) {
                cout << ans[i].first << " " << ans[i].second << "\n";
            }
        } else if (k < n - 1) {
            for (int i = 0; i < n; ++i) {
                if (i == 0 || i == n - 1 || i == k || i == n - 1 - k)
                    continue;
                if (i < (i ^ (n - 1))) {
                    ans.emplace_back(i, (i ^ (n - 1)));
                }
            }
            ans.emplace_back(k, n - 1);
            ans.emplace_back(0, n - 1 - k);
            for (int i = 0; i < n / 2; ++i) {
                cout << ans[i].first << " " << ans[i].second << "\n";
            }
        } else {
            if (n == 4) {
                cout << -1 << "\n";
            } else {
                int a = 1;
                int b = 3;
                for (int i = 0; i < n; ++i) {
                    if (i == 0 || i == 1 || i == 3 ||
                        n - 1 - i == 0 || n - 1 - i == 1 || n - 1 - i == 3)
                        continue;
                    if (i < (i ^ (n - 1))) {
                        ans.emplace_back(i, (i ^ (n - 1)));
                    }
                }
                ans.emplace_back(0, n - 1 - 3);
                ans.emplace_back(1, 3);
                ans.emplace_back(n - 1, n - 1 - 1);
                for (int i = 0; i < n / 2; ++i) {
                    cout << ans[i].first << " " << ans[i].second << "\n";
                }
            }
        }
    }

}