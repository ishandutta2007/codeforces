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
        int n, m, k;
        cin >> n >> m >> k;

        int maxhor = n*(m/2);
        int maxver = m*(n/2);

        if (k <= maxhor && n*m/2 - k <= maxver && k % 2 == maxhor % 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}