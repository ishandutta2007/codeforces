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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> b;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (b.find(a[i]) == b.end()) {
                b[a[i]] = i;
                continue;
            }
            if (ans == -1) {
                ans = i - b[a[i]] + 1;
            }
            else {
                ans = min(ans, i - b[a[i]] + 1);
            }
            b[a[i]] = i;
        }
        cout << ans << endl;
    }
}