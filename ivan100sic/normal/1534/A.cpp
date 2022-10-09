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
        int c[2] = {1, 1};
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
            for (int j=0; j<m; j++) {
                if (a[i][j] != '.') {
                    int x = a[i][j] == 'R';
                    x ^= i ^ j;
                    c[x & 1] = 0;
                }
            }
        }

        if (!c[0] && !c[1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            int k = find(c, c+2, 1) - c;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    cout << ((k+i+j) % 2 ? 'W' : 'R');
                }
                cout << '\n';
            }
        }
    }
}