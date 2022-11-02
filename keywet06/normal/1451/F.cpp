#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m, 0));
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < m; ++k) cin >> a[j][k];
        }
        if (n == 1 && m == 1) {
            cout << (a[0][0] ? "Ashish" : "Jeel") << endl;
        } else {
            vector<int> X(n + m - 2, 0);
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < m; ++k) {
                    int s = j + k;
                    if (s == n + m - 2) --s;
                    X[s] ^= a[j][k];
                }
            }
            bool ok = false;
            for (int j = 0; j < n + m - 2; ++j) ok |= X[j] != 0;
            cout << (ok ? "Ashish" : "Jeel") << endl;
        }
    }
}