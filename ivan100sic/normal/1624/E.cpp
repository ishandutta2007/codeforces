// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int inf = 1'123'123'123;

void mn(int& x, int y) {
    x = min(x, y);
}
struct string_info {
    int start, len, id;
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i : ra(0, n)) cin >> a[i];
        string b;
        cin >> b;

        map<string, string_info> mp;
        for (int i : ra(0, n)) {
            for (int j : ra(0, m)) {
                for (int l : {2, 3}) {
                    if (j+l <= m) {
                        mp[a[i].substr(j, l)] = {j+1, l, i+1};
                    }
                }
            }
        }

        vector dp(m+1, string_info{-1, -1});
        dp[0].len = -5;
        for (int i : ra(0, m)) {
            if (dp[i].len == -1) continue;
            for (int l : {2, 3}) {
                if (i+l > m) continue;
                auto it = mp.find(b.substr(i, l));
                if (it != mp.end()) {
                    dp[i+l] = it->second;
                }
            }
        }

        if (dp[m].len == -1) {
            cout << "-1\n";
        } else {
            vector<string_info> sol;
            int p = m;
            while (p != 0) {
                sol.push_back(dp[p]);
                p -= dp[p].len;
            }
            
            cout << sol.size() << '\n';
            for (auto [x, y, z] : R::reverse_view(sol)) {
                cout << x << ' ' << x+y-1 << ' ' << z << '\n';
            }
        }
    }
}