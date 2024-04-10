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
        int n, s = 0;
        cin >> n;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            s += a[i];
        }

        if (s > 0) {
            sort(begin(a), end(a), greater<int>());
        } else if (s < 0) {
            sort(begin(a), end(a));
        } else {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}