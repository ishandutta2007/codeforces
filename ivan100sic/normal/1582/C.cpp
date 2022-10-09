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
        int sol = n + 1;

        for (char c : ra('a', 'z' + 1)) {
            int l = 0, r = n - 1, skip = 0;
            while (l < r) {
                if (s[l] == s[r]) {
                    l++;
                    r--;
                } else if (s[l] == c) {
                    l++;
                    skip++;
                } else if (s[r] == c) {
                    r--;
                    skip++;
                } else {
                    skip = n+1;
                    break;
                }
            }

            sol = min(sol, skip);
        }

        if (sol == n+1) sol = -1;
        cout << sol << '\n';
    }
    
}