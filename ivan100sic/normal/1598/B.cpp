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
        vector<bitset<5>> a(n);
        for (int i : ra(0, n)) {
            for (int j : ra(0, 5)) {
                int x;
                cin >> x;
                a[i][j] = x;
            }
        }

        if (n % 2) {
            cout << "NO\n";
            continue;
        }

        string ans = "NO";
        for (int i : ra(0, 5)) {
            for (int j : ra(i+1, 5)) {
                int p = 0, q = 0, r = 0, s = 0;
                for (int k : ra(0, n)) {
                    if (a[k][i] && a[k][j]) r++;
                    else if (a[k][i]) p++;
                    else if (a[k][j]) q++;
                    else s++;
                }

                if (s == 0 && p <= n/2 && p+r >= n/2) {
                    ans = "YES";
                }
            }
        }

        cout << ans << '\n';
    }
    
}