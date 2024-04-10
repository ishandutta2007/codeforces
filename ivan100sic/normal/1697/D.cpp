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

    int n;
    cin >> n;

    vector<vector<int>> g;
    for (int i : ra(1, n+1)) {
        vector<int> last;
        for (auto& v : g) {
            last.push_back(v.back());
        }
        auto l0 = last;
        R::sort(last);
        int m = *R::lower_bound(ra(0, ssize(last)), true, {}, [&](int j) {
            cout << "? 2 " << last[j] << ' ' << i << '\n' << flush;
            int y;
            cin >> y;
            return y != ssize(last) - j;
        }) - 1;

        if (m == -1) {
            g.push_back({i});
        } else {
            int m0 = R::find(l0, last[m]) - begin(l0);
            g[m0].push_back(i);
        }
    }

    string sol(n, ' ');
    for (auto& v : g) {
        cout << "? 1 " << v.back() << '\n' << flush;
        char c;
        cin >> c;
        for (int i : v) {
            sol[i-1] = c;
        } 
    }

    cout << "! " << sol << '\n';
}