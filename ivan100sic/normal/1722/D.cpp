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
        string s;
        cin >> s;

        ll val = 0;
        vector<int> g;

        for (int i : ra(0, n)) {
            int x = i, y = n-1-i;
            if (s[i] == 'R') {
                swap(x, y);
            }
            val += x;
            g.push_back(y-x);
        }

        R::sort(g, greater<>{});

        for (int i : ra(0, n)) {
            val += max(g[i], 0);
            cout << val << " \n"[i == n-1];
        }
    }
}