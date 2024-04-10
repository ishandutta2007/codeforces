#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        if ((a + b) % 3 != 0 || (b - a) > a) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
}