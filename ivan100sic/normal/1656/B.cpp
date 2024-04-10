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
        string a = "NO\n";
        set<int> s;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            if (s.contains(x-k) || s.contains(x+k)) {
                a = "YES\n";
            }
            s.insert(x);
        }
        cout << a;
    }
}