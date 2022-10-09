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
        int n, m;
        cin >> n >> m;
        vector<string> a(n, string(m, '0'));

        auto stavi = [&](int x, int y) {
            for (int i=x-1; i<=x+1; i++) {
                for (int j=y-1; j<=y+1; j++) {
                    if (i < 0 || j < 0 || i >= n || j >= m) continue;
                    if (a[i][j] == '1') {
                        return;
                    }
                }
            }

            a[x][y] = '1';
        };

        for (int j=0; j<m; j++) {
            stavi(0, j);
        }
        for (int i=1; i<n-1; i++) {
            stavi(i, m-1);
        }
        for (int j=m-1; j>=0; j--) {
            stavi(n-1, j);
        }
        for (int i=n-2; i>=1; i--) {
            stavi(i, 0);
        }

        for (int i=0; i<n; i++) {
            cout << a[i] << '\n';
        }
        cout << '\n';
    }
}