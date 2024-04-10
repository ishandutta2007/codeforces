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
        int a, b, c, m;
        cin >> a >> b >> c >> m;

        int n = a + b + c;
        int h = max({a, b, c});
        // min je 0 osim ako h ne dominira
        int mn = max(0, 2 * h - n - 1);
        int mx = n - 3;

        cout << (mn <= m && m <= mx ? "YES\n" : "NO\n");
    }
}