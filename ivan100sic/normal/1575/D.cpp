// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int dp[11][33];
const auto digits = ra('0', '9' + 1);

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    string s;
    cin >> s;

    if (size(s) == 1) {
        cout << int(s[0] == '0' || s[0] == 'X' || s[0] == '_') << '\n';
        return 0;
    }

    vector<string> repl;
    if (R::count(s, 'X')) {
        for (char c : digits) {
            string b = s;
            for (char& x : b) if (x == 'X') x = c;
            repl.push_back(b);
        }
    } else {
        repl.push_back(s);
    }

    int sol = 0, n = size(s);
    for (string s : repl) {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i : ra(0, n)) {
            for (int r : ra(0, 25)) {
                for (char c : digits) {
                    if (c != s[i] && s[i] != '_') continue;
                    if (i == 0 && c == '0') continue;
                    dp[i+1][(10*r + c - '0') % 25] += dp[i][r];
                }
            }
        }
        sol += dp[n][0];
    }
    
    cout << sol << '\n';
}