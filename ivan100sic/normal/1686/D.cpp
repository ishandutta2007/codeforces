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
        int a, b, ab, ba;
        cin >> a >> b >> ab >> ba;

        string s;
        cin >> s;

        // cerr << "!!! " << s << ' ' << R::count(s, 'A') << ' ' << a+ab+ba << '\n';

        if (R::count(s, 'A') != a + ab + ba) {
            cout << "NO\n";
            continue;
        }

        int n = ssize(s);

        int l = 0;

        int generic = 0;
        vector<int> sab, sba;

        for (int i : ra(1, n+1)) {
            if (i == n || s[i-1] == s[i]) {
                int r = i;
                int w = r-l;
                if (w % 2) {
                    generic += w/2;
                } else {
                    if (s[l] == 'A') {
                        sab.push_back(w/2);
                    } else {
                        sba.push_back(w/2);
                    }
                }
                l = r;
            }
        }

        // greedily make as many ab-s using progressively worse options
        R::sort(sab);
        R::sort(sba, greater<>{});
        
        int ab_rem = ab;
        for (int& w : sab) {
            int d = min(w, ab_rem);
            w -= d;
            ab_rem -= d;
        }

        {
            int d = min(generic, ab_rem);
            generic -= d;
            ab_rem -= d;
        }

        for (int& w : sba) {
            int d = min(w-1, ab_rem);
            if (d > 0) {
                w -= d + 1;
                ab_rem -= d;
            }
        }

        if (ab_rem > 0) {
            cout << "NO\n";
            continue;
        }

        int baleft = 0;
        for (int w : sab) baleft += max(0, w - 1);
    
        baleft += generic;

        for (int w : sba) baleft += w;

        // cerr << "baleft = " << baleft << '\n';

        if (baleft >= ba) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

// ABABAB BA ABAB
// abab   ba  ba
//  baba  ba abab
// 1 1 2 3