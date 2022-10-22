#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a - 1 == b) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}