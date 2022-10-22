#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int r, b, k;
        cin >> r >> b >> k;
        int z = __gcd(r, b);
        r /= z;
        b /= z;
        if (r > b) swap(r, b);
        b--;
        int x = (b + r - 1) / r;
        if (x >= k) {
            cout << "REBEL" << endl;
            continue;
        }
        cout << "OBEY" << endl;
    }
}