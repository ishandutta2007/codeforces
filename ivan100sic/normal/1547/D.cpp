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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int val = a[0];
        cout << 0;

        for (int i=1; i<n; i++) {
            int y = val & ~a[i];
            cout << ' ' << y;
            val = (a[i] ^ y);
        }

        cout << '\n';
    }
}