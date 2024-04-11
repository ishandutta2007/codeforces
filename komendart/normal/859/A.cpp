#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int k;
    cin >> k;
    int ma = 0;
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        ma = max(ma, x);
    }
    cout << max(0, ma - 25) << '\n';
}