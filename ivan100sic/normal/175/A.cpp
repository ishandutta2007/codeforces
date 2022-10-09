// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

bool ok(string s) {
    return (s.size() == 1 || s[0] != '0') && s.size() <= 7 && stoi(s) <= 1000000;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    string s;
    cin >> s;
    int n = s.size(), sol = -1;
    for (int i : ra(1, n)) {
        for (int j : ra(i+1, n)) {
            string p = s.substr(0, i);
            string q = s.substr(i, j-i);
            string r = s.substr(j);

            if (ok(p) && ok(q) && ok(r)) {
                sol = max(sol, stoi(p) + stoi(q) + stoi(r));
            }
        }
    }
    cout << sol << '\n';
}