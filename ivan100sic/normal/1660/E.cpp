// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
string s[2005];
short d[4005][4005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int h = 0, c = 0;
        for (int i : ra(0, n)) {
            cin >> s[i];
            for (int j : ra(0, n)) {
                c += s[i][j] == '1';
            }
        }
        for (int i : ra(0, 2*n)) {
            for (int j : ra(0, 2*n)) {
                d[i+1][j+1] = d[i][j] + (s[i % n][j % n] == '1');

                if (i+1 >= n && j+1 >= n) {
                    h = max(h, d[i+1][j+1] - d[i+1-n][j+1-n]);
                }
            }
        }

        cout << c-h + n-h << '\n';
    }
}