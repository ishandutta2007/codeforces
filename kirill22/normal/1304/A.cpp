#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if ((b - a) % (c + d) == 0) {
            cout << (b - a) / (c + d) << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
}