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
        ll s, n, k;
        cin >> s >> n >> k;

        // s elements, you have to choose the last one
        n--;

        ll l[3] = {0}, c[3] = {0};

        if (s < k) {
            // no interactions
            l[0] = 1;
            c[0] = s - 1;
        } else if (k == s) {
            // farm is obv. ideal
            cout << "YES\n";
            continue;
        } else if (s % k == 0) {
            c[0] = 1;
            l[0] = max(0ll, s / k - 3);
            
            c[1] = k - 1;
            l[1] = s / k; 
        } else {
            c[0] = 2;
            l[0] = s / k - 1;

            c[1] = s % k - 1;
            l[1] = s / k + 1;

            c[2] = k - c[0] - c[1];
            l[2] = s / k;
        }

        // cerr << c[0] << " degenerate paths of length " << l[0] << '\n';
        // cerr << c[1] << " big paths of length " << l[1] << '\n';
        // cerr << c[2] << " small paths of length " << l[2] << '\n';

        ll h = 0;
        for (int i : {0, 1, 2}) {
            h += (l[i] + 1) / 2 * c[i];
        }

        cout << (h < n ? "YES\n" : "NO\n");
    }
}