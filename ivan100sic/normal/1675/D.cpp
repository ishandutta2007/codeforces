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
        vector<int> p(n+1), outdeg(n+1), used(n+1);
        vector<vector<int>> paths;
        for (int i : ra(1, n+1)) {
            cin >> p[i];
            if (i != p[i]) {
                outdeg[p[i]]++;
            }
        }

        for (int i=1; i<=n; i++) {
            if (outdeg[i] == 0 && !used[i]) {
                vector<int> path;
                for (int j = i; !used[j]; j = p[j]) {
                    path.push_back(j);
                    used[j] = 1;
                }
                paths.emplace_back(move(path));
            }
        }

        cout << paths.size() << '\n';
        for (auto& p : paths) {
            cout << p.size() << '\n';
            for (int x : R::reverse_view(p)) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}