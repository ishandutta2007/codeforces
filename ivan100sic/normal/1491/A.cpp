// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, q, z = 0;
    cin >> n >> q;
    vector<int> a(n);
    for (int& x : a) cin >> x, z += x;
    while (q--) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            x--;
            z -= a[x];
            a[x] ^= 1;
            z += a[x];
        } else {
            cout << (z >= x) << '\n';
        }
    }
}