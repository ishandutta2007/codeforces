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
        string s;
        cin >> n >> s;

        string sol = string(2, s[0]);
        int j = n-1;
        for (int i : ra(0, n-1)) {
            if (s[i] < s[i+1]) {
                j = i;
                break;
            }
        }
        auto st = s.substr(0, j+1);
        auto ts = st;
        R::reverse(ts);
        cout << min(sol, st + ts) << '\n';
    }
}