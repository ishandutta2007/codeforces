// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct blok {
    char tip;
    int len;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n, k, x;
        string s;
        cin >> n >> k >> x >> s;
        x--;

        vector<blok> b;
        for (char c : s) {
            if (c == '*') {
                if (b.size() && b.back().tip == '*') {
                    b.back().len++;
                } else {
                    b.push_back({c, 1});
                }
            } else {
                b.push_back({'a', 1});
            }
        }

        string o;
        for (auto [t, l] : R::reverse_view(b)) {
            if (t == '*') {
                o += string(x % (k*l+1), 'b');
                x /= k*l+1;
            } else {
                o.push_back(t);
            }
        }

        R::reverse(o);
        cout << o << "\n";
    }
}