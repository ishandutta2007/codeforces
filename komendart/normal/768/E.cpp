#include <bits/stdc++.h>

using namespace std;

const int maxw = 16;

/*int dp[maxw][1 << maxw];

void solve(int n, int mask) {
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int d = n - i - 1;
        if (!(mask & (1 << d))) {
            v.push_back(dp[i][mask | (1 << d)]);
        }
    }
    sort(v.begin(), v.end());
    int mex = 0;
    for (auto i: v) {
        if (i > mex) break;
        mex = max(mex, i + 1);
    }
    dp[n][mask] = mex;
}*/

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    /*for (int i = 1; i < maxw; ++i) {
        for (int mask = 0; mask < (1 << maxw); ++mask) {
            solve(i, mask);
        }
    }
    for (int i = 0; i < maxw; ++i) {
        cout << i << ' ' << dp[i][0] << '\n';
    }*/

    vector<int> dp(61);
    int last = 0;
    for (int i = 0; last <= 60; ++i) {
        for (int j = last; j <= 60 && j <= last + i; ++j) {
            dp[j] = i;
        }
        last += i + 1;
    }

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ans ^= dp[x];
    }
    if (ans) cout << "NO\n";
    else cout << "YES\n";
}