#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> v(e);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            int status = 1;
            if (x == 1) {
                status = 0;
            } else {
                for (int j = 2; j * j <= x; ++j) {
                    if (x % j == 0) {
                        status = 2;
                        break;
                    }
                }
            }
            v[i % e].push_back(status);
        }
        ll ans = 0;
        for (int i = 0; i < e; ++i) {
            if (v[i].empty()) {
                continue;
            }
            int a = -1;
            int b = -1;
            int L, R;
            for (int j = 0; j < v[i].size(); ++j) {
                if (v[i][j] == 2) {
                    a = j;
                    b = j;
                } else if (v[i][j] == 1) {
                    a = b;
                    b = j;
                    L = a + 1;
                    R = min(b, j - 1);
                    if (L <= R) {
                        ans += R - L + 1;
                    }
                } else {
                    L = a + 1;
                    R = min(b, j - 1);
                    if (L <= R) {
                        ans += R - L + 1;
                    }
                }
            }
        }
        cout << ans << '\n';

    }
    
}