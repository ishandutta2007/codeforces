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

        int w, m;
        cin >> w >> m;
        
        vector<int> z(n+1);
        for (int i : ra(0, n)) {
            z[i+1] = z[i] + (s[i] - '0');
        }

        int remp1[9], remp2[9];
        R::fill(remp1, -1);
        R::fill(remp2, -1);
        for (int i : ra(0, n-w+1)) {
            int r = (z[i+w] - z[i]) % 9;
            if (remp1[r] == -1) {
                remp1[r] = i+1;
            } else if (remp2[r] == -1) {
                remp2[r] = i+1;
            }
        }
        
        while (m--) {
            int l, r, k;
            cin >> l >> r >> k;
            int rq = z[r] - z[l-1];

            pair<int, int> sol = {123123123, 123123123};
            for (int i : ra(0, 9)) {
                for (int j : ra(0, 9)) {
                    if ((i * rq + j) % 9 == k) {
                        if (i == j) {
                            if (remp1[i] != -1 && remp2[i] != -1) {
                                sol = min(sol, pair(remp1[i], remp2[i]));
                            }
                        } else {
                            if (remp1[i] != -1 && remp1[j] != -1) {
                                sol = min(sol, pair(remp1[i], remp1[j]));
                            }
                        }
                    }
                }
            }

            if (sol.first == 123123123) {
                sol = {-1, -1};
            }

            cout << sol.first << ' ' << sol.second << '\n';
        }
    }
}