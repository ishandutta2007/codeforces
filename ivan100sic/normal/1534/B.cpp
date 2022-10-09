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
        for (int& x : a) {
            cin >> x;
        }

        ll z = 0;
        for (int i=0; i<n; i++) {
            int l = i ? a[i-1] : 0;
            int r = i+1 < n ? a[i+1] : 0;
            int d = min(a[i] - l, a[i] - r);
            if (d > 0) {
                a[i] -= d;
                z += d;
            }
        }

        for (int i=1; i<n; i++) {
            z += abs(a[i] - a[i-1]);
        }

        z += a[0] + a[n-1];
        cout << z << '\n';
    }
}