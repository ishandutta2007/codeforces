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
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;

        if (k1 + k2 >= 2 * w && 2 * n - k1 - k2 >= 2 * b) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}