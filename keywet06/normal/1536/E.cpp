#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        int ans = 1;
        bool has = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '0') {
                    has = true;
                } else {
                    ans = (2LL * ans) % mod;
                }
            }
        }
        if (has) {
            cout << ans << '\n';
        } else {
            cout << (ans - 1) << '\n';
        }
    }
    return 0;
}