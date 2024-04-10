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
        multiset<int> a, b;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            a.insert(x);
        }

        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            b.insert(x);
        }

        int sol = 0;

        while (!a.empty()) {
            auto ait = prev(a.end());
            auto bit = prev(b.end());

            if (*ait == *bit) {
                a.erase(ait);
                b.erase(bit);
            } else if (*ait > *bit) {
                int x = to_string(*ait).size();
                a.erase(ait);
                a.insert(x);
                sol++;
            } else {
                int y = to_string(*bit).size();
                b.erase(bit);
                b.insert(y);
                sol++;
            }
        }

        cout << sol << '\n';
    }
}