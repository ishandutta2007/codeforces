#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int m;
        cin >> m;
        vector<int> u(m), d(m);
        for (int i = 0; i < m; ++i) {
            cin >> u[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> d[i];
        }
        vector<int> suf(m + 1), pref(m + 1);
        pref[0] = 0;
        for (int i = 1; i <= m; ++i) {
            pref[i] = pref[i - 1] + d[i - 1];
        }
        suf[m] = 0;
        for (int i = m - 1; i >= 0; --i) {
            suf[i] = suf[i + 1] + u[i];
        }
        int ans = 2e9 + 100;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, max(pref[i], suf[i + 1]));
        }
        cout << ans << "\n";
    }
    return 0;
}