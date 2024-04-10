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
        vector<int> a(n);
        for (int& x : a) cin >> x;

        vector<vector<int>> e(n+1);

        for (int i : ra(0, n)) {
            int d = a[i];
            if (i-d >= 0) {
                e[i-d].push_back(i+1);
            }

            if (i+d+1 <= n) {
                e[i].push_back(i+d+1);
            }
        }

        queue<int> q;
        string v(n+1, 0);
        q.push(0);
        v[0] = 1;
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int y : e[x]) {
                if (!v[y]) {
                    v[y] = 1;
                    q.push(y);
                }
            }
        }

        cout << (v[n] ? "YES\n" : "NO\n");
    }
}