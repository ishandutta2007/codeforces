// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

void flip(auto& s) {
    for (auto& c : s) {
        c = c ^ 'D' ^ 'R';
    }
}

ll above(auto& s) {
    int r = R::count(s, 'R');
    int k = 0;
    ll z = 0;
    for (char c : s) {
        if (c == 'R') {
            k++;
        } else {
            z += r - k;
        }
    }
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        if (s[0] == 'D') {
            flip(s);
        }

        ll sol = above(s);
        int pref = 1;
        while (pref < ssize(s) && s[pref] == 'R') pref++;

        sol += (n-1)*pref;
        
        auto rem = s.substr(pref);
        if (rem == "") {
            cout << n << '\n';
            continue;
        }
        flip(rem);

        sol += above(rem);

        cout << n*n - sol << '\n';
    }
}