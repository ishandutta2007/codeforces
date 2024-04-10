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
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        x--, y--;

        vector<int> a(k);
        for (int& x : a) cin >> x, x--;
        a.push_back(y);

        vector<vector<int>> e(n);
        for (int i : ra(1, n)) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            e[x].push_back(y);
            e[y].push_back(x);
        }

        queue<int> q;
        vector<int> p(n, -1), d(n, -1);
        p[x] = -2;
        d[x] = 0;
        q.push(x);
        while (q.size()) {
            int x = q.front(); q.pop();
            for (int y : e[x]) {
                if (p[y] == -1) {
                    p[y] = x;
                    d[y] = d[x] + 1;
                    q.push(y);
                }
            }
        }

        vector<int> mark(n, 0);
        mark[x] = 1;
        for (int x : a) {
            for (int y=x; !mark[y]; y=p[y]) {
                mark[y] = 1;
            }
        }

        cout << R::count(mark, 1) * 2 - d[y] - 2 << '\n';
    }
}