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
        int c, m, x;
        cin >> c >> m >> x;
        int k = min(c, m);
        if (k * 3 <= c + m + x) {
            cout << k << endl;
        }
        else {
            cout << (c + m + x) / 3 << endl;
        }
    }
}