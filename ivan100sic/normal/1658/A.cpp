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
        string s;
        cin >> s;

        int z = 0;
        for (int i : ra(1, n)) {
            z += 2*(s[i] == '0' && s[i-1] == '0');
        }

        for (int i=2; i<n; i++) {
            z += (s[i] == '0' && s[i-1] == '1' && s[i-2] == '0');
        }

        cout << z << '\n';
    }
    
}