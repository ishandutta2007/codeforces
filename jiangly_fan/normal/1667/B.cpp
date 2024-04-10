#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<LL> a(n + 1), s(n + 1);
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
        }
        auto t = s;
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        vector<int> bit(t.size(), n * 2), dp(n + 1, 2 * n);
        auto add = [&](int x, int y) {
            for (x += 1; x <= t.size(); x += x & -x)
                bit[x - 1] = min(bit[x - 1], y);
        };
        auto sum = [&](int x) {
            int y = n * 2;
            for (x += 1; x; x -= x & -x)
                y = min(y, bit[x - 1]);
            return y;
        };
        auto fi = [&](LL x) {
            return lower_bound(t.begin(), t.end(), x) - t.begin();
        };
        add(fi(0), 0);
        dp[0] = 0;
        for (int i = 1; i <= n; i += 1) {
            if (a[i] > 0) dp[i] = min(dp[i], dp[i - 1]);
            if (a[i] == 0) dp[i] = min(dp[i], dp[i - 1] + 1);
            if (a[i] < 0) dp[i] = min(dp[i], dp[i - 1] + 2);
            dp[i] = min(dp[i], sum(fi(s[i]) - 1));
            add(fi(s[i]), dp[i]);
        }
        cout << n - dp[n] << "\n";
    }
}