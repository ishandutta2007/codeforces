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
        int m;
        cin >> m;
        vector<int> a(m+2), b(m+2);
        for (int i=1; i<=m; i++) cin >> a[i];
        for (int i=1; i<=m; i++) cin >> b[i];

        for (int i=m; i>=1; i--) a[i] += a[i+1];
        for (int i=1; i<=m; i++) b[i] += b[i-1];

        int sol = 2e9;
        for (int i=1; i<=m; i++) {
            sol = min(sol, max(b[i-1], a[i+1]));
        }

        cout << sol << '\n';
    }
}