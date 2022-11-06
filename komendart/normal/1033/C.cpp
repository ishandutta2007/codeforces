#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) ((x).size()))

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = i;
    }
    sort(order.begin(), order.end(), [&a] (int x, int y) {
        return a[x] > a[y];
    });
    vector<int> dp(n, true);
    for (auto id: order) {
        dp[id] = false;
        for (int i = id + a[id]; i < n; i += a[id]) {
            if (!dp[i]) {
                dp[id] = true;
            }
        }
        for (int i = id - a[id]; i >= 0; i -= a[id]) {
            if (!dp[i]) {
                dp[id] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i]) cout << "A";
        else cout << "B";
    }
}