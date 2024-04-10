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

        if (R::count(s, '1') % 2) {
            cout << "-1\n";
            continue;
        }

        vector<int> r;
        char tgt = '0';
        for (int i=0; i<2*n; i+=2) {
            if (s[i] != s[i+1]) {
                r.push_back(s[i] == tgt ? i : i+1);
                tgt ^= 1;
            }
        }

        cout << r.size();
        for (int x : r) cout << ' ' << x+1;
        cout << '\n';

        for (int i : ra(0, n)) cout << 2*i+1 << ' ';
        cout << '\n';
    }
}