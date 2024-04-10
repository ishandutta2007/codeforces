// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct entry {
    int l, r, v;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;

    vector<entry> s;
    int sol = 0, unstabbed = 0;
    for (int i : ra(0, n)) {
        int x;
        cin >> x;

        for (auto& [l, r, v] : s) {
            l++, r++;
            v = gcd(v, x);
        }
        s.push_back({1, 1, x});
        unstabbed++;
        int j = 0;
        for (int i=1; i<ssize(s); i++) {
            if (s[i].v == s[j].v) {
                s[j].l = s[i].l;
            } else {
                s[++j] = s[i];
            }
        }
        s.resize(j+1);

        for (auto [l, r, v] : s) {
            if (l <= v && v <= r) {
                if (v <= unstabbed) {
                    unstabbed = 0;
                    sol++;
                }
            }
        }
        cout << sol << ' ';
    }
    cout << "\n";
}