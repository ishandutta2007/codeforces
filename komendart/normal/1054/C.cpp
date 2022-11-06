#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    vector<int> ans(n);
    for (int val = n; val > 0 && count(ans.begin(), ans.end(), 0) > 0; --val) {
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0 && l[i] == 0 && r[i] == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "NO\n";
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0 && l[i] == 0 && r[i] == 0) {
                ans[i] = val;
            }
        }
        for (int i = 0, d = 0; i < n; ++i) {
            if (ans[i] == val) {
                ++d;
            } else if (ans[i] == 0) {
                l[i] -= d;
            }
        }
        for (int i = n - 1, d = 0; i >= 0; --i) {
            if (ans[i] == val) {
                ++d;
            } else if (ans[i] == 0) {
                r[i] -= d;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}