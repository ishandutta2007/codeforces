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
        multiset<int> a, b;
        int n;
        cin >> n;
        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            while (x % 2 == 0) x /= 2;
            a.insert(x);
        }

        for (int i : ra(0, n)) {
            int x;
            cin >> x;
            b.insert(x);
        }
        
        while (b.size()) {
            int bx = *--b.end();
            int ax = *--a.end();
            
            if (bx == ax) {
                b.erase(--b.end());
                a.erase(--a.end());
                continue;
            }

            if (bx > ax) {
                b.erase(--b.end());
                b.insert(bx / 2);
                continue;
            }

            break;
        }

        cout << (b.size() ? "NO\n" : "YES\n");
    }
    
}