// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m;
    cin >> n >> m;

    vector<char> reach(m+1);
    reach[0] = 1;

    vector<int> sol(m+1, 123123123);

    for (int i=0; i<n; i++) {
        ll t, x, y;
        cin >> t >> x >> y;

        vector<int> d(m+1, 123123123);
        for (int j=0; j<=m; j++) if (reach[j]) d[j] = 0;
        for (int j=0; j<=m; j++) {
            ll j2 = t == 1 ? j + (x + 99999) / 100000 : (j * x + 99999ll) / 100000;
            if (j2 <= m) {
                d[j2] = min(d[j2], d[j] + 1);
            }
        }

        for (int j=0; j<=m; j++) {
            if (d[j] <= y) {
                sol[j] = min(sol[j], i+1);
                reach[j] = 1;
            } else {
                reach[j] = 0;
            }
        }
    }

    for (int j=1; j<=m; j++) {
        int z = sol[j];
        if (z == 123123123) {
            z = -1;
        }
        cout << z << " \n"[j == m];
    }
}