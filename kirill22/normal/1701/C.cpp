#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(n);
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            x--;
            cnt[x]++;
        }
        int l = 0, r = 2 * m + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int need = 0;
            for (int i = 0; i < n; i++) {
                int z = min(m, cnt[i]);
                need += cnt[i] - z;
                need -= (m - z) / 2;
            }
            if (need <= 0) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r << '\n';
    }
}