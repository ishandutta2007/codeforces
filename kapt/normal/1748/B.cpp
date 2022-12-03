#include <bits/stdc++.h>
using namespace std;

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> cnt(10, 0);
            int mx = 0, c = 0;
            for (int j = i; j < n; ++j) {
                int id = s[j] - '0';
                if (cnt[id] == 0) {
                    c++;
                }
                cnt[id]++;
                mx = max(mx, cnt[id]);
                if (mx <= c) ans++;
                if (mx > 10) break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}