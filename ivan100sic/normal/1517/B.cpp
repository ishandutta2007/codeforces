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
        vector<deque<int>> a(n), b(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }

        for (int i=0; i<n; i++) {
            sort(begin(a[i]), end(a[i]));
        }

        for (int j=0; j<m; j++) {
            int x = min_element(begin(a), end(a), [](const auto& x, const auto& y) { return x[0] < y[0]; }) - begin(a);
            for (int i=0; i<n; i++) {
                if (i == x) {
                    b[i].push_back(a[i].front());
                    a[i].pop_front();
                } else {
                    b[i].push_back(a[i].back());
                    a[i].pop_back();
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cout << b[i][j] << " \n"[j == m-1];
            }
        }
    }
}