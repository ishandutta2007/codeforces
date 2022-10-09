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
        int n, k;
        cin >> n >> k;
        string s, sol;
        cin >> s;

        vector<int> f(26);
        for (char c : s) f[c-'a']++;

        for (int i : ra(0, k)) {
            // take small one at a time
            int rem = n / k;
            int p = 0;
            while (rem) {
                if (f[p]) {
                    f[p]--;
                    p++;
                    rem--;
                } else {
                    break;
                }
            }

            sol += char(p + 'a');
        }

        cout << sol << '\n';
    }
}