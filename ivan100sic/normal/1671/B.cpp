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

        bool ans = 0;
        for (int l : {a[0]-1, a[0], a[0]+1}) {
            bool ok = 1;
            for (int i : ra(0, n)) {
                if (abs(a[i] - (l+i)) > 1) {
                    ok = 0;
                }
            }
            ans |= ok;
        }

        cout << (ans ? "YES\n" : "NO\n");
    }
    
}