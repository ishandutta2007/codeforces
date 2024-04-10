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
        vector<int> b(n+1);
        for (int i : ra(0, n)) {
            cin >> b[i+1];
        }

        vector<int> p(n+1);
        for (int i : ra(0, n)) {
            cin >> p[i+1];
        }

        vector<int> d(n+1);
        for (int i : ra(1, n+1)) {
            d[p[i]] = i;
        }

        bool ok = 1;

        for (int i : ra(1, n+1)) {
            if (i != b[i] && d[b[i]] > d[i]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }

        for (int i : ra(1, n+1)) {
            cout << (i == b[i] ? 0 : d[i] - d[b[i]]) << " \n"[i == n];
        }
    }
    
}