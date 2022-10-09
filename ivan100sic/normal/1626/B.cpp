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
        int n = ssize(s);
        int big = -1;
        for (int i : ra(0, n-1)) {
            if (s[i] - '0' + s[i+1] - '0' >= 10) { 
                big = i;
            }
        }

        if (big != -1) {
            int i = big;
            int v = s[i] - '0' + s[i+1] - '0';
            s[i] = v / 10 + '0';
            s[i+1] = v % 10 + '0';
            cout << s << '\n';
        } else {
            int i = 0;
            int v = s[i] - '0' + s[i+1] - '0';
            cout << v << s.substr(2) << '\n';
        }
    }
}