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
        map<int, int> mp;
        for (int& x : a) {
            cin >> x;
            mp[x]++;
        }

        {
            bool no = 0;
            for (auto [k, v] : mp) {
                if (v % 2) {
                    no = 1;
                }
            }
            if (no) {
                cout << "-1\n";
                continue;
            }
        }

        vector<int> tandem;
        int offset = 0;
        vector<pair<int, int>> sol;
        while (a.size()) {
            int i = find(begin(a)+1, end(a), a[0]) - begin(a);
            tandem.push_back(2*i);
            for (int j=1; j<i; j++) {
                sol.emplace_back(i+j+offset, a[j]);
            }
            reverse(begin(a) + 1, begin(a) + i + 1);
            a.erase(begin(a), begin(a) + 2);
            offset += 2*i;
        }

        cout << sol.size() << '\n';
        for (auto [x, y] : sol) {
            cout << x << ' ' << y << '\n';
        }

        cout << tandem.size() << '\n';
        for (int x : tandem) {
            cout << x << ' ';
        }
        cout << '\n';
    }
    
}