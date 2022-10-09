// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct pt {
    int x, y;

    strong_ordering operator<=> (const pt& b) const = default;
};

int solve(vector<pt>& a) {
    for (auto& [x, y] : a) {
        int x2 = x + y;
        int y2 = x - y;
        x = x2, y = y2;
    }

    R::sort(a);
    vector<int> d;
    
    for (auto [x, y] : a) {
        y = -y;
        auto it = R::lower_bound(d, y);
        if (it == d.end()) {
            d.push_back(y);
        } else {
            *it = y;
        }
    }

    return d.size();
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pt> a, b;
        for (int i : ra(0, n)) {
            string s;
            cin >> s;
            for (int j : ra(0, m)) {
                auto& v = (i + j) % 2 ? a : b;
                if (s[j] == '1') {
                    v.push_back({i, j});
                }              
            }
        }

        cout << solve(a) + solve(b) << '\n';
    }
    
}