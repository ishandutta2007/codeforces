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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    vector<int> ideg(n), q(n), tmp;
    int qs = 0, qe = 0;

    for (int i : ra(0, m)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        e[x].push_back(y);
        ideg[y]++;
    }

    tmp = ideg;

    for (int i : ra(0, n)) {
        if (ideg[i] == 0) {
            q[qe++] = i;
        }
    }

    while (qs != qe) {
        int x = q[qs++];
        for (int y : e[x]) {
            if (0 == --ideg[y]) {
                q[qe++] = y;
            }
        }
    }

    swap(ideg, tmp);
    vector<int> d(n, 1);

    for (int x : q) {
        for (int y : e[x]) {
            if (e[x].size() >= 2 && ideg[y] >= 2) {
                d[y] = max(d[y], d[x] + 1);
            }
        }
    }

    cout << *R::max_element(d) << '\n';
}