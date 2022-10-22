#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool f = true;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) f = false;
        }
        if (f) {
            cout << 1 << endl;
            for (int i = 0; i < n; i++) {
                cout << 1 << " ";
            }
            cout << endl;
            continue;
        }
        int j = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == a[(i + 1) % n]) {
                j = i;
            }
        }
        if (j == -1) {
            vector<int> ans(n, -1);
            ans[0] = 1;
            for (int i = 1; i < n; i++) {
                if (ans[i - 1] == 1) ans[i] = 2;
                else ans[i] = 1;
            }
            int res = 2;
            if (ans[0] == ans[n - 1]) {
                ans[0] = 3;
                res = 3;
            }
            cout << res << endl;
            for (auto el : ans) cout << el << " ";
            cout << endl;
            continue;
        }
        vector<int> ans(n);
        cout << 2 << endl;
        ans[j] = 1;
        for (int i = 1; i < n; i++) {
            if (ans[(j - i + 1 + n) % n] == 1) ans[(j - i + n) % n] = 2;
            else ans[(j - i + n) % n] = 1;
        }
        for (auto el : ans) cout << el << " ";
        cout << endl;
    }
}