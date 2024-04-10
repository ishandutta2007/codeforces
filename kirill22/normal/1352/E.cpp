#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q; cin >> q; while (q--) {
        int n;
        cin >> n;
        vector<int> a(n), pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pref[i + 1] = pref[i] + a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = 0;
            for (int j = 0; j <= n; j++) {
                while (l <= n && pref[l] - pref[j] < a[i]) l++;
                if (l != n + 1 && l != j + 1 && pref[l] - pref[j] == a[i]) {
                    ans++;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}