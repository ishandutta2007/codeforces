#include <bits/stdc++.h>

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
        vector<int> a(4 * n);
        for (int i = 0; i < 4 * n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        bool f = true;
        int ans = a[0] * a[4 * n - 1];
        for (int i = 0; i < 2 * n; i += 2) {
            if (a[i] != a[i + 1] || a[4 * n - i - 1] != a[4 * n - i - 2] || a[4 * n - i - 1] * a[i] != ans) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}