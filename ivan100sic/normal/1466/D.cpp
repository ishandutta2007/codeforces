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
        for (int i=0; i<n; i++) cin >> a[i].first;
        for (int i=0; i<n-1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            a[x].second++;
            a[y].second++;
        }

        sort(begin(a), end(a), greater<pair<int, int>>());

        ll z = 0;
        for (auto [x, y] : a) z += x;
        cout << z;
        for (int i=0; i<n; i++) {
            for (int j=1; j<a[i].second; j++) {
                z += a[i].first;
                cout << ' ' << z;
            }
        }
        cout << '\n';
    }
}