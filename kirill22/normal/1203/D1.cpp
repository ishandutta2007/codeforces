#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int x = 0;
            for (int i = 0; i < n; i++) {
                if (i < l || i > r) {
                    if (x < m && s[i] == t[x]) {
                        x++;
                    }
                }
            }
            if (x == m) {
                ans = max(ans, r - l + 1);
            }
        }
    }
    cout << ans;
}