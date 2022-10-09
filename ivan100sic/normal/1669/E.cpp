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
        int c[26][26] = {0};
        for (int i : ra(0, n)) {
            string s;
            cin >> s;
            c[s[0]-'a'][s[1]-'a']++;
        }

        ll x = 0;
        for (int i : ra(0, 26)) {
            for (int j : ra(0, 26)) {
                for (int k : ra(0, 26)) {
                    for (int l : ra(0, 26)) {
                        int d = i != k;
                        d += j != l;
                        if (d == 1) {
                            x += c[i][j] * 1ll * c[k][l];
                        }
                    }
                }
            }
        }

        cout << x/2 << '\n';
    }
    
}