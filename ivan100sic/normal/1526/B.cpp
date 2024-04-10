// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int x, k = 0;
        cin >> x;
        for (int y=0; y<11; y++) {
            int r = x - 111*y;
            if (r >= 0 && r % 11 == 0) {
                k = 1;
            }
        }

        cout << (k ? "YES\n" : "NO\n");
    }
}