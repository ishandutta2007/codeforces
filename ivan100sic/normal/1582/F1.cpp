// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int dp[8192];

void mn(int& x, int y) {
    x = min(x, y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    memset(dp, 63, sizeof(dp));
    dp[0] = -1;

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        for (int i : ra(0, 512)) {
            if (dp[i] < x) {
                mn(dp[i^x], x);
            }
        }
    }

    vector<int> a;
    for (int i : ra(0, 512)) {
        if (dp[i] < 512) {
            a.push_back(i);
        }
    }

    cout << a.size() << '\n';
    for (int x : a) cout << x << ' ';
    cout << '\n';
}