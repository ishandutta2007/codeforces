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
        int a, b;
        cin >> a >> b;
        b = b * b;
        if (a >= b && (a - b) % 2 == 0) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}