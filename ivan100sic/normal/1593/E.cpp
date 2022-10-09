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
        int n, k;
        cin >> n >> k;
        vector<set<int>> e(n+1);

        for (int i=0; i<n-1; i++) {
            int x, y;
            cin >> x >> y;
            e[x].insert(y);
            e[y].insert(x);
        }

        vector<int> le;
        for (int x : ra(1, n+1)) {
            if (e[x].size() <= 1) {
                le.push_back(x);
            }
        }

        int rem = n;

        for (int i=0; i<k; i++) {
            vector<int> tmp;
            set<int> maybe;
            for (int x : le) {
                rem--;
                for (int y : e[x]) {
                    e[y].erase(x);
                    maybe.insert(y);
                }
            }

            le = {};
            for (int x : maybe) {
                if (e[x].size() <= 1) {
                    le.push_back(x);
                }
            }

            if (rem == 0) break;
        }

        cout << rem << '\n';
    }
}