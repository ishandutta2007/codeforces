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

    int n, q;
    string s;
    cin >> n >> q >> s;

    if (n < 3) {
        for (int i : ra(0, q)) {
            cout << "0\n";
        }
        return 0;
    }

    int z = 0;
    for (int i : ra(0, n-2)) {
        if (string_view(s.begin() + i, s.begin() + i + 3) == "abc") {
            z++;
        }
    }

    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        i--;
        
        int l = max(0, i-2);
        int r = min(n-2, i);

        for (int j : ra(l, r+1)) {
            if (string_view(s.begin() + j, s.begin() + j + 3) == "abc") {
                z--;
            }
        }

        s[i] = c;

        for (int j : ra(l, r+1)) {
            if (string_view(s.begin() + j, s.begin() + j + 3) == "abc") {
                z++;
            }
        }

        cout << z << '\n';
    }
}