// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        iota(begin(a), end(a), 1);
        set<vector<int>> s;
        while (ssize(s) < n) {
            R::shuffle(a, eng);
            bool ok = true;
            for (int i : ra(0, n-2)) {
                if (a[i] + a[i+1] == a[i+2]) {
                    ok = false;
                }
            }
            if (ok) s.insert(a);
        }

        for (auto a : s) {
            for (int x : a) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }
}