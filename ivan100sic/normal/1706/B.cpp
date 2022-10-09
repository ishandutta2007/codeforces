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
        vector<vector<int>> e(n);
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            x--;
            e[x].push_back(i);
        }

        for (int x : ra(0, n)) {
            int c = 0;
            if (e[x].size()) {
                c = 1;
                for (int j : ra(0, ssize(e[x]) - 1)) {
                    if ((e[x][j+1] - e[x][j]) % 2) {
                        c++;
                    }
                }
            }
            cout << c << ' ';
        }
        cout << '\n';
    }
    
}