// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

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
        auto N = ra(0, n);
        vector a(n, vector(n, 0));
        for (int i : N) {
            for (int j : N) {
                cin >> a[i][j];
            }
        }

        int sol = 0;
        for (int i=0; i<n/2; i+=2) {
            vector<pair<int, int>> p;
            for (int j=i; j<n-i; j++) p.emplace_back(i, j);
            for (int j=i+1; j<n-i-1; j++) p.emplace_back(j, n-i-1);
            for (int j=n-i-1; j>=i; j--) p.emplace_back(n-i-1, j);
            for (int j=n-i-2; j>=i+1; j--) p.emplace_back(j, i);

            for (int i : ra(0, ssize(p))) {
                if (i % 4 < 2) {
                    sol ^= a[p[i].first][p[i].second];
                }
            }
        }

        cout << sol << '\n';
    }
}