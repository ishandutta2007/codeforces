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
        int n, m;
        cin >> n >> m;

        set<pair<int, int>> s;
        vector<int> a(n);
        
        auto add = [&](int i, int x) {
            s.erase({i, x});
            auto it = s.emplace(i, x).first;

            if (it != s.begin() && prev(it)->second <= x) {
                s.erase(it);
            } else {
                auto jt = next(it);
                while (jt != s.end() && x <= jt->second) {
                    jt = s.erase(jt);
                }
            }
        };

        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            add(i, x);
            a[i] = x;
        }

        for (int j : ra(0, m)) {
            int k, d;
            cin >> k >> d;
            k--;
            a[k] -= d;
            add(k, a[k]);
            cout << s.size() << ' ';
        }
        cout << '\n';
    }
    
}