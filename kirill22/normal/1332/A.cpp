#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, z;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        vector<int> x(3), y(3);
        cin >> a >> b >> c >> d;
        swap(c, d);
        for (int i = 0; i < 3; i++) {
            cin >> x[i] >> y[i];
        }
        bool f = true;
        if (x[1] <= x[0] + b - a && x[0] + b - a <= x[2]) {
            z++;
        }
        else f = false;
        if (y[1] <= y[0] + c - d && y[0] + c - d <= y[2]) {
            z++;
        }
        else f = false;
        if (x[1] == x[2] && a + b > 0) f = false;
        if (y[1] == y[2] && c + d > 0) f = false;
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}