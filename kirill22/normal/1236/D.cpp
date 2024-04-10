#include<bits/stdc++.h>
using namespace std;
signed main() {
    long long n, m, k, res = 0, x = 0, y = 0, A = 0, B = 0, s = 0;
    cin >> n >> m >> k;
    map<int, vector<long long>> X, Y;
    for (int i = 0 ; i < k; i++) {
        cin >> x >> y;
        X[x - 1].push_back(y - 1);
        Y[y - 1].push_back(x - 1);
    }
    res = n * m - k - 1, n = n - 1, m = m - 1, x = 0, y = 0;
    for (auto &c : X) {
        sort(c.second.begin(), c.second.end());
    }
    for (auto &c : Y) {
        sort(c.second.begin(), c.second.end());
    }
    for (int t = 1; t < 1e18; t++) {
        if ((x == n && y == m && A == n && B == m) || (x > n) || (y > m)) {
            if (s == res) cout << "Yes";
            else cout << "No";
            return 0;
        }
        if (t % 4 == 0) {
            if (lower_bound(Y[B].begin(), Y[B].end(), A) - Y[B].begin() - 1 != -1) {
                x = max(x, Y[B][lower_bound(Y[B].begin(), Y[B].end(), A) - Y[B].begin() - 1] + 1);
            }
            s += (A - x), y++, A = x;
        }
        if (t % 4 == 1) {
            if (lower_bound(X[A].begin(), X[A].end(), B) - X[A].begin() != X[A].size()) {
                m = min(m, X[A][lower_bound(X[A].begin(), X[A].end(), B) - X[A].begin()] - 1);
            }
            s += (m - B), x++, B = m;
        }
        if (t % 4 == 2) {
            if (lower_bound(Y[B].begin(), Y[B].end(), A) - Y[B].begin() != Y[B].size()) {
                n = min(n, Y[B][lower_bound(Y[B].begin(), Y[B].end(), A) - Y[B].begin()] - 1);
            }
            s += (n - A), m--, A = n;
        }
        if (t % 4 == 3) {
            if (lower_bound(X[A].begin(), X[A].end(), B) - X[A].begin() - 1 != -1) {
                y = max(y, X[A][lower_bound(X[A].begin(), X[A].end(), B) - X[A].begin() - 1] + 1);
            }
            s += (B - y), n--, B = y;
        }
    }
}