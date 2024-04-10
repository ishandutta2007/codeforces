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
        for (int& x : a) cin >> x;

        vector<pair<int, int>> b;
        for (int i : ra(1, n)) {
            b.emplace_back(a[i-1]-a[i], i+1);
        }

        R::sort(b);
        for (auto [_, v] : b) {
            cout << v << ' ';
        }
        cout << "1\n";
    }
}