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
        int n;
        cin >> n;
        ll z = 0;
        for (int i=0; i<n; i++) {
            int x;
            cin >> x;
            z += x;
        }

        z %= n;
        cout << z * (n-z) << '\n';
    }
}