#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        a[x].push_back(i);
    }
    for (int j = 0; j < n; j++) {
        int ans = 0;
        vector<int> dp = {0, 0};
        for (auto x : a[j]) {
            int res = dp[x % 2];
            res = max(res, dp[1 - x % 2] + 1);
            dp[x % 2] = res;
        }
        cout << max(dp[0], dp[1]) << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}