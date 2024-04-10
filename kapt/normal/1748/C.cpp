#include <bits/stdc++.h>
using namespace std;
#define int int64_t

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        unordered_map<int, int> cnt;
        int mx = 0, p = 0;
        int dlt = 0;
        int ans = 0;
        bool f = false;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            if (a != 0) {
                p += a;
                cnt[p]++;
                if (cnt[p] > mx) {
                    mx = cnt[p];
                    dlt = p;
                }
            } else {
                if (!f) {
                    ans += cnt[0];
                    f = true;
                } else {
                    ans += mx;
                    p -= dlt;
                }
                cnt.clear();
                cnt[p]++;
                mx = 1;
                dlt = p;
            }
        }
        if (!f) {
            ans += cnt[0];
        } else {
            ans += mx;
        }
        cout << ans << endl;
    }
    return 0;
}