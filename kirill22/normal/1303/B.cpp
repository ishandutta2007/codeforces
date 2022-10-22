#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, g, b;
        cin >> n >> g >> b;
        int x = (n + 1) / 2;
        if (x % g == 0) {
            cout << max(n, (g + b) * (x / g) - b) << endl;
        }
        else {
            cout << max((g + b) * (x / g) + x % g, n) << endl;
        }
    }
}