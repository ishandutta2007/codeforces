#include <bits/stdc++.h>

using namespace std;

signed main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> r(n);
    vector<int> c(m);
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int x; cin >> x;
                r[i] ^= x;
                c[j] ^= x;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (r[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (c[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}