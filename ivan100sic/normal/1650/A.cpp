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
        string s;
        char c;
        cin >> s >> c;

        int n = ssize(s);
        bool ok = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c && i % 2 == 0) {
                ok = 1;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    
}