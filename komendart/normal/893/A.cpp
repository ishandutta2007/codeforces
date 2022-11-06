#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    int rest = 3;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == rest) {
            cout << "NO\n";
            return 0;
        }
        rest = 1 + 2 + 3 - x - rest;
    }
    cout << "YES\n";
}