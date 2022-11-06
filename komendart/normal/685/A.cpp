#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a = 0, b = 0;
    for (int i = 1; i <= n - 1; i *= 7) a++;
    for (int i = 1; i <= m - 1; i *= 7) b++;
    a = max(a, 1); b = max(b, 1);

    int ans = 0;
    for (int mask = 0; mask < (1 << 7); mask++) {
        vector<int> v;
        for (int i = 0; i < 7; i++) {
            if (mask & (1 << i)) v.push_back(i);
        }
        if (v.size() != a + b) continue;
        do {
            int x = 0;
            for (int i = 0; i < a; i++) {
                x = x * 7 + v[i];
            }
            int y = 0;
            for (int i = a; i < v.size(); i++) {
                y = y * 7 + v[i];
            }
            if (x < n && y < m) ans++;
        } while (next_permutation(v.begin(), v.end()));
    }

    cout << ans << endl;
}