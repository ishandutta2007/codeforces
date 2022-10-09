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
        vector<pair<int, int>> a(n);
        for (int i=0; i<n; i++) {
            int k;
            cin >> k;
            vector<int> b(k);
            for (int& x : b) cin >> x;
            int z = 0;
            for (int i=0; i<k; i++) {
                z = max(z, b[i] - i);
            }
            a[i] = {z+1, k};
        }

        sort(begin(a), end(a));

        int l = 0, r = 1.04e9, o = -1;
        while (l <= r) {
            int m = (l+r) / 2;
            int t = m;
            int ok = 1;
            for (auto [z, k] : a) {
                if (t < z) {
                    ok = 0;
                    break;
                } else {
                    t += k;
                }
            }

            if (ok) {
                o = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        cout << o << '\n';
    }
}