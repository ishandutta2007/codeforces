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
        cin >> s;
        int n = s.size();

        vector<int> a(n+1), b(n+1);
        for (int i=0; i<n; i++) {
            a[i+1] = a[i] + (i % 2 == 0 && (s[i] == '[' || s[i] == ']'));
            b[i+1] = b[i] + (i % 2 == 1 && (s[i] == '[' || s[i] == ']'));
        }

        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            cout << abs((b[r]-b[l])-(a[r]-a[l])) << '\n';
        }
    }
    
}