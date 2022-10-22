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
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        if (d < e) {
            swap(d, e);
            swap(b, c);
        }
        int k = min(a / 2, b);
        cout << k * d + min(c, (a - k * 2) / 2) * e << endl;
    }
}