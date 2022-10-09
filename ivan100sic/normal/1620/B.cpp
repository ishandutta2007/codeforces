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
        int w, h;
        cin >> w >> h;
        vector<int> a[4];
        for (auto& v : a) {
            int k;
            cin >> k;
            v.resize(k);
            for (int& x : v) cin >> x;
        }
        swap(a[1], a[2]);

        const ll dim[4] = {h, w, h, w};
        ll sol = 0; 
        for (int i : ra(0, 4)) {
            sol = max(sol, (a[i].back() - a[i][0]) * dim[i]);
        }
        
        cout << sol << '\n';
    }
}