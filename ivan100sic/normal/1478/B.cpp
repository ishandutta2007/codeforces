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
        int q, d;
        cin >> q >> d;
        vector<int> ok;
        for (int x=1; x<=200; x++) {
            if (to_string(x).find('0' + d) != string::npos) {
                ok.push_back(x);
            }
        }

        vector<int> dp(500);
        dp[0] = 1;
        for (int x=0; x<500; x++) {
            if (dp[x]) {
                for (int y : ok) {
                    if (x+y < 500) dp[x+y] = 1;
                }
            }
        }

        while (q--) {
            int x;
            cin >> x;
            if (x >= 500 || dp[x]) cout << "YES\n";
            else cout << "NO\n";
        }        
    }
}