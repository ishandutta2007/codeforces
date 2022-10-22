#include "bits/stdc++.h"

using namespace std;

void solve() {
    for (int x = 1; ; x++) {
        for (int y = 1; y < x; y++) {
            cout << "? " << x << " " << y << endl;
            long long res;
            cin >> res;
            if (res == -1) {
                cout << "! " << x - 1 << endl;
                return;
            }
            cout << "? " << y << " " << x << endl;
            long long res2;
            cin >> res2;
            if (res != res2) {
                cout << "! " << res + res2 << endl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
}