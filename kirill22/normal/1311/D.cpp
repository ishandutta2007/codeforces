#include<bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        int res = 1e9, _a = -1, _b = -1, _c = -1;
        for (int a2 = 1; a2 <= 100000; a2++) {
            for (int b2 = a2; b2 <= 100000; b2 += a2) {
                for (int c2 = b2; c2 <= 200000; c2 += b2) {
                    int _res = abs(a - a2) + abs(b - b2) + abs(c - c2);
                    if (res > _res) {
                        res = _res;
                        _a = a2;
                        _b = b2;
                        _c = c2;
                    }
                }
            }
        }
        cout << res << endl << _a << " " << _b << " " << _c << endl;
    }
}