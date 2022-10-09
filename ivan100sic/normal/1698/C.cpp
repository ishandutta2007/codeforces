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

        vector<int> pos, neg;
        int zeros = 0;

        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            if (x > 0) {
                pos.push_back(x);
            } else if (x < 0) {
                neg.push_back(x);
            } else {
                zeros++;
            }
        }

        if (pos.size() >= 3 || neg.size() >= 3) {
            cout << "NO\n";
            continue;
        }

        zeros = min(zeros, 3);
        auto all = pos;
        R::copy(neg, back_inserter(all));
        fill_n(back_inserter(all), zeros, 0);

        int m = ssize(all);
        string ans = "YES\n";
        for (int i : ra(0, m)) {
            for (int j : ra(i+1, m)) {
                for (int k : ra(j+1, m)) {
                    if (!R::count(all, all[i] + all[j] + all[k])) {
                        ans = "NO\n";
                    }
                }
            }
        }
        cout << ans;
    }
}