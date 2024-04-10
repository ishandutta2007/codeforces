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

        int i = n/2;
        int l = i, r = i;
        while (l > 0 && s[l-1] == s[i]) l--;
        while (r+1 < n && s[r+1] == s[i]) r++;

        cout << r-l+1 << '\n';
    }
}