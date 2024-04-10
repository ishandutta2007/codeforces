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
        iota(begin(a), end(a), 1);
        
        auto pr = [&] {
            for (int x : a) cout << x << ' ';
            cout << '\n';
        };

        cout << n << '\n';
        pr();
        for (int i : ra(0, n-1)) {
            swap(a[i], a[i+1]);
            pr();
        }
    }
    
}