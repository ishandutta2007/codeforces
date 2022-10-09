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
        int n, u, v, f=0;
        cin >> n >> u >> v;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        for (int i=0; i<n-1; i++) {
            f = max(f, abs(a[i] - a[i+1]));
        }

        if (f >= 2) {
            cout << "0\n";
        } else if (f == 1) {
            cout << min(u, v) << '\n';
        } else {
            cout << min(u + v, v + v) << '\n';
        }
    }
}