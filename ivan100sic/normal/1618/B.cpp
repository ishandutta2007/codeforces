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
        vector<string> a(n-2), b;     
        for (auto& s : a) cin >> s;

        int c = 0;
        for (int i : ra(0, n-3)) {
            b.push_back(a[i]);
            if (a[i][1] != a[i+1][0]) {
                b.push_back(string{a[i][1], a[i+1][0]});
                c++;
            }
        }
        b.push_back(a[n-3]);

        for (string s : b) {
            cout << s[0];
        }
        if (!c) cout << b.back()[1];
        cout << b.back()[1] << '\n';
    }
    
}