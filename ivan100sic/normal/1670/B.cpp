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
        int k;
        cin >> k;
        set<char> g;
        for (int i : ra(0, k)) {
            char x;
            cin >> x;
            g.insert(x);
        }

        for (char& x : s) {
            x = g.count(x);
        }

        int sol = 0, zeros = 0;
        for (int i : ra(0, n)) {
            if (s[i] == 0) {
                zeros++;
            } else {
                sol = max(zeros + (i == zeros ? 0 : 1), sol);
                zeros = 0;
            }
        }

        if (sol > 0) {
            cout << sol << '\n';
        } else {
            cout << "0\n";
            // if (R::count(s, 0) == n) {
            // } else {
            //     cout << "1\n";
            // }
        }
    }
}